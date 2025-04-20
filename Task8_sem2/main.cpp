#pragma once

#include <iostream>
#include <fstream>
#include "TextL.h"
#include "StrL.h"

void main()
{
    setlocale(LC_ALL, "RU");
    fstream fin;
    fstream fout;

    char lim, sym;

    fout.open("out.txt", ios::out);
    if (!fout.is_open())
        cout << "Ошибка открытия файла на запись!\n";
    else
    {
        fin.open("in.txt", ios::in);
        if (!fin.is_open())
            cout << "Ошибка открытия файла на чтение!";
        else
        {
            TxtL A;
            A.SetTxt(fin);
            A.SortStr();
            A.GetTxt(fout);
        }
    }
    fout.close();
    fin.close();
}