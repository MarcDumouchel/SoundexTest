#include <iostream>
#include <string>

using namespace std;

class Soundex
{
public:
    string Encode(const string& word) const{
        return word;
    }
};

#include "gmock/gmock.h"
using ::testing::Eq;
TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
    //Arrange
   Soundex soundex;
   //Act
    auto encode = soundex.Encode("A");
    //Assert
    ASSERT_THAT(encode, Eq("A"));
}

