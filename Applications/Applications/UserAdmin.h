#pragma once
#include <string>
#pragma warning(suppress : 4996)

class User {
	private:
		long long int Id;
		std::string Username;
		std::string Password;
		std::string firstName;
		std::string lastName;
		std::string address;
		std::string studentName;
		int year_of_student;
	protected:
		long long int getId();
		std::string getUsername();
		std::string getPassword();
		std::string getFirstName();
		std::string getLastName();
		std::string getAddress();
		std::string getStudentName();
		int getYearOfStudent();
	public:
		void setUsername(std::string givenUsername);
		void changePassword(std::string password);
		int getUsersYears();
		bool isPartOfAddressExisting(std::string partAddress);
};

class Admin : public User {
	private:
		short int adminLevel;
	public: 
		int getAdminLevel();
		void setAdminLevel(short int level);
};