#include<stdio.h>
int sign(int n) {
	return (n>>31) | !!n;
}

int main() {
	int n;
	scanf("%d",&n);
	printf("%d\n",sign(n));
	return 0;
}

