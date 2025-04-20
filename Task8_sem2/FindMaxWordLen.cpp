#include "StrL.h"

void StrL::FindMaxWordLen()
{
    int len[N] = { 0 };
    int i = 0, wordscount = 0, cur_len = 0;

    while (i < L)
    {
        if (S[i] == ' ')
        {
            if (cur_len > 0)
            {
                len[wordscount++] = cur_len;
                cur_len = 0;
            }
        }
        else
        {
            cur_len++;
        }
        i++;
    }
    if (cur_len > 0)
    {
        len[wordscount++] = cur_len;
    }

    int max = len[0];
    for (int j = 1; j < wordscount; j++)
    {
        if (len[j] > max) max = len[j];
    }
    longestword = max;
}