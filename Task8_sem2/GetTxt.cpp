#include "TextL.h"

void TxtL::GetTxt(fstream& fout)
{
    for (int k = 0; k < StrCount; k++)
    {
        Str[k].Out2(fout);
    }
}