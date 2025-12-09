//Haroitus: Hotelli harjoitustyö
//Tekijä: Veeti "Hazel" Stolt

#include<iostream>
#include<string>


using namespace std;

//prototypes for the functions aside from "main"
int order(int room[], int ROOMS, int PRICE);
int menu(int room[], int ROOMS, int PRICE);


int main() {	//main initializes constants and room reservation array

	int const PRICE = 100;
	int const ROOMS = 20;

	int room[ROOMS];

	menu(room, ROOMS, PRICE);

	return 0;

}

int menu(int room[], int ROOMS, int PRICE) {	//menu handler

	int thing;
	int goAgain;
	int sum = 0;
	int free;
	bool error;

	cout << "\nWhat would you like to do?\n\n 1. Make reservation\n 2. Print current room reservation status\n 0. Close program\n\n";	//ask what user wants to do and take input 
	cin >> thing;

	switch (thing) {	//menu switch 

	case 1:	{	//order case calls order function

		order(room, ROOMS, PRICE);

		cout << "Would you like to exit the program?\n\n 1. Continue operating.  |  0. Close program.\n";
		cin >> goAgain;

		if (goAgain == 1) {

			menu(room, ROOMS, PRICE);

		}
		else if (goAgain != 0) {

			error = true;

			cout << "Error! Please enter a supported input.";
			cin.clear();
			cin.ignore(80, '\n');

		}

		return 0;
		break;

	}
	case 2: {	//simple case prints out all rooms' reservation statuses

		cout << "Current reservation status:\n\n";

		for (int b = 0; b < ROOMS; b++) {

			if (room[b] == 1) {

				cout << "Room " << b + 1 << ". Reserved.\n";
				sum++;

			}
			else {

				cout << "Room " << b + 1 << ". Free.\n";

			}

		}
		if (sum == ROOMS) {

			cout << "All rooms are currently reserved.\n";

		}
		else {

			free = ROOMS - sum;

			cout << "There are currently " << free << " rooms available for reservation.\n\n";

		}

		do {	//input validation for closing the program or continuing operation although this isn't very necessary, failing to input a number between 0 and 1 will just close the program without this input validator

			error = false;

			cout << "Would you like to exit the program?\n\n 1. Continue operating.  |  0. Close program.\n";
			cin >> goAgain;

			if (goAgain == 1) {

				menu(room, ROOMS, PRICE);

			}
			else if (goAgain != 0) {

				error = true;

				cout << "Error! Please enter a supported input.";
				cin.clear();
				cin.ignore(80, '\n');

			}

			return 0;
		} while (error);

	}
	case 0: {	//simply breaks the switch and returns 0 effectively ending the program

		return 0;
		break;

	}
	default: {	//default for making sure the input is allowed

		cout << "\nUNSUPPORTED INPUT!\n\n";  

		cout << "Would you like to exit the program?\n\n 1. Continue operating.  |  0. Close program.\n";
		cin >> goAgain;

		if (goAgain == 1) {

			menu(room, ROOMS, PRICE);

		}

	}
	}

	return 0;

}

int order(int room[], int ROOMS, int PRICE) {

	//declaring all variables to be used in this function

	string name;
	int days;
	int roomNum;
	bool error;
	int cost;

	//setting "num" to 0 by default
	int num = 0;

	while (num == 0) {	//actual reservation loop

		//Ask for customer details
		cout << "Please input the name, under which the reservation should be made:\n\n";
		cin >> name;

		do {	//input validation for days
			error = false;

			cout << "Please input the days wanted:\n\n";	//asking for wanted room number
			cin >> days;

			if (cin.fail()) {

				error = true;
				cout << "Error! Please input a valid number.\n";
				cin.clear();
				cin.ignore(80, '\n');

			}

		} while (error);

		do {	//input validation room number
			error = false;

			cout << "Please input the wanted room number:\n\n";	//asking for wanted room number
			cin >> roomNum;

			if (cin.fail() || roomNum > ROOMS || roomNum < 1) {	//error state

				error = true;
				cout << "Error! Please input a valid number between 1-" << ROOMS << ".\n";
				cin.clear();
				cin.ignore(80, '\n');

			}
			if (room[roomNum - 1] == 1) {	//this one to check whether the wanted room is occupied

				error = true;
				cout << "Sorry, this room already has a reservation.\nPlease input a new room number to continue.\n";
				cin.clear();
				cin.ignore(80, '\n');

				int temp = 0;

				for (int c = 0; c < ROOMS; c++) {	//something about softlock prevention 

					if (room[c] == 0) {

						temp++;

					}
					
					cout << "\nThere are currently " << temp << " rooms available.\n";

					if (temp == 0) {	//without this trying to make an order whilst all rooms are reserved would lock user in an endless loop of trying to reserve a room and failing due to all rooms being occupied.

						cout << "\n\nNo rooms are currently available to reserve. Would you like to close the program?\n";
						cin >> num;

					}

					if (num == 1) {

						menu(room, ROOMS, PRICE);
						error = false; 
					}

					break;

				}

			}
			

		} while (error);
		
		//making sure customer details are correct
		cout << "Is " << days << " days in room: " << roomNum << ". Under the name " << name << " correct?\n\n Yes (1) | No (0)\n";
		cin >> num;
		cout << endl;

	}

	room[roomNum - 1] = 1;

	//output cost of stay
	cost = days * PRICE;
	cout << "The total cost of the stay is: " << cost << " Euro\n";

	return 0;

}
