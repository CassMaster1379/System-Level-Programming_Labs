//Name: Cassandra Lundberg  Date: 11/11/21
//Title: palindrome.c
//This program takes a string of numbers or characters or both and checks to see
//if it is a palindrome


#include <stdio.h>
#include <string.h> //included string library function
#define MESS_LEN 100 //created constant variable of 100

void palindrome(char message[], int length){ //palindrome method
	//create variables i for indexing
	int i; 
	//create temp string to store the reversed string
	char temp[length+1];
	//create variable j to index the ending element of the string
	int j = length-1;
	//for every element in the string
	for(i = 0; i < length; i++){
		//starting from last element copy all characters from the message
		//string to the temp string
		temp[i] = message[j];
		//decremrent j to move towards the begginging of the string
		j--;
	}
	//compare the two strings useing the strcmp function and if they are equal
	if(strcmp(temp, message) == 0){
		//then the string is a palindrome
		printf("This is a palindrome.\n");
	}
	//otherwise if they are not equal
	else{
		//then the string is not a palindrome
		printf("This is not a palindrome.\n");
	}
	
}

main(){ //main function
	//create string to store up to 100 elements
	char message[MESS_LEN+1];
		
	//print prompt to enter message
	printf("Enter a message: ");
	//scan input string
	scanf("%s", message);

	//create variable to store the length of the stirng
	int length = strlen(message);
	
	//if the length of the string is less than 100
	if(length <= MESS_LEN){
		//then call the method
		palindrome(message, length);
	}
	//otherwise the message is too long and the array cannot hold the entire string
	else{
		//print the message is too long
		printf("That message is too long.");
	}
	//exit the main method
	return 0;
}
