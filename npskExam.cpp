#include <iostream>
using namespace std;
int max(int a, int b)
{ int r=0;
if (a > b) r=a;
else r=b; return (r); 
}
int xyz(int a, int b[], int c[], int n)
{
	if (n == 0 || a == 0)
		return 0;
	if (b[n - 1] > a)
		return xyz(a, b, c, n - 1);
	else
		return max(
			c[n - 1]
				+ xyz(a - b[n - 1],
						b, c, n - 1),
			xyz(a, b, c, n - 1));
}
int main()
{
    int a = 50, n = 3; 
	int c[] = {60, 100, 120}, b[] = {10, 20, 30}; 
	cout << xyz(a, b, c, n);
	return 0;
}
