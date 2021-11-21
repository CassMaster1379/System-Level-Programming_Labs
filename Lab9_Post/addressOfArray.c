/* Name: Cassandra Lundberg  Date: 10/28/21
 * Title: addressOfArray.c
 * This program prints the address of the array variable numbers, then the address of each array element, then the size of the array */

#include <stdio.h>

int main(){
	int numbers[5] = {1,2,3,4,5};
	int i = 0;

	printf("numbers = %p\n", numbers);

	do{
		printf("numbers[%u] = %p\n", i, (void *)(&numbers[i]));
		i++;
	}while(i < 5);

	printf("sizeof(numbers) = %lu\n", sizeof(numbers));
	printf("length of array = %d\n", (sizeof(numbers)/sizeof(numbers[0])));
	return 0;
}
