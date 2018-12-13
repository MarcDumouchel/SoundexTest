//
// Created by CCEClass1 on 12/13/2018.
//

#include "Soundex.h"
    string Soundex::ZeroPad(const string& word)const
    {
        return word + "000";
    }
    string Soundex::Encode(const string& word) const{
        return ZeroPad(word);
    }
