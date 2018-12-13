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

TEST_F(SoundexEncoding, ReplaceConsonantsWithAppropriateDigits)
{
    //Arrange
    //Act
    //Assert
    EXPECT_THAT(soundex.Encode("Ab"), Eq("A100"));
    EXPECT_THAT(soundex.Encode("Ac"), Eq("A200"));
    EXPECT_THAT(soundex.Encode("Ad"), Eq("A300"));
    EXPECT_THAT(soundex.Encode("Al"), Eq("A400"));
    EXPECT_THAT(soundex.Encode("Am"), Eq("A500"));
    EXPECT_THAT(soundex.Encode("Ar"), Eq("A600"));
}