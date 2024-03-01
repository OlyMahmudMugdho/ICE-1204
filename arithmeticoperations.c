#include<stdio.h> 
#include<stdlib.h>

main() {

	int num1 = 0, num2 = 0, sum = 0;
	printf("Enter first number!:\n");
	scanf_s("%i", &num1);
	scanf_s("%i", &num2);
	sum = num1 + num2;
	printf("The addtion is %i", sum);

  system("pause");

}
