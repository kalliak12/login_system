//Login System avec Registration + File Storing
//inspo from hazardedit 
//By kalliak12 30/3/23


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIn() {
	string username, password, u, p;
	cout << "Enter username: "; cin >> username;
	cout << "Enter password: "; cin >> password;

	ifstream read(username + ".txt");
	getline(read, u);
	getline(read, p);

	if (u == username && p == password) {
		return true;
	}
	else {
		return false;
	}
}
int main(){
	int choice;

	cout << "1: Register\n2: Login\nYour choice: "; cin >> choice;
	if (choice == 1) {
		string username, password;

		cout << "select a username: "; cin >> username;
		cout << "select a password: "; cin >> password;

		ofstream file;
		file.open(username + ".txt");
		file << username << endl << password;
		file.close();

		main();
	}
	else if (choice == 2) {
		bool status = IsLoggedIn();

		if (!status) {
			
			cout << "False Loggin!" << endl;
			system("PAUSE");
			return 0;
		}
		else {

			cout << "succesfully logged in!" << endl;
			system("PAUSE");
			return 1;
		}
	}
}