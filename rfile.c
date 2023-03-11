#include <stdio.h>

int main(){
	FILE *fptr;
	char c;
	fptr = fopen("std.txt","r");
	while((c = getc(fptr)) != EOF ){
		printf("%c",c);
	}
	fclose(fptr);
	return 0;
}
