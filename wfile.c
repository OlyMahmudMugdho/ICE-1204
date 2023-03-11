#include <stdio.h>
 int main(){
	 FILE *fptr;
	 char name[50];
	 int roll;
	 printf("Enter your name : \n");
	 fgets(name,50,stdin);
	 printf("Enter your roll : \n");
	 scanf("%d",&roll);
	 fptr = fopen("std.txt","w");
	 fprintf(fptr,"Name : %s\nRoll : %d",name, roll);
	 fclose(fptr);
	 return 0;
 }
