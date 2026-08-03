#include<stdio.h>

int conditional(int x, int y, int z) {

 	return (!!x & y)|(!!x-1 & z);
}

int main(){
	int x, y, z;
	scanf("%d",&x);
	scanf("%d",&y);
	scanf("%d",&z);
	printf("%d\n",conditional(x, y, z));
	return 0;
}
