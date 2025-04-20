#include "StrL.h"

void StrM::Inp4(char s, fstream* f, StrM& m)
{
    m.Mark = s;
    int i = 0;

    f->unsetf(ios::skipws);

    while (!f->eof())
    {
        *f >> s;
        if ((i > N - 1) || (s == m.Mark) || (s == '\n'))
        {
            break;
        }
        m.Str[i++] = s;
    }
    m.Str[i] = m.Mark;
    if (s != '\n')
        while (!f->eof())
        {
            *f >> s;
            if ((s == '\n'))
            {
                break;
            }
        }

}