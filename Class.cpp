#include <iostream>
#include <string>
#include "Class.h"
#include <cmath>

using namespace std;

static int base = 1073741824;
static int outbase = 1000000000;



Test::Test ()
: array(NULL), size(0), znak(1) {}


Test::Test(Test &b)
{
    size = b.size;
    array = new long long [size];
    for (long i =0; i< size; i++)
        array[i] = b.array[i];
    znak = b.znak;
}

Test::Test(string &s)
{
    Set_from_string(s);
}

Test::~Test()
{
    delete []array;
}



void Test::Set_from_string(string s)
{
	long long *arr;
	long size1;
    long n,i, j=0;
	int w;
	int posl=0;

	int b;	//пер для перевода в 2-ичн.
	int boolmas[30]={0}, ib=0, is=0;
	long long arrpos;	
    int arrpos1;
    if (s[0] == '-')
    {
        znak = -1;
        s.erase(0,1);
    }
    else
        znak = 1;
    
    n = s.length();
    size1 = (n/10)+1;
	arr = new long long[size1];
	for (int k = 0; k < size1; k++)
		arr[k] = 0;
	i = 0;
	while (i < n)
	{
		if ( i+9 < n)
		{
			for (int k = 9; k >= 0; k--)
			{
				w = (int)s[i+k] - 48;
				arr[j] = arr[j]+w*pow(10, 9-k);
			}
			j++;
			i = i + 10;
		}
		else
		{
			for (int k = i; k <n ; k++)
			{
				w = (int)s[k] - 48;
				arr[j] =arr[j]+ w*pow(10,  9+i-k);
			}
			j++;
			posl = n-i;
			i = n;
		}
	}           // в arr число записано в 0 эл - первые 10 цифр числа ... в posl храним число цифр последнего эл arr


    size = size1+1;
    array = new long long[size];
    for(long l=0; l< size ; l++)
	array[l]=0;
	int ase=0;
    while (!Pav0(arr, size1))							// начало кода перевода из 10 в 2
    {                                               // делим число на 2 по ка не получим 30 0 или 1
	    for (long l=0; l< size1-1; l++)        //  которые храним в boolmas потом записываем их в 1 ячейку array
	    {
		    b = arr[l] % 2;
		    arr[l]= arr[l]/2;
		    arr[l+1]= arr[l+1] + b*10000000000;
	    }	
	    if (posl!=0)
	    {
    		arrpos = arr[size1-1]/pow(10, 10 - posl);
		    boolmas[ib] = arrpos %2;
		    arrpos = arrpos / 2;
		    arr[size1-1] = arrpos *pow(10, 10 - posl);
	    }
    	else 
    		{
			    boolmas[ib]=b;
			    arr[size1-1] = 0;
			    ase++;
		    }

	    ib++; 
	    if (ib == 30)
	    {
    		for (int l=0; l < 30; l++)
		    {
			    array[is] = array[is]+ boolmas[l] * pow(2,l);

		    }
		    is++;
		
		    ib = 0; 
	    }
    }
    if (ib !=0)
    {
	    for (int l=0; l < ib; l++)
	    {
		    array[is] =array[is]+ boolmas[l] * pow(2,l);
	    }
    }	
	delete []arr;
}


void Test::Set_from_consol()
{
	string s;
	getline(cin,s);
	Set_from_string(s);
}

int colpos(long long a)
{
	int j=0;
	while (a > 0)
	{
		a = a/10;
		j++;
	}
	return j;
}

void funct_output( long long * a, long b)
{
	bool flag =0, flag1=0;
	int col0;
	long long arr;
	for (long i= b-1; i >=0; i-- )
	{
		//cout << " "<< i << "@ ";
		if (a[i] !=0)	
			flag = true;
		if (flag) 
			{
				if (!flag1)
					{
						cout << a[i];
						flag1=1;
					}
				else
				{
					col0 =9  - colpos(a[i]);
					//cout << "@";
					for (int j = 0;j < col0; j++ )
						cout << "0";
					if (a[i]!=0)
						cout << a[i];
				}
			}	

	}
	cout << endl;
}




bool Test::Pav0(const long long * a, long  b)
{
	int j=0;
	for (int i=0; i< b ; i++)
		if (a[i] !=0) j++;
	if (j!=0) return false;
	else return true;
}


