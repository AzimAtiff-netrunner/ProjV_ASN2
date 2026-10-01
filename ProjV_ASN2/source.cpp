#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct STUDENT_DATA {
	string firstName;
	string lastName;
};


int main() {
#ifdef PRE_RELEASE
		cout << "Application is using pre-release source code." << endl;
#else
		cout << "Application is using standard source code." << endl;
#endif

	ifstream inf("StudentData.txt");

	if (!inf.is_open()) {
		cerr << "Error opening StudentData.txt file for reading." << endl;
		return 1;
	}
	vector<STUDENT_DATA> students;
	string line;
	while (getline(inf, line)) {
		STUDENT_DATA student;
		student.firstName;
		student.lastName;
		size_t comma = line.find(',');

		student.firstName = line.substr(0, comma);
		student.lastName = line.substr(comma + 1);

		students.push_back(student);

#ifdef _DEBUG
		cout << student.firstName << " " << student.lastName << ": " << endl;
#endif
	}

#ifdef PRE_RELEASE

	ifstream ef("StudentData_Emails.txt");

	if (!ef.is_open()) {
		cerr << "Error opening StudentData_Emails.txt file for reading" << endl;
		return 1;
	}
	while (getline(ef, line)) {
		cout << line << endl;
	}

#endif
	

	inf.close();
#ifdef PRE_RELEASE
	ef.close();
	#endif
	return 0;
}