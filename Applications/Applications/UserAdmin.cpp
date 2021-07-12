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

void User::setFirstName(std::string name) {
	User::firstName = name;
}
void User::setAddress(std::string address) {
	User::address = address;
}
void User::setLastName(std::string lastName) {
	User::lastName = lastName;
}
void User::setYear(int year) {
	User::year_of_student = year;
}
void User::setStudentName(std::string name) {
	User::studentName = name;
}


int User::getUsersYears() {
	if (User::year_of_student == NULL) { cout << "Student has no years." << endl; }

	time_t now = time(0);

	tm* ltm = localtime(&now);

	return (1900 + ltm->tm_year) - User::year_of_student;
}

bool User::isPartOfAddressExisting(string partAddress) {
	if (INT_MAX <= User::address.find(partAddress))
	{
		return false;
	} else {
		return true;
	}
}

void User::setId(long long int id) {
	User::Id = id;
}

void User::setUserInfo(long long int &lastId) {
	cin >> User::firstName;
	cin >> User::lastName;
	cin >> User::Username;
	cin >> User::Password;
	cin >> User::address;
	cin >> User::studentName;
	cin >> User::year_of_student;
}

void User::setCurrentId(long long int &id) {
	User::currentId = id;
}