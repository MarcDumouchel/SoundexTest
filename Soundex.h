//
// Created by CCEClass1 on 12/13/2018.
//

#ifndef FIRSTEXAMPLE_SOUNDEX_H
#define FIRSTEXAMPLE_SOUNDEX_H
#include <iostream>
#include <string>

using namespace std;


class Soundex {
    string ZeroPad(const string& word)const;
public:
    string Encode(const string& word) const;
};


#endif //FIRSTEXAMPLE_SOUNDEX_H
