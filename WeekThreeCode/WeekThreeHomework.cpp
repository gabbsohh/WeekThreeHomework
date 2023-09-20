// Gabriela Ortega
// GAME 2303
// Sept 19, 2023
// Reads a list of students and their grades from a file, and ultimately 
// evaluates and displays that data in a number of ways.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Student class
class Student
{
public:
	// variables for student
	string firstName;
	string lastName;
	int grade;
};

// Bubble sorting
void gradeSort(vector<Student>& students)
{
    for (int i = 0; i < students.size() - 1; ++i) {
        for (int j = 0; j < students.size() - i - 1; ++j) {
            if (students[j].grade < students[j + 1].grade) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

int main()
{
    // Create a vector for Student
	vector <Student> students;

	ifstream inputFile("example.txt");

    // Error code in case file cannot open
	if (!inputFile.is_open()) {
		cout << "Error: Unable to open file." << endl;
		return 1;
	}

    //create variable for getline
    string line;
    while (getline(inputFile, line)) {
        int firstSpace = line.find(' ');
        if (firstSpace != string::npos) {
            string firstName = line.substr(0, firstSpace);
            line.erase(0, firstSpace + 1);

            int secondSpace = line.find(' ');
            if (secondSpace != string::npos) {
                string lastName = line.substr(0, secondSpace);
                line.erase(0, secondSpace + 1);


                int grade = std::stoi(line);

                // creating a student object
                Student student;
                student.firstName = firstName;
                student.lastName = lastName;
                student.grade = grade;

                //placing student objects into the student vector
                students.push_back(student);
            }
        }
    }

    //CLOSE FILE
	inputFile.close();
    
    //call function to sort grades
    gradeSort(students);

    //display using loop
    for (size_t i = 0; i < students.size(); ++i) {
        cout << "First Name: " << students[i].firstName << endl;
        cout << "Last Name: " << students[i].lastName << endl;
        cout << "Grade: " << students[i].grade << endl;
    }

	return (0);
}