#include<stdio.h>
#include<string.h>
void reverse_string(char *str){
	int left=0; 
	int right=strlen(str)-1;
	while(left<right){
		char temp=str[left];
		str[left]=str[right];
		str[right]=temp;
		left++;
		right--;
	}
}
int main (){
	char str[]="Data Structures";
	reverse_string(str);
	printf("%s\n",str);
	return 0;
}
