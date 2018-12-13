#include "gmock/gmock.h"
#include "Soundex.h"

using ::testing::Eq;

class SoundexEncoding: public testing::Test{
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
    //Arrange
   //Act
    //Assert
    ASSERT_THAT(soundex.Encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigitsFollowingFirstLetter)
{
    //Arrange
    //Act
    //Assert
    ASSERT_THAT(soundex.Encode("I"), Eq("I000"));
}