/*Name: Cassandra Lundberg  Date: 10/29/21
 * Title: getMostFreqChar.c
 * This program takes an input and prints out the most frequent letter, ignoring
 * the case*/

#include <stdio.h>

//the main method has argc and argv arguments passed to input the test file
void main(int argc, char *argv[]){
	//variable of type FILE called file_input
	FILE *file_input;
	//file_input opens the file with parameter of text file from the main method argument
	file_input = fopen(argv[1], "r");
	//new array created with 26 elements of the letters of the alphabet
	char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
	//variable character of char tyoe created
	char character;
	
	//new array count with 30 elements
	int count[30];
	//variable i created
	int i;
	//assigns 0 to each elements in array count
	for (i = 0; i < 30; i++){
		count[i] = 0;
	}

	//variable character gets a character from input_file
	//while it is not equal to the end of file
	while ((character = getc(file_input)) != EOF){
		//for every character in the alphabet not equal to a NULL character
		for (i = 0; alphabet[i] != '\0'; i++){
			//if the character from input_file is equal to an element in array alphabet
			//or if the character from input_file is equal to an uppercase letter
			//This is based on the ASCII numberical representations of characters
			if (character == alphabet[i] || character == (alphabet[i] - 32)){
				//then increment the count array at the index of that character
				count[i]++;
			}
		}
	}
	//close the file 
	fclose(file_input);
	//created variables max_index and max_frequency
	int max_index = 0;
	int max_frequency = 0;
	//for every character in the alphabet array not equal to a NULL character
	for(i = 0; alphabet[i] != '\0'; i++){
		//if the new frequency of characters in count array is greater than the old max_frequency of characters
		if(max_frequency < count[i]){
			//then the value at the index of count array is the new max frequency
			max_frequency = count[i];
			//the max index is the variable i's value
			max_index = i;
		}
	}
	//print the prompt with the character being the value of the alphabet array at the index of the max_index
	//and the max_frequency is the numberical value from count array
	printf("The most frequent letter is '%c'. It appeared %d times.\n", alphabet[max_index], max_frequency);
}		
	
