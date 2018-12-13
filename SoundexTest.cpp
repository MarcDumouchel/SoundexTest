#include <iostream>
#include <string>

using namespace std;

class Soundex
{
    string ZeroPad(const string& word)const
    {
        return word + "000";
    }
public:
    string Encode(const string& word) const{
        return ZeroPad(word);
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
    ASSERT_THAT(encode, Eq("A000"));
}

TEST(SoundexEncoding, PadsWithZerosToEnsureThreeDigitsFollowingFirstLetter)
{
    //Arrange
    Soundex soundex;
    //Act
    auto encode = soundex.Encode("I");
    //Assert
    ASSERT_THAT(encode, Eq("I000"));
}