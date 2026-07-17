#include <stdio.h>
#include <string.h>

void url_encode(char *str,int true_length){
	int l = true_length-1;
	int r = strlen(str)-1;
	while(l>=0){
		if (str[l]!=' '){
			str[r--]=str[l];
		}
		else{
			str[r--]='0';
			str[r--]='2';
			str[r--]='%';
		}
		l--;
	}
}

int main() {
	char str[] = "Hello World  ";
	int true_length = 11;
	url_encode(str,true_length);
	printf("%s\n",str);
	return 0;
}