/*void Test::Normalize()
{
	long long *arr;
	long j=size-1;
	while ((j>0)&&(array[j]==0))
		j--;
	for (int i = 0; i < j-1; i++)
	{
		if (array[i] > base)
		{
			array[i + 1] = array[i + 1] + array[i] / base;
			array[i] = array[i] % base;
		}
		if (array[i] < 0)
		{
			array[i + 1] = array[i + 1] + array[i] / base - 1;
			array[i] = base - array[i] % base;

		}
	}
	if (array[j]< 0 )
		{
			znak = znak *(-1);
			array[j]*= -1; 
		}
	if (array[j] >= base)
		{
			arr = new long long [j+1];
			for (int i=0; i < j+1; j++)
				arr[i] = 0;
			for (long i =0; i < j; i++)
				arr[i]  = array[i];
			delete []array;
			array = arr;
			Normalize();
		}
	
}
*/
void Test::Normalize()
{
	long long *arr;
	long j=size-1;
	while ((j>0)&&(array[j]==0))
		j--;
	Chast_nomal(j);
}

void Test::Chast_nomal(long j)
{
	long long * arr;
	if (array[j] < 0)
		{
			for (long i=0; i < j+1; i++)
				array[i] *= -1;
			znak = -1;
		}
	else znak=1;
	for (long i = 0; i < j; i++)
	{
		if (array[i] > base)
		{
			array[i + 1] = array[i + 1] + array[i] / base;
			array[i] = array[i] % base;
		}
		if (array[i] < 0)
		{
			array[i + 1] = array[i + 1] + array[i] / base - 1;
			array[i] = base + array[i] % base;	
		}
	}
	if (array[j] >= base)
		{
			arr = new long long [j+2];
			size = j+2;
			for (long i=0; i < size; i++)
				arr[i] = 0;
			for (long i =0; i < j+1; i++)
				arr[i]  = array[i];
			arr [j+1] = arr[j+1] + arr[j]/base;
			arr[j] = arr[j]%base;
			delete []array;
			array = arr;
		}
	
}


void Test::Out_from_consol()
{
	long long * arr;
	long long * arr1;
	long long ost;
	long size1, j=0;
	size1 = size+1;
	arr1 = new long long[size];
	for (long long i =0; i< size; i++)
	arr1[i] = array[i];
	arr = new long long[size1];
	for (long long i =0; i< size1; i++)
		arr[i] = 0;
	while (!Pav0(arr1, size))
	{
		for (long long i=size-1 ; i >0 ; i--)
		{
			ost = arr1[i] % outbase;
			arr1[i] = arr1[i]/outbase;
			arr1[i-1] = arr1[i-1] + ost*base;
		}
		ost = arr1[0] % outbase;
		arr1[0] = arr1[0]/outbase;
		arr[j] = ost;
		j++;
	}
	if (Pav0(array, size))
		cout << 0<< endl;
	else
	{
		if (znak <0 )
			cout << "-";
		funct_output(arr, size1);
	}

	delete []arr;
	delete []arr1;
}


Test & Test::operator= (const Test & a)
{
	if (this == &a)
		return *this;
	delete []array;
	size = a.size;
	znak = a.znak;
	array = new long long [size];
	for (long i=0; i < size; i++)
		array[i] = a.array[i];
	return *this;
}

Test & Test::operator= (string s)
{
	Set_from_string(s);
}

void Test::operator +(const Test &b)
{
	long long * c;
	long s, k=0, p, znak1;
	if (size >= b.size)
	{
		s= size+1;
		p = b.size;
		c = new long long[s];
		for (long i =0; i< size; i++)
			{
				c[i] = znak*array[i];
			}
		c[size]=0;
	}
	else 
	{
		s= b.size+1;
		p = size;
		c = new long long[s];
		for (long i =0; i< b.size; i++)
			{
				c[i] = b.znak*b.array[i];
			}
		c[b.size] = 0;
	}
	for (long i=0; i<p; i++ )
	{
		c[i] = (znak*array[i] +b.znak*b.array[i] +k)%base;
		k =  (znak*array[i] +b.znak*b.array[i] +k)/base;
	}
	c[p] = c[p] +k;
	delete []array;
	array = c;
	size = s;
	//znak = znak * b.znak;
	znak = 1;
	c = NULL;
	
	Normalize();
}

void Test::operator -(const Test &b)
{
	long long * c;
	long s, k=0, p, znak1;
	if (size >= b.size)
	{
		s= size+1;
		p = b.size;
		c = new long long[s];
		for (long i =0; i< size; i++)
			{
				c[i] = znak*array[i];
			}
		c[size]=0;
	}
	else 
	{
		s= b.size+1;
		p = size;
		c = new long long[s];
		for (long i =0; i< b.size; i++)
			{
				c[i] =(-1)*b.znak*b.array[i];
			}
		c[b.size] = 0;
	}
	for (long i=0; i<p; i++ )
	{
		c[i] = (znak*array[i] +(-1)*b.znak*b.array[i] +k)%base;
		k =  (znak*array[i] +(-1)*b.znak*b.array[i] +k)/base;
	}
	c[p] = c[p] +k;
	delete []array;
	array = c;
	size = s;
	//znak = znak * b.znak;
	znak = 1;
	c = NULL;
	Normalize();

}


