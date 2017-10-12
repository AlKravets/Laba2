#ifndef Class_h
#define Class_h

#include <iostream>
#include <string>
using namespace std;

class Test
{
private:
    long long *array;
    long size;
    int znak;   //1 = + || -1 = -
    bool Pav0(const long long *,long);
public:
    Test();
    ~Test();
    Test(string &);
    Test(Test &);
   void Set_from_string(string);
   void Set_from_consol();
    void Set_from_con();
    void Normalize();
    void Out_from_consol();
    Test & operator= (const Test &);
    Test & operator= (string s);
    void operator +(const Test &a);
    void operator -(const Test &a);
    void Chast_nomal(long);
    void operator *(const Test &);
    void Metod_Caracyba (const Test &);
};

#endif