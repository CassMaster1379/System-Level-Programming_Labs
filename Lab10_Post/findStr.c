//Name: Cassandra Lundberg  Date: 11/05/21
//Title: findStr.c 
//This program finds the smallest and largest order of words entered and stops
//accepting input when the word is a 4-letter word


#include <stdio.h>
#define LEN_WORD 20
#include <string.h>

main(){ //main method
	
	//initialized string(array of characters) called word
	char word[LEN_WORD+1];
	//initialize smallest_word string to store the smallest word
	char smallest_word[LEN_WORD+1];
	//initialize largest_word string to store the largest word
	char largest_word[LEN_WORD+1];
	
	//print prompt
	printf("Enter word: ");
	//store input in word
	scanf("%s", word);
	
	//use string length function to get length of string word
	int len = strlen(word);
	//copy the string in word to the string smallest_word to hold a value
	strcpy(smallest_word, word);
	//copy the string in word to the string largest_word to hold a value
	strcpy(largest_word, word);

	//while the length of the word entered does not equal 4
	while(len != 4){
		//print prompt
		printf("Enter word: ");
		//store input in string word
		scanf("%s", word);
		//get the length of the string
		len = strlen(word);
		
		//if the new word is less than the current smallest_word
		if(strcmp(word, smallest_word) < 0){
			//then copy the word to be the new smallest_word
			strcpy(smallest_word, word);
		}
		//if the new word is greater than the current largest word
		if(strcmp(word, largest_word) > 0){
			//then copy the word to be the new largest word
			strcpy(largest_word, word);
		}
	}
	//print smallest word prompt
	printf("Smallest word: ");
	//print the smallest_word
	puts(smallest_word);	
	//print largest word prompt
	printf("Largest word: ");
	//print the largest_wrd
	puts(largest_word);

//exit the main function
return 0;
}
