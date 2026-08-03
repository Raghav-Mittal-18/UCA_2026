#include<stdio.h>
int bitAnd(int x , int y) {
	return ~(~x | ~y);
}

int main(){
	int a , b;
	scanf("%d",&a);
	scanf("%d",&b);
	printf("%d\n",bitAnd(a,b));
	return 0;
}
