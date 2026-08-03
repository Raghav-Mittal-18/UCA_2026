#include<stdio.h>
int getByte(int x, int n) {
	return (x>>(n<<3)) & 0xff;
}

int main() {
	int n, x;
	scanf("%x",&x);
	scanf("%d",&n);
	printf("%x\n",getByte(x , n));
	return 0;
}
