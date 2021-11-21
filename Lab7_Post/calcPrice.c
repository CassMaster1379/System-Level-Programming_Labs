/*Name: Cassandra Lundberg  Date: 10/15/21  Title: calcPrice.c
 * This program formats information entered by a user and calculates the 
 * total amount purchased*/

#include <stdio.h> //directive stating the information in <stdio.h> is to be included into the program before it
                   //is complied

int main(void){ //main function of int type to return an integer value

	//declaring the variables used in the program
	int item, quantity, month, day, year;  //includes whole numbers
	float price, total;  //includes decimal numbers
	
	//prompts user to enter an integer item number and uses scanf function to store input in variable item
	printf("Enter item number: ");
	scanf("%d", &item);

	//prompts user to enter unit price decimal number and scanf function to store in price variable
	printf("Enter unit price: ");
	scanf("%f", &price);

	//prompts user to enter quantity and scnaf function to store in quantity variable
	printf("Enter quantity: ");
	scanf("%d", &quantity);

	//prompts user to enter purchase date with non-white space characters to separate the variables of month
	//day and year then stores then in the variables using scanf
	printf("Enter purchase date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &month, &day, &year);

	//calculates the total price by multiplying the quantity and the price entered by user
	total = price * quantity;

	//prints the columns for the information calculated 
	printf("Item\tUnit Price\tQTY\tPurchase Date\tTotal Amount\n");
	printf("\n");

	//prints each variable's value under the columns separated by tabs
	//item, quantity, month, day, and year are all left justified by using the minus symbol
	//price ant total are right justified by default with a minimum of 4 characters overall and precision
	//of only 2 characters after the decimal 
	printf("%-d\t$\t%4.2f\t%-d\t%-d/%d/%d\t$\t%4.2f\n", item, price, quantity, month, day, year, total);
	
	//the return statement to return a value of 0 from the main function then terminates the program
	return 0;

} 
