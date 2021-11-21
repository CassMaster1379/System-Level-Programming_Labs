/*Name: Cassandra Lundberg  Date: 10/15/21 Title: getPhoneNumber.c
 * This program takes a user input of a phone number in one format 
 * and outputs the phone number in a different format*/

#include <stdio.h>  //directive stating the information in <stdio.h is to be
                    //included into the program before it is compiled

int main (void){   //the main function of int type return value

	int i,j,k; //initializing the parts of the phone number
 
	printf("Enter phone number [(999)999-9999]: "); //prompting the user
	
	//the scan function taking each separate part of the phone number as
	//an integer value with two parenthesis as non-white space characters
	//and one dash as the other non-white space character separating the
	//parts
	scanf ("(%d)%d-%d", &i, &j, &k); 

	//the print function which prints each part of the scanned phone number
	//separated by a dash
	printf("You entered %d-%d-%d\n", i, j, k);

	//the return statement causing the main function to return a value of
	//0 then terminate the program
	return 0;
}
