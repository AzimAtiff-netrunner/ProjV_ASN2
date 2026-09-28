#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

struct STUDENT_DATA {
	char firstName[20];
	char lastName[20];
};

int main() {
	ifstream inf("StudentData.txt");
	if (!inf.is_open()) {
		cerr << "Error opening StudentData.txt file for reading." << endl;
		return 1;
	}
	vector<STUDENT_DATA> students;
	string line;
	while (getline(inf, line)) {
		STUDENT_DATA student;
		if (IsDebuggerPresent()) {
			cout << line << endl;
		}
		students.push_back(student);
		
	}


	inf.close();
	return 0;
}