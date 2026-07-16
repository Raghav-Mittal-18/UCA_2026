#include<stdio.h>

int my_strlen(const char *str){
	int l=0;
	while(str[l]!='\0'){
		l=l+1;
	}
	return l;
}

int main(){
	char str[]="raghav mittal";
	int len=my_strlen(str);
	printf("length of string is : %d\n",len);
	return 0;
}
