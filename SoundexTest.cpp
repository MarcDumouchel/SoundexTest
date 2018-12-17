#include "gmock/gmock.h"
#include "Soundex.h"

using namespace testing;

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

TEST_F(SoundexEncoding, IgnoreNonAlphabetics)
{
    //Arrange
    //Act
    //Assert
    ASSERT_THAT(soundex.Encode("A#"), Eq("A000"));
}

TEST_F(SoundexEncoding, ReplaceMultipleConsonantsWithDigits)
{
    //Arrange
    //Act
    //Assert
    ASSERT_THAT(soundex.Encode("Acdl"), Eq("A234"));
}

TEST_F(SoundexEncoding, LimitLengthToFourCharacters)
{
    //Arrange
    //Act
    //Assert
    ASSERT_THAT(soundex.Encode("Dcdlb").length(), Eq(4u));
}

TEST_F(SoundexEncoding, CombineDuplicateEncodings)
{
    //Arrange
    //Act
    //Assert
    ASSERT_THAT(soundex.encodeDigit('b'), Eq(soundex.encodeDigit('f')));
    ASSERT_THAT(soundex.encodeDigit('x'), Eq(soundex.encodeDigit('g')));
    ASSERT_THAT(soundex.encodeDigit('d'), Eq(soundex.encodeDigit('t')));
    ASSERT_THAT(soundex.Encode("Abfxgdt"), Eq("A123"));
}

TEST_F(SoundexEncoding, UpperCaseFirstLetter)
{
    //Arrange
    //Act
    //Assert
    ASSERT_THAT(soundex.Encode("abcd"), StartsWith("A"));
}

TEST_F(SoundexEncoding, IgnoreVowelsLikeLetters)
{
    //Arrange
    //Act
    //Assert
    ASSERT_THAT(soundex.Encode("BaAeEiIoOuUhHyYcdl"), Eq("B234"));
}