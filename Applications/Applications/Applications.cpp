#include <iostream>
#include <string>
#include "UserAdmin.h"
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

void loadUsers(User &any, vector<User> &allUsers) {
	fstream file;
	file.open("users.csv", ios::in | ios::out | ios::app);
	string line;
	int count = 0;
	while (getline(file, line)) {
		if (count > 1) {
			stringstream newLine(line);
			string strLine;
			int counter2 = 0;
			while (getline(newLine, strLine, ',')) {
				if (counter2 == 0) {
					long long int num = stoi(strLine);
					allUsers.at(count).setId(num);
				}
				if (counter2 == 1) {
					allUsers.at(count).setUsername(strLine);
				}
				if (counter2 == 2) {
					allUsers.at(count).changePassword(strLine);
				}
			}
		} else {
			stringstream newLine(line);
			string strLine;
			int counter2 = 0;
			while (getline(newLine, strLine, ',')) {
				int val = stoi(strLine);
				long long int val1 = (int64_t)val;
				any.setCurrentId(val1);
				break;
			}
		}
		count++;
	}
}

int main()
{
	const Admin admin(5,"admin", "adminpass");
	vector<User> users;
	
	loadUsers(users[0], users);
}