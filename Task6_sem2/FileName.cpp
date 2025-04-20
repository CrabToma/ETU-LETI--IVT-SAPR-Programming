/*
  Задание: 21 д) Преобразовать строку, заменяя каждое вхождение
  заданного слова другим заданным словом. удалить из каждой группы
  подряд идущих цифр, которой не предшествует точка, все
  начальные нули (кроме последнего, если за ним идет точка)

  Автор: Фанасюткин Роман Владимирович  Группа: 4354  Версия программы: 6.1.25
  Дата начала: 09.02.25  Завершения: 09.02.25
*/

#include <iostream>
#include <fstream>
#include <locale>

using namespace std;

const int N = 100;

struct StrM
{
    char Str[N + 1];

    char Mark;

    void Out(fstream& fout)
    {
        int i = 0;
        while (Str[i] != Mark)
            fout << Str[i++];
        fout << "\n";
    }
};

void ReadMark1(char s, fstream* f, StrM& m)
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

void ReadMark2(char s, char lim, fstream* f, StrM& m)
{
    m.Mark = s;
    int i = 0, limcount = 0;
    bool insidelimits = false;

    f->unsetf(ios::skipws);

    while (!f->eof())
    {
        *f >> s;
        if ((i > N - 1) || (s == m.Mark) || (s == '\n'))
        {
            break;
        }
        if (s == lim)
        {
            insidelimits = !insidelimits;
            limcount++;
        }
        if (insidelimits && s != lim && (limcount <= 2))
        {
            m.Str[i++] = s;
        }
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

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

void DeleteZeros(StrM& m)
{
    int writeIndex = 0;  
    bool inNumber = false; 
    bool hasDot = false; 
    int numStart = -1;

    for (int i = 0; i < N && m.Str[i] != m.Mark; i++)
    {
        if (isDigit(m.Str[i]))
        {
            if (!inNumber)
            {      
                inNumber = true;
                hasDot = (i > 0 && m.Str[i - 1] == '.');
                numStart = writeIndex; 
            }
            if (m.Str[i] == '0' && !hasDot)
            {
                if (numStart == writeIndex && (i + 1 < N && isDigit(m.Str[i + 1])))
                {
                    continue;
                }
            }
        }
        else
        {
            inNumber = false;
        }
        m.Str[writeIndex++] = m.Str[i];
    }

    m.Str[writeIndex] = '\0';
    m.Mark = '\0';
}

void main()
{
    setlocale(LC_ALL, "RU");
    fstream fin;
    fstream fout;

    char mark, lim, sym;

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
            StrM array[N];
            int strcount = 0;

            fin.seekg(0);
            fin << skipws;
            fin >> mark;
            fin >> lim;
            fin >> noskipws;

            fout << mark;
            fout << lim;
            array->Mark = mark;

            fin.ignore();
            fout << '\n';


            while (!fin.eof())
            {
                ReadMark1(mark, &fin, array[strcount]);
                //ReadMark2(mark, lim, &fin, array[strcount]);
                DeleteZeros(array[strcount]);
                array[strcount].Out(fout);
                strcount++;
            }
        }
    }
    fout.close();
    fin.close();
}