void Test::operator *(const Test &b)
{
	long long *c, k, k1;
	long size_c, znak_c;
	size_c = size+b.size;
	c = new long long [size_c];
	for (long i=0; i < size_c; i++)
	{
		c[i] =0;
	}
	for (long i=0; i < size; i++)
	{
		k=0;
		for (long j=0; j < b.size; j++)
		{
			k1 = (c[i+j] +array[i]* b.array[j] +k)/base;
			c[j+i] = (c[i+j]+array[i]* b.array[j] +k)%base;
			k = k1;
		}
		c[i+b.size]+= k;  
	} 
	size = size_c;
	array = c;
	c= NULL;
	znak_c=znak*b.znak;
	znak=1;
	Normalize();
	znak = znak_c;
}


void Test::Metod_Caracyba (const Test & b)
{
	long long *c, k=0, k1;
	long r, size_c, znak_c;
	Test u,v, u0, u1, v0, v1, u10, v01;
	if (size > b.size)
		{
			r = size/2;
			v.size = u.size = size;
		}
	else
		{
			r= b.size/2;
			v.size = u.size = b.size;
		}
	
	u.array =new long long [u.size];
	for (long i=0; i < u.size; i++)
		u.array[i] = 0;
	for (long i=0; i < size; i++)
		u.array[i] = array[i];
	v.array =new long long [v.size];
	for (long i=0; i < v.size; i++)
		v.array[i] = 0;
	for (long i=0; i < b.size; i++)
		v.array[i] = b.array[i];

	u0.size = v0.size= r;
	u0.array =new long long [u0.size];
	for (long i=0; i < r; i++)
		u0.array[i] = u.array[i];
	v0.array =new long long [v0.size];
	for (long i=0; i < r; i++)
		v0.array[i] = v.array[i];
	

	u1.size = v1.size= u.size- r;
	u1.array =new long long [u1.size];
	for (long i=r; i < u.size; i++)
		u1.array[i-r] = u.array[i];
	v1.array =new long long [v1.size];
	for (long i=r; i < v.size; i++)
		v1.array[i-r] = v.array[i];
	
	u10=u1;
	v01=v0;
	//u.Out_from_consol();
	//v01.Out_from_consol();
	//u0.Out_from_consol();

	u10-u0;
	//u10.Out_from_consol();
	v01-v1;
	u10*v01;
//	v01.Out_from_consol();
	u1*v1;
	u0*v0;
	
	u10+u0;
	u10+u1;
//	u10.Out_from_consol();
//	u0.Out_from_consol();
//	u1.Out_from_consol();
	size_c = u.size*2;
	c = new long long [size_c];
	for (long i=0; i < size_c; i++)
		c[i] =0;
	for (long i=0; i < u0.size; i++)
		{
			k1 =  (c[i] + u0.znak*u0.array[i] +k)/base;
			c[i] =  (c[i] + u0.znak*u0.array[i] +k)%base;
			k = k1;
		}
	c[u0.size] = c[u0.size] +k;

	k=0;

/*	for (long i=r; i < (u0.size+r); i++)
	{
		k1 =  (c[i] + u0.array[i-r] +k)/base;
		c[i] =  (c[i] + u0.array[i-r] +k)%base;
		k = k1;
	}
	c[u0.size+r] = c[u0.size+r] +k;
	*/
	k=0;
	
		for (long i=r; i < (u10.size+r); i++)
		{
			k1 =  (c[i] + u10.znak*u10.array[i-r] +k)/base;
			c[i] =  (c[i] + u10.znak*u10.array[i-r] +k)%base;
			k = k1;
		}
		c[u10.size+r] = c[u10.size+r] +k;
	
	k=0;
		
/*		for (long i=r; i < (u1.size+r); i++)
		{
			k1 =  (c[i] + u1.array[i-r] +k)/base;
			c[i] =  (c[i] + u1.array[i-r] +k)%base;
			k = k1;
		}
		c[u1.size+r] = c[u1.size+r] +k;
*/
	k=0;
	
		for (long i=2*r; i < (u1.size+2*r); i++)
		{
			k1 =  (c[i] + u1.znak*u1.array[i-2*r] +k)/base;
			c[i] =  (c[i] + u1.znak*u1.array[i-2*r] +k)%base;
			k = k1;
		}
		c[u1.size+2*r] = c[u1.size+2*r] +k;

	
	for (long i=0; i < size_c; i++)
		cout << c[i] << " # ";
	cout << endl;
	
	znak = znak*b.znak;
	size = size_c;
	array = c;
	c = NULL;
	Normalize();
	
}