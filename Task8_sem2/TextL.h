#pragma once

#include <iostream>
#include <fstream>
#include "StrL.h"

const int M = 100;

class TxtL
{
public:
    StrL Str[M];
    int StrCount = 0;

    void SetTxt(fstream& fin);
    void GetTxt(fstream& fout);
    void SortStr();
};