#include<stdio.h>

int fitsBits(int x, int n) {
	return !((~x+1)>>n);
}

int main() {
	int x , n;
	scanf("%d",&x);
	scanf("%d",&n);
	printf("%d\n",fitsBits(x,n));
	return 0;
}
