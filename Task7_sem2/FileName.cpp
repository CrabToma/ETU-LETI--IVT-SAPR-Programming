// реализация через классы как на лекции

#include <iostream>
#include <fstream>

using namespace std;
const unsigned N = 100;

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

class StrL
{                                 
    char S[N];                   
    unsigned L; // длина
public:
    // можно с конструкторами.дистркторами и без них
    // Функцию ввода можно как конструктор сделать 

    void Inp3(char lim, fstream* f)
    {
        int i = 0, limcount = 0;
        bool insidelimits = false;
        char s;

        f->unsetf(ios::skipws);

        while (!f->eof())
        {
            *f >> s;
            if ((i > N - 1) || (s == '\n'))
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
                S[i++] = s;
            }
        }
        L = i;
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


    void Inp4(fstream* f)
    {
        int i = 0;
        char s;
        L = 0;

        f->unsetf(ios::skipws);

        while (!f->eof())
        {
            *f >> s;
            if (s >= '0' && s <= '9')
            {
                L = L * 10 + (s - '0');
            }
            else if (s == ' ' || s == '\n')
            {
                break;
            }
            else
            {
                L = 0;
                break;
            }
        }

        while (!f->eof())
        {
            *f >> s;
            if (s != ' ')
            {
                f->putback(s);
                break;
            }
        }

        if (L <= 0 || L > N)
        {
            L = 0;
            return;
        }

        while (!f->eof() && i < L)
        {
            *f >> s;
            if (s == '\n')
            {
                break;
            }
            S[i++] = s;
        }

        L = i;
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

    void Out2(fstream& fout)
    {
        int i = 0;
        while (i < L)
            fout << S[i++];
        fout << "\n";
    }

    void DeleteZeros()
    {
        int writeIndex = 0;
        bool inNumber = false;
        bool hasDot = false;
        int numStart = -1;

        for (int i = 0; i < L; i++)
        {
            if (isDigit(S[i]))
            {
                if (!inNumber)
                {
                    inNumber = true;
                    hasDot = false;
                    numStart = writeIndex;
                }
                if (S[i] == '0' && !hasDot)
                {
                    if (numStart == writeIndex && (i + 1 < L && isDigit(S[i + 1])))
                    {
                        continue;
                    }
                }
            }
            else if (S[i] == '.')
            {
                hasDot = true;
            }
            else
            {
                inNumber = false;
                hasDot = false;
            }
            S[writeIndex++] = S[i];
        }
        L = writeIndex; 
    }
};

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
            StrL array[N];
            int strcount = 0;

            fin.seekg(0);
            fin << skipws;
            fin >> lim;
            fin >> noskipws;

            fout << lim;

            fin.ignore();
            fout << '\n';

            while (!fin.eof())
            {
                //array[strcount].Inp3(lim, &fin);
                
                array[strcount].Inp4(&fin);
                array[strcount].DeleteZeros();
                array[strcount].Out2(fout);
                strcount++;
            }
        }
    }
    fout.close();
    fin.close();
}