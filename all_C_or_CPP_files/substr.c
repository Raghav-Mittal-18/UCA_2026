#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int find_substring(const char *haystack,const char *needle){
	int n=strlen(haystack);
	int m=strlen(needle);
	for (int i=0;i<n-m;i++){
		char *check="";
		bool flag = true;
		int a=0;
		for (int j=i;j<i+m;j++){
			if (needle[a++]!=haystack[j]){
				flag=false;
			}
		}
		if (flag){
			return i;
		}
	}
	return -1;
}
int main(){
	char haystack[] = "Embedded Systems";
	char needle[] = "bed";
	printf("%d\n",find_substring(haystack,needle));
}
