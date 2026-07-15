#include<stdio.h>
int main(){
	int n;
	printf("enter the number : ");
	scanf("%d",&n);
	int a=1;
	int b=1;
	int sum=0;
	for (int i=3;i<=n;i++){
		if (b>=n) {
                         printf("sum of even numbers is : %d \n",sum);
                         return 0;
                }
		int next=a+b;
		a=b;
		b=next;
		if (b%2==0){
		sum=sum+b;
		}
		
	}
	printf("sum of even numbers is : %d \n",sum);
	return 0;
}
