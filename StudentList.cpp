#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct Student {
  char firstName[20];
  char lastName[20];
  int ID;
  float GPA;
};

void addStudent(vector<Student*> &s);
void printStudents(vector<Student*> s);

int main() {

  vector<Student*> students;

  char input[20];

  do {
    cout << endl << "Enter command (type \"HELP\" for all commands):" << endl; 
    cin.get(input, 20);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << endl;

    if (strcmp(input, "HELP") == 0) {
      cout << "List of commands:" << endl;
      cout << " - ADD: Add a new student to the database." << endl;
      cout << " - PRINT: Prints out all of the students in the database." << endl;
      cout << " - DELETE: Remove a student from the database." << endl;
      cout << " - QUIT: Close the program" << endl;
    }
    else if (strcmp(input, "ADD") == 0) {
      addStudent(students);
    }
    else if (strcmp(input, "PRINT") == 0) {
      printStudents(students);
    }
    else if (strcmp(input, "REMOVE") == 0) {

    }
    
  } while (strcmp(input, "QUIT") != 0);
  
  
  

  return 0;
}

void createStudent(vector<Student*> &s) {
  Student newS;
  cout <<"Adding a new student..." << endl;
  cout << "Enter first name:" << endl;
  cin.get(newS.firstName, 20);
  cin.get();

  cout << "Enter last name:" << endl;
  cin.get(newS.lastName, 20);
  cin.get();

  cout << "Enter student ID:" << endl;
  cin >> newS.ID;

  cout << "Enter GPA:" << endl;
  cin >> newS.GPA;

  s.push_back(&newS);
}

void printStudents(vector<Student*> s) {
  cout << "Complete list of students:" << endl;

  for (int i = 0; i < s.size(); i++) {
    cout << s.at(i) -> firstName << " " << s.at(i) -> lastName << ", " << s.at(i) -> ID << ", " << s.at(i) -> GPA << endl;
  }
}
