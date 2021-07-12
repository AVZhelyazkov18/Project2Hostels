#pragma once
#include <string>
#pragma warning(suppress : 4996)

class User {
	private:
		long long int Id = 0;
		std::string Username;
		std::string Password;
		std::string firstName;
		std::string lastName;
		std::string address;
		std::string studentName;
		int year_of_student = 0;
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
		void createUser(long long int &userIds);
		User(std::string userName, std::string passWord, std::string fName, std::string lName, std::string Address, std::string studentName, int studentYear) {
			Username = userName;
			Password = passWord;
			this->firstName = fName;
			this->lastName = lName;
			this->address = Address;
			this->studentName = studentName;
			this->year_of_student = studentYear;
		}
		User() { Id = 1; year_of_student = 0; }
};

class Admin : public User {
	private:
		short int adminLevel;
	public: 
		int getAdminLevel();
		void setAdminLevel(short int level);

		Admin(int level, std::string _username, std::string _password) {
			this->adminLevel = level;
			setUsername(_username);
			changePassword(_password);
		}
};