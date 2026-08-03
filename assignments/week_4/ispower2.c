#include<stdio.h>

int ispower2(int x) {
	return !(x&(x-1));
}

int main() {
	int n;
	scanf("%d",&n);
	printf("%d\n",ispower2(n));
	return 0;
}
