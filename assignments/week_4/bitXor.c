#include<stdio.h>
int bitXor(int a,int b) {
	return ~(~(~a&b)&~(a&~b));
}

int main() {
	int a,b;
	scanf("%d",&a);
	scanf("%d",&b);
	printf("%d\n",bitXor(a,b));
	return 0;
}

