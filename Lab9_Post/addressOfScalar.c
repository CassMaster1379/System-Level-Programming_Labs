/*Name: Cassandra Lundberg  Date: 10/29/21
 * Title: addressOfScalar.c
 * This program provides examples of using the '&' operator */

#include <stdio.h>

int main(){
	char charvar = '\0';
	printf("address of charvar = %p\n", (void *)(&charvar));
	printf("address of charvar - 1 = %p\n", (void *)(&charvar - 1));
	printf("address of charvar + 1 = %p\n", (void *)(&charvar + 1));

	int intvar = 1;
	printf("address of intvar = %p\n", (void *)(&intvar));
	printf("address of intvar - 1 = %p\n", (void *)(&intvar - 1));
	printf("address of intvar + 1 = %p\n", (void *)(&intvar + 1));
 
	return 0;
}
