//Created by Jared Alwyn, Sept 11 2017
//Phone Number List

#include "stdafx.h"
#include <iostream>;
#include <string>;
#include <cstring>;
using namespace std;

int main() {
	const int size = 11, length = 25;	//Size holds total names on list, length is based on max string length.
	bool found = false;					//Used to prompt error if no match is found.
	char *str_ptr = nullptr;			//Pointer used to search list with user data.
	char look_up[length];				//Used to store user value in search.
	char again;							//Holds value to search for another name.

	//Phone list that user will search from.
	char phone_list[size][length] = { "Renee Javens, 678-1223",
									  "Joe Looney, 586-0097",
									  "Geri Palmer, 223-8787",
									  "Lynn Presnell, 887-1212",
									  "Bill Wolfe, 223-8878",
									  "Sam Wiggins, 486-0998",
									  "Bob Kain, 586-8712",
									  "Tim Haynes, 586-7676",
									  "John Johnson, 223-9037",
									  "Jean James, 678-4939",
									  "Ron Palmer, 486-2783" };

	//Title and prompt user for name to search for.
	do {
		cout << "\t\t---Phone Number List---\n\n"
			<< "Enter a name or partial name to search the phone list: ";
		cin.ignore();
		cin.getline(look_up, length);
		cout << endl;

		//Searches for match in phone list using pointer. 
		for (int count = 0; count < size; count++) {
			str_ptr = nullptr;
			str_ptr = strstr(phone_list[count], look_up);
			if (str_ptr != nullptr) {
				found = true;
				cout << phone_list[count] << endl;
			}
		}

		//Display error message if no data was found.
		if (found == false)
			cout << "Sorry, no matching name and number was found.\n";

		//Set pointer to null pointer and prompt question to re-search.
		str_ptr = nullptr;
		cout << "\nWould you like to search for another name? (Y or N) ";
		cin >> again;
		cout << endl;

	} while (toupper(again) == 'Y');

	//Used to hold program open.
	cout << "\nThank you for using the program." << endl;
	system("Pause");
	return 0;
}

