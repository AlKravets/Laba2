#include <iostream>
#include "Class.h"
#include <string>
using namespace std;

int main()
{
    string s = "-1234567890";
    cout << s << endl;
	Test b(s);
	Test b1(s);
	Test t;
	t.Set_from_consol();
	cout << "----------" << endl;
	t.Out_from_consol();
	
	b*t;
	b.Out_from_consol();
	cout << "---------------" << endl;
	b1.Metod_Caracyba(t);
	b.Out_from_consol();
	return 0;
}