void Test::Metod_Caracyba (const Test & b)
{
	long long *c, k=0, k1;
	long r, size_c, znak_c;
	Test u,v u0, u1, v0, v1, u10, v01;
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

	u01=u1;
	v01=v0;

	u1*v1;
	u0*v0;
	u10-u0;
	v01-v1;
	u10*v01;

	size_c = u.size*2;
	c = new long long [size_c];
	for (long i=0; i < size_c; i++)
		c[i] =0;
	for (long i=0; i < u0.size; i++)
		{
			k1 =  (c[i] + u0.array[i] +k)/base;
			c[i] =  (c[i] + u0.array[i] +k)%base;
			k = k1;
		}
	c[u0.size] = c[i] +k;

	k=0;

	for (long i=r; i < (u0.size+r); i++)
	{
		k1 =  (c[i] + u0.array[i-r] +k)/base;
		c[i] =  (c[i] + u0.array[i-r] +k)%base;
		k = k1;
	}
	c[u0.size+r] = c[i] +k;

	k=0;
	
		for (long i=r; i < (u10.size+r); i++)
		{
			k1 =  (c[i] + u10.array[i-r] +k)/base;
			c[i] =  (c[i] + u10.array[i-r] +k)%base;
			k = k1;
		}
		c[u10.size+r] = c[i] +k;
	
	k=0;
		
		for (long i=r; i < (u1.size+r); i++)
		{
			k1 =  (c[i] + u1.array[i-r] +k)/base;
			c[i] =  (c[i] + u1.array[i-r] +k)%base;
			k = k1;
		}
		c[u1.size+r] = c[i] +k;

	k=0;
	
		for (long i=2*r; i < (u0.size+2*r); i++)
		{
			k1 =  (c[i] + u0.array[i-2*r] +k)/base;
			c[i] =  (c[i] + u0.array[i-2*r] +k)%base;
			k = k1;
		}
		c[u0.size+2*r] = c[i] +k;

	znak = znak*b.znak;
	size = size_c;
	a = c;
	c = NUlL;
	Normalize();
	
}