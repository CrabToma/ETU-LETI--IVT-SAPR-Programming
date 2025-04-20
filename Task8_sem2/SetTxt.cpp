#include "TextL.h"

void TxtL::SetTxt(fstream& fin)
{
    while (!fin.eof())
    {
        Str[StrCount].Inp4(&fin);
        Str[StrCount].FindMaxWordLen();
        StrCount++;
    }
}