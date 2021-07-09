#include "UserAdmin.h"
#include <iostream>
#include <time.h>

#pragma warning(disable : 4996)

using namespace std;

long long int User::getId() {
	return User::Id;
}

string User::getUsername() {
	return User::Username;
}

void User::setUsername(string givenUsername) {
	User::Username = givenUsername;
}

string User::getPassword() {
	return User::Password;
}

void User::changePassword(string password) {
	User::Password = password;
}

string User::getFirstName() {
	return User::firstName;
}

string User::getLastName() {
	return User::lastName;
}

string User::getStudentName() {
	return User::studentName;
}

string User::getAddress() {
	return User::address;
}

int User::getYearOfStudent() {
	return User::year_of_student;
}

int Admin::getAdminLevel() {
	return adminLevel;
}

void Admin::setAdminLevel(short int level) {
	Admin::adminLevel = level;
}

int User::getUsersYears() {
	if (User::year_of_student == NULL) { cout << "Student has no years." << endl; }

	time_t now = time(0);

	tm* ltm = localtime(&now);

	return (1900 + ltm->tm_year) - User::year_of_student;
}

bool User::isPartOfAddressExisting(string partAddress) {
	bool isFound =  User::address.find(partAddress);
	
	return isFound;
}