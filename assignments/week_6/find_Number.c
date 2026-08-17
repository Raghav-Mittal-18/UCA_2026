#include<stdio.h>

int main() {
	int n;
	scanf("%d",&n);
	int arr[n];
	for (int i=0 ; i < n ; i++) {
		scanf("%d",&arr[i]);
	}
	int bit[32];
	for (int i = 0 ; i < 32 ; i++ ){
		bit[i] = 0;
	}
	for (int i=0 ; i < n ; i++) {
                int num = arr[i];
		int bit_idx = 0;
		while (num>0) {
			if (num%2 == 1) {
			bit[31-bit_idx]++;
			}
			num = num>>1;
			bit_idx++;
		}
        }
	int help = 1;
	int ans = 0;
	for (int i = 31 ; i >= 0 ; i--) {
		if (bit[i]%3 == 1){
			ans+=help;
		}
		help *= 2;
	}
	printf("answer is : %d\n",ans);
	return 0;
}
