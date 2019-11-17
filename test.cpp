#include <stdio.h>
#define Hoanvi(a,b) { auto t = a; a = b; b = t; }
void SapXepMang(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] > a[i])
				Hoanvi(a[i], a[j]);
		}
	}
}
int Exc169(int a[], int n, int b[], int &k, int c[], int &h)
{
	SapXepMang(a, n);
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
			b[k++] = a[i];
		else
			c[h++] = a[i];
	}
	int i = k-2;
	int max = b[k-1];
	while (i>=0 && max > c[h - 1])
	{
		max = b[i];
		i--;
	}
	return max;
}
int main()
{
	int n = 6;
	int b[] = { 0 };
	int k = 0;
	int c[] = { 0 };
	int h = 0;
	//printf("nhap n: ");
	//scanf_s("%d", &n);
	//InputArray(a, n);
	int a[] = { 3,2,5,6,1,8 };
	printf("%d",Exc169(a,n,b,k,c,h));
}
