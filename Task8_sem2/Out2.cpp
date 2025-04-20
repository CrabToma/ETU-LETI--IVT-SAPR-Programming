#include "StrL.h"

void StrM::Out2(fstream& fout)
{
    int i = 0;
    while (Str[i] != Mark)
        fout << Str[i++];
    fout << "\n";
}
