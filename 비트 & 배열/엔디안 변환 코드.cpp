#include <iostream>
using namespace std;

void ce(int * n ) // change endian
{
	char *p = (char *) n;
	char t;
	t = p[0], p[0] = p[3], p[3] =t;
	t = p[1], p[1] = p[2], p[2] =t;
}

void ce1(int *n)
{
	*n = (*n <<24 | ((*n <<8) & 0xff0000) | ((*n >> 8) & 0xff00) | (*n>>24)); 
}

int main(void) {
	int x =0x01020304;
	char *p = (char *) &x;
	
	printf("x = %d%d%d%d\n", p[0], p[1], p[2], p[3]);
	ce(&x);
	printf("x = %d%d%d%d\n", p[0], p[1], p[2], p[3]);
	return 0;
}
