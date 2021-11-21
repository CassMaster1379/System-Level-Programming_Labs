#!/bin/bash
# Name of Programmer: Cassandra Lundberg  Email of Programmer: clundberg3@student.gsu.edu
#Title: phonebook.sh
# This shell script performs functions to display, modify, delete, add, and search line existing in a text file called addressbook.txt

main_menu(){ #method to display the main menu prompt
echo "*******************"
echo "Cassie's Phone Book" #prompt text for flare
echo "*******************"
echo " "
echo "Please enter a number:"
echo " 1.Display"
echo " 2.Search"
echo " 3.Delete"
echo " 4.Modify"
echo " 5.Add"
echo " 6.Leave" 

read choice #takes user's input of an option
}

main_menu #calls on the prompt method
while [ $choice -ne 6 ] #while the choice does not call to exit
do
Book="addressbook.txt" #the text file is assigned to a variable called Book

	case "$choice" in  #using the case control structure to evaluate each option
		"1")  #if option is choice number 1 then the code will display the contents of the addressbook.txt file
			echo " "
			sort -t";" +0 -1 -f $Book | cat -n $Book #using sed to determine the field separators are semi colons
								 #and sorting by the first field, first name, then using the cat 
								 #command to display the contents
			echo " "
			main_menu  #return to main menu method to perform other functions
			;;
		"2") #if option is choice number 2 then search for a contact using the first name or phone number
 			echo "What is the first name or phone number of the contact to search?"
			read find #take user's input of the string to search

			grep -i $find $Book #using grep find the string in the text file
			main_menu #return to main menu method
			;;
		"3") #if option is choice 3 then delete a contact by searching then using sed to permanently delete
			echo "Which contact would you like to delete?"
			echo "Please enter a first name: " 
		 	read fname #user's input of first name to delete
			
			if grep -qi "$fname" "$Book" #if the first name exists in the file using grep then
			then
				echo "Do you wish to delete this contact?" #ask user to confirm
				echo "y/n"
				echo " "
				read confirmation #take confirmation input

				if [ "$confirmation" == "y" ] #if the confirmation is equal to the strin "y"
				then

					sed -i "/$fname/d" $Book #then delete the lsnene as the executable program pathname used to interpret the  script as a bash shell, written as “#!/bin/bash” with the first name
                                                                            
					echo " "
					echo "The contact has been deleted" #ensure the contact has been deleted
					main_menu #return to main menu method
				else #the user denied the confirmation
					echo "The contact has not been deleted" #the contact still exists
					main_menu #return to main menu method
				fi
			else #otherwise the contact does not exist to delete
				echo " "
				echo "There are no such contacts that match the entered name or phone number" #tells user of no match
				main_menu #return to main menu method
			fi
			;;
		"4") #if choice is option 4 then modify the contact by searching for contact and using sed to change contents of line 
			echo " "
			echo "Which contact would you like to edit? Enter first and last name" #enter first and last name to search
			echo "Enter first name: "
			read oldfirstname #user inputs first name
			echo "Enter last name: "
			read oldlastname #user inputs last name
			
			if grep -iq "$oldfirstname; $oldlastname" "$Book" #if the first and last name exist in the text file then 
			then 
				echo "Enter the modified first name: "
				read newfirstname #user inputs new first name

				echo "Enter the modified last name: "
				read newlastname #user inputs new last name

				echo "Enter the modified phone number: "
				read newphonenumber #user inputs new phone number

				echo "Enter the modified address: "
				read newaddress #user inputs new address 

				echo "Change the contact to: " #ask user to confirm new fields of contact
				echo -e "$newfirstname; $newlastname; $newphonenumber; $newaddress" #print the fields of contact
				echo "y/n" 
				echo " "
				read confirmation #input user's confirmation 

				if [ "$confirmation" == "y" ] #if user's confirmation is "y" then
				then
					sed -i "/$oldfirstname/c$newfirstname; $newlastname; $newphonenumber; $newaddress" "$Book"
					#then change the line with the original first name to the new fields of the contact
					echo "The contact information was changed" #tell the user that the fields have changed
					main_menu #return to main menu method
				else #otherwise the user does not confirm modification
  					echo "The contact information was not changed" #inform user of no change
					main_menu #return to main menu method
				fi
				
			else #otherwise the contact does not exist to modify
				echo "The contact does not exist to modify"
 				main_menu #return to main menu method
			fi
			;;
		"5") #if the choice is option 5 then a new contact is added by creating new fields of a line an redirecting them to 
		     #the text file 
			echo "Enter the first name: "
			read firstname #enter the first name of the new contact

			echo "Enter the last name: "
 			read lastname #enter the last name of the new contact

			echo "Enter the phone number: "
			read phonenumber #enter the new phone number of the contact

			echo "Enter the address: "
			read address #enter the address of the new contact
	
			echo " "
			echo "Do you wish to enter the values? " #ask user to confirm new contact information
			echo -e "$firstname; $lastname; $phonenumber; $address" #print information of contact
			echo "y/n" 
			echo " "
			read confirmation #take user's input of confirmation

			if [ "$confirmation" == "y" ] #if the confirmation is equal to the string "y" then
			then
				echo "$firstname; $lastname; $phonenumber; $address" >>$Book #redirect all the fields to the text file
				echo "The values were written to the address book" #tell the user of the entry
			else #otherwise the entry is not entered into address book
				echo "The values were not entered" #tell the user the entry was cancelled
			fi	
			main_menu #return to the main menu method
			;;
		esac
		done
