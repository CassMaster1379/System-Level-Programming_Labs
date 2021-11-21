//Name: Cassandra Lundberg  Date: 11/12/21 
//Title: swapalphanumeric.c
//This program takes inputs from two different strings of the same length
//containing alphanumeric characters and swaps the numbers of one string
//with the letters fro the other without the use of a temp variable


#include <stdio.h> //library function to incorporate standard inputs
#include <string.h> //library function to incorporate the string function
#define STRING_LEN 100 //constant variable to represent max elements of the strings
void swap(char *p, char *s){ //swap function with inputs of two pointers
	//pointer variable p points to the concatenation of the pointer holding the address of the first
	//string and the pointer holding the address of the second string
	*p = *p + *s; 
	//the pointer variable s points to the address of the first string after the pointer with the address
	//of the second string is subtracted from the concatenation of the pointers from above
	*s = *p - *s;
	//the pointer variable p points to the address of the second string after the pointer with the
	//address of the first string(now pointer s) is subtracted from the concatenation of the pointer
	//from the previous p pointer variable
	*p = *p - *s;
//In doing this the addresses in which the pointers held are now switched
}
int main(void){ //the main function
	//string1 is created with room for 100 elements
	char string1[STRING_LEN+1];
	//string2 is created with room for 100 elements
	char string2[STRING_LEN+1];

	//print prompt for the first sentence
	printf("Enter the first sentence.\n");
	//scan input for string1
	scanf("%s", string1);
	//print prompt for the second sentence
	printf("Enter the second sentence.\n");
	//scan input for string2
	scanf("%s", string2);
	
	//len1 and len2 are created from the library function of string.h to ensure the strings' length
	//match
	int len1 = strlen(string1);
	int len2 = strlen(string2);

	//variable i is created for indexing
	int i = 0;
	//while either string has not reached a null character(when either string has not reached the end)
	while(string1[i] != '\0' && string2[i] != '\0'){
		//call the swap function with the string's addresses as input for each index
		swap(&string1[i], &string2[i]);
		//then increment the index
		i++;
	}
	//if the lengths match
	if(len1 == len2){
		//then print the prompt for the new first string
		printf("The first sentence is now: ");
		//output the value of string1
		puts(string1);
		//print new line
		printf("\n");
		//print the prompt for the new second string
		printf("The second sentence is now: ");
		//output the value of string2
		puts(string2);
		//print new line
		printf("\n");
	}
	else{//otherwise one of the sentences is larger than the array allows
		//tell user the sentence is too large
		printf("One of the strings is longer than the other.\n");
	}
//exit the main function
return 0;
}
