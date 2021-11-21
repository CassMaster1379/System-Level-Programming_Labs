//Name: Cassandra Lundberg  Date: 11/14/21
//Title: international_dial_code.c
//This program takes a dialing code int vlue as input then searches for the int
//value in an array country_codes. If the value is found then the corresponding
//country's name is printed.


#include <stdio.h>  //include the standard input library
#include <string.h> //include the stringn liabrary

struct dialing_code{  //create a structure called dialing_code
	//one member of the structure is a pointer variable called country
	char *country; 
	//the other member of structure is an int variable called code
	int code;
};

main(){ //main method
	//create int variable number which will store the input value 
	int number;

	//the contant array of strucures called country_codes which has the pointer country pointing
	//to a literal string
	const struct dialing_code country_codes[] = 
	{{"Argentina", 54},
	{"Brazil", 55},
	{"China", 86},
	{"Congo, Dem. Rep. of", 243},
	{"Ethiopia", 251},
	{"Germany", 49},
	{"Bangladesh", 880},
	{"Colombia", 57},
	{"Egypt", 20},
	{"France", 33},
	{"India", 91},
	{"Indonesia", 62},
	{"Italy", 39},
	{"Mexico", 52},
	{"Pakistan", 92},
	{"Poland", 48},
	{"South Africa", 27},
	{"Spain", 34},
	{"Thailand", 66},
	{"Ukraine", 380}};	

	//print prompt to enter code to search
	printf("Enter an international dialing code: ");
	//scan input and store in address of number
	scanf("%d", &number);
	
	//create variables i for indexing and found for searching
	int i;
	int found = 0;
	//for every structure in the array  
	for(i = 0; i <20; i++){
		//if a structure of code member is equal to the int value entered from input
		if(country_codes[i].code == number){
			//then print the country string literal pointed to by the country member
			//of the aray of structures
			printf("The corresponding country is: %s\n", country_codes[i].country);
			//and assign found to 1
			found = 1;
		}
	}
	//if found does not equal 1 
	if(found != 1){
		//then print the error message
		printf("ERROR : THE INTERNATIONAL DIALING CODE DOES NOT EXIST FOR THIS DATABASE.\n");
	}
//and exit main method
return 0;
}
