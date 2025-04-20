#include "TextL.h"

void Swap(StrL& a, StrL& b)
{
    StrL temp = a;
    a = b;
    b = temp;
}

void TxtL::SortStr()
{
    for (int i = 0; i < StrCount - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < StrCount; j++)
        {
            if (Str[j].longestword < Str[min_index].longestword)
                min_index = j;
        }

        if (min_index != i)
            Swap(Str[min_index], Str[i]);
    }
}