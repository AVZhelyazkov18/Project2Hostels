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

void User::setAdmin(bool isAdmin) {
	User::isAdmin = isAdmin;
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

	time_t now = time(0);

	tm* ltm = localtime(&now);

	if ((1900 + ltm->tm_year) - User::year_of_student < 1) { cout << "Student doesn't exist." << endl; }

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

bool User::setUserInfo(long long int &lastId) {
	User::Id = lastId;
	cout << "Enter the User's First Name: ";
	cin >> User::firstName;
	cout << "Enter the User's Last Name: ";
	cin >> User::lastName;
	cout << "Enter the User's Username: ";
	cin >> User::Username;
	cout << "Enter the User's Password: ";
	cin >> User::Password;
	cout << "Enter the User's Address: ";
	cin >> User::address;
	cout << "Enter the Student's Name: ";
	cin >> User::studentName;
	cout << "Enter the Student's Year of birth: ";
	cin >> User::year_of_student;
	if (User::firstName == "" or User::lastName == "" or User::address == "" or User::Password == "" or User::Username == "" or User::studentName == "")
	{
		User::firstName = "";
		User::lastName = "";
		User::address = "";
		User::Username = "";
		User::Password = "";
		User::studentName = "";
		cout << "User has not been created due to empty data." << endl;
		return false;
	}
	return true;
}

void User::disableUser() {
	User::isDisabled = true;
}

bool User::_isDisabled() {
	return User::isDisabled;
}

void User::deleteUser() {
	if (User::isDisabled == false) {
		User::disableUser();
		cout << "User has been deleted successfully." << endl;
	}
}

bool User::_isAdmin() {
	return User::isAdmin;
}

int User::getUserId() {
	return User::Id;
}