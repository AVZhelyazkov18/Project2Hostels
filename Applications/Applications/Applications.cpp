#include <iostream>
#include <string>
#include "UserAdmin.h"
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

void cls();

bool isCharNumber(char a) {
	if (a >= 48 and a < 57)
	{
		return true;
	}
	return false;
}

void userMenu(User& user) {
	
	string str;
	while (true)
	{
		cls();
		cout << "1. Show your info" << endl;
		cout << "2. Log out" << endl;
		cin >> str;
		if (str == "1")
		{
			cout << "Username: " << user.getUsername() << endl;
			cout << "Password: ";
			for (int i = 0; i < user.getPassword().size(); i++)
			{
				if (i < 1) {
					cout << user.getPassword()[i];
				} else {
					cout << "*";
				}
			}
			cout << endl;
			cout << "First Name: " << user.getFirstName() << endl;
			cout << "Last Name: " << user.getLastName() << endl;
			cout << "Address: " << user.getAddress() << endl;
			cout << "Years old: " << user.getUsersYears() << endl;
			system("pause");
		}
		else if (str == "2") {
			return;
		} else {
			cout << "Please choose a valid option. (1/2)" << endl;
		}
	}
}

void adminMenu(vector<User> &users) {  

	string str;
	while (true)
	{
		cls();
		cout << "1. Show all Users" << endl;
		cout << "2. Create a user" << endl;
		cout << "3. Edit user's info" << endl;
		cout << "4. Disable a user's account." << endl;
		cout << "0. Log out" << endl;
		cin >> str;
		if (str == "1")
		{
			cls();
			while (true) {
				cls();
				cout << "1. Existing Users" << endl;
				cout << "2. Disabled Users" << endl;
				cout << "3. Back" << endl;
				cin >> str;
				if (str == "1") {
					cout << endl << endl << "+-------------------+" << endl;
					for (int i = 0; i < users.size(); i++)
					{
						if (not users.at(i)._isDisabled()) {
							cout << users.at(i).getUserId() << ". " << users.at(i).getFirstName() << " " << users.at(i).getLastName() << " " << users.at(i).getAddress() << " " << users.at(i).getUsersYears() << endl;
						}
					}
					cout << endl << "+-------------------+" << endl;
					system("pause");
				} else if (str == "2") {
					cout << endl << endl << "+-------------------+" << endl;
					for (int i = 0; i < users.size(); i++)
					{
						if (users.at(i)._isDisabled()) {
							cout << users.at(i).getUserId() << ". " << users.at(i).getFirstName() << " " << users.at(i).getLastName() << " " << users.at(i).getAddress() << " " << users.at(i).getUsersYears() << endl;
						}
					}
					cout << endl << "+-------------------+" << endl;
					system("pause");
				} else if (str == "3") {
					break;
				} else {
					cls();
					cout << "Please enter a valid option." << endl;
				}
			}
		} else if (str == "2") {
			User user;
			long long int size = (int64_t)users.size();
			bool val = user.setUserInfo(size);
			if(val) {
				if (user.getUsersYears() >= 12 and user.getUsersYears() <= 16)
				{
					users.push_back(user);
					cout << "User has been successfully added!" << endl;
					system("pause");
				} else {
					cout << "User does not meet the age requirments. (12 - 16)" << endl;
					system("pause");
				}
			}
		} else if (str == "3") {
			cls();
			int userIndex = 0;
			bool isCancelling = false;
			while (true) {
				while (true) {
					cin >> str;
					try {
						if (stoi(str) == 0) {
							isCancelling = true;
							break;
						}
						if (stoi(str) <= users.size() - 1 and stoi(str) > 0) {
							userIndex = stoi(str);
							break;
						} else {
							cls();
							cout << "User doesn't exist with ID: " << str << ". Please enter a valid ID or 0 to Cancel." << endl;
						}
					} catch (...) {
						cout << "Please enter a numerical ID." << endl;
						continue;
					}
				}
				if (isCancelling == true) {
					break;
				}
				cout << "1. Edit Username" << endl;
				cout << "2. Edit Password" << endl;
				cout << "3. Edit First Name" << endl; 
				cout << "4. Edit Last Name" << endl;
				cout << "0. Back" << endl;
				cin >> str;
				if (str == "1") {
					cin >> str;
					if (str != "")
					{
						users.at(userIndex).setUsername(str);
						cout << "Successfully changed User's Username!" << endl;
					}
				} else if (str == "2") {
					cin >> str;
					if (str != "")
					{
						users.at(userIndex).changePassword(str);
						cout << "Successfully changed User's Password!" << endl;
					}
				} else if (str == "3") {
					cin >> str;
					if (str != "")
					{
						users.at(userIndex).setFirstName(str);
						cout << "Successfully changed User's First Name!" << endl;
					}
				} else if (str == "4") {
					cin >> str;
					if (str != "")
					{
						users.at(userIndex).setLastName(str);
						cout << "Successfully changed User's Last Name!" << endl;
					}
				} else if (str == "0") {
					break;
				} else {
					cls();
					cout << "Please enter a valid option." << endl;
				}
			}
		} else if (str == "4") {
			int userIndex = 0;
			bool isCancelling = false;
			while (true) {
				cin >> str;
				try {
					if (stoi(str) == 0) {
						isCancelling = true;
						break;
					}
					if (stoi(str) <= users.size() - 1 and stoi(str) > 0) {
						userIndex = stoi(str);
						break;
					} else {
						cls();
						cout << "User doesn't exist with ID: " << str << ". Please enter a valid ID or 0 to Cancel." << endl;
					}
				} catch (...) {
					cout << "Please enter a numerical ID." << endl;
					continue;
				}
			}
			if (isCancelling == false) {
				User& user = users.at(userIndex);
				user.deleteUser();
			}
		} else if (str == "0") {
			return;
		} else {
			cout << "Please choose a valid option. (1/2/3/4/0)" << endl;
		}
	}

}

void cls() {
	system("cls");
}

void Login(vector<User> &users, int loginIndex) {
	User& user = users.at(loginIndex);

	if (user._isAdmin() == true) {
		adminMenu(users);
	} else {
		userMenu(user);
	}
}

bool showLogin(vector<User> &users) {
	bool entered = false;
	cout << "Hello! Please enter your Username and Password on one line with a space between them." << endl;
	cout << "Or write Exit to exit the program." << endl;
	cout << "Example: MyUsername MyPassword" << endl;
	int loginedIndex;
	string _user, _pass;
	while (not entered)
	{
		cin >> _user;
		if (_user == "Exit" or _user == "exit")
		{
			return false;
		}
		cin >> _pass;

		for (size_t i = 0; i < users.size(); i++)
		{
			if (users.at(i).getUsername() == _user and users.at(i).getPassword() == _pass) {
				entered = true;
				cls();
				cout << "Welcome " << _user << "!" << endl;
				loginedIndex = i;
				break;
			}
		}

		if (not entered) {
			cls();
			cout << "Username or password is wrong. Make sure, you type it correctly as both data members are case sensitive." << endl;
		}
	}
	Login(users, loginedIndex);
	return true;
}

void setAdmin(vector<User> &users) {
	User user;
	user.setId(0);
	user.setUsername("admin");
	user.changePassword("adminpass");
	user.setAdmin(true);
	user.setFirstName("Admin");
	user.setLastName("istrator");
	user.setYear(2021);
	user.setStudentName("N/A");
	user.setAddress("Unknown");
	users.push_back(user);
}

int main()
{
	vector<User> users;
	setAdmin(users);
	bool val = false;
	do {
		val = showLogin(users);
	} while (val);
	
}