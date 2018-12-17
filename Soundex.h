//
// Created by CCEClass1 on 12/13/2018.
//

#ifndef FIRSTEXAMPLE_SOUNDEX_H
#define FIRSTEXAMPLE_SOUNDEX_H
#include <iostream>
#include <string>

using namespace std;
static const size_t MaxCodeLength{4};
static const string NotADigit {"*"};

class Soundex {
    string ZeroPad(const string& word)const;
    string head(const string& word) const;
    string tail(const string& word) const;
    string encodeDigits(const string& word)const;
    bool isComplete(const string& encoding)const;
    string lastDigit(const string& encoding)const;
    string upperFront(const string& word)const;
    char lower(char c)const;
public:
    string Encode(const string& word) const;
    string encodeDigit(char letter)const;
};


#endif //FIRSTEXAMPLE_SOUNDEX_H
