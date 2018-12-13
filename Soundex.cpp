//
// Created by CCEClass1 on 12/13/2018.
//

#include "Soundex.h"
    string Soundex::ZeroPad(const string& word)const
    {
        auto zerosNeeded = 4 - word.length();
        return word + string(zerosNeeded, '0');
    }
    string Soundex::Encode(const string& word) const
    {
        return ZeroPad(head(word) + encodeDigits(word));
    }

    /**
     * Extract the first char of the string
     * @param word - input string
     * @return - first letter of string "head"
     */
string Soundex::head(const string &word) const
{
    return word.substr(0,1);
}

/**
 *Encode the stringinto digits using Soundex algorithm
 * @param word
 * @return
 */
string Soundex::encodeDigits(const string &word) const {
    if(word.length() > 1)
        return "1";
    return "";
}
