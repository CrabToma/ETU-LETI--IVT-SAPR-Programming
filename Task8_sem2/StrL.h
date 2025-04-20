#pragma once

#include <iostream>
#include <fstream>

using namespace std;
const unsigned N = 100;

class StrL
{
    char S[N];
    unsigned L = 0;
public:
    int longestword = 0;

    void Inp4(fstream* f);
    void Out2(fstream& fout);
    void FindMaxWordLen();
};