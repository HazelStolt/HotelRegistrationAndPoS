//Haroitus: Hotelli harjoitustyö
//Tekijä: Veeti "Hazel" Stolt

#include<iostream>
#include<iomanip>
#include<string>
#include<random>
#include<vector>

using namespace std;

int order(int room[], int ROOMS, int PRICE);
int menu(int room[], int ROOMS, int PRICE);


int main() {

	int const PRICE = 100;
	int const ROOMS = 50;

	int room[ROOMS]{};

	menu(room, ROOMS, PRICE);

	return 0;

}

int menu(int room[], int ROOMS, int PRICE) {

	int thing;
	int goAgain;

	cout << "\nWhat would you like to do?\n\n 1. Make reservation\n 0. Close program\n\n";
	cin >> thing;

	switch (thing) {

	case 1: {

		order(room, ROOMS, PRICE);

		cout << "Would you like to exit the program?\n\n 1. Continue operating.  |  0. Close program.\n";
		cin >> goAgain;

		if (goAgain == 1) {

			menu(room, ROOMS, PRICE);

		}

		return 0;
		break;
		
	}
	case 0: {

		return 0;
		break;

	}
	default: {

		cout << "\nUNSUPPORTED INPUT!\n\n";  //default for making sure the input is allowed

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

			if (cin.fail() || roomNum > 50 || roomNum < 1) {

				error = true;
				cout << "Error! Please input a valid number between 1-" << ROOMS << ".\n";
				cin.clear();
				cin.ignore(80, '\n');

			}
			if (room[roomNum - 1] == 1) {	//this one to check whether the wanted room is occupied

				cout << "Sorry, this room already has a reservation.\nPlease input a new room number to continue.\n";
				cin.clear();
				cin.ignore(80, '\n');

			}


		} while (error);
		
		//making sure customer details are correct
		cout << "Is " << days << " days in room: " << roomNum << ". Under the name " << name << " correct?\n\n Yes (1) | No (0)\n";
		cin >> num;
		cout << endl;

	}

	room[roomNum - 1] = 1;

	for (int a = 0; a < ROOMS; a++) {

		cout << room[a] << endl;

	}

	//output cost of stay
	cost = days * PRICE;
	cout << "The total cost of the stay is: " << cost << " Euro\n";

	return 0;

}
