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
void removeStudent(vector<Student*> &s);

int main() {

  vector<Student*> students;
  char input[20];

  //This will run until the user enters "QUIT"
  do {
    //ask for user input
    cout << endl << "Enter command (type \"HELP\" for all commands):" << endl; 
    cin.get(input, 20);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << endl;
    
    if (strcmp(input, "HELP") == 0) {
      //show all the valid commands
      cout << "List of commands:" << endl;
      cout << " - ADD: Add a new student to the database." << endl;
      cout << " - PRINT: Prints out all of the students in the database." << endl;
      cout << " - DELETE: Remove a student from the database." << endl;
      cout << " - QUIT: Close the program" << endl;
    }
    else if (strcmp(input, "ADD") == 0) {
      //add a student
      addStudent(students);
    }
    else if (strcmp(input, "PRINT") == 0) {
      //show the complete list of students
      printStudents(students);
    }
    else if (strcmp(input, "DELETE") == 0) {
      //remove a student
      removeStudent(students);
    }
    
  } while (strcmp(input, "QUIT") != 0);
  
  
  

  return 0;
}

void addStudent(vector<Student*> &s) {
  Student* sPtr = new Student();
  cout <<"Adding a new student..." << endl;
  cout << "Enter first name:" << endl;
  cin.get((*sPtr).firstName, 20);
  cin.get();

  cout << "Enter last name:" << endl;
  cin.get((*sPtr).lastName, 20);
  cin.get();

  //gets student id and verifies that its valid
  do {
    if (cin.fail()) {
      cin.clear();
      cin.ignore(10000, '\n');
    }
    cout << "Enter student ID:" << endl;
    cin >> (*sPtr).ID;
  } while (cin.fail() || (*sPtr).ID <= 0);

  
  do {
    if (cin.fail()) {
      cin.clear();
      cin.ignore(10000, '\n');
    }
    cout << "Enter GPA:" << endl;
    cin >> (*sPtr).GPA;
  } while (cin.fail() || (*sPtr).GPA < 0 || (*sPtr).GPA > 4.5);

  cin.clear();
  cin.ignore(10000, '\n');
  
  s.push_back(sPtr);
}

void printStudents(vector<Student*> s) {
  cout << "Complete list of students:" << endl;

  //prints out each student's complete information
  for (int i = 0; i < s.size(); i++) {
    cout << s.at(i) -> firstName << " " << s.at(i) -> lastName << ", " << s.at(i) -> ID << ", " << s.at(i) -> GPA << endl;
  }
}

void removeStudent(vector<Student*> &s) {
  //asks for ID and saves it
  int id = 0;
  do {
    if (cin.fail()) {
      cin.clear();
      cin.ignore(10000, '\n');
    }
    cout << "Enter the student ID of the student to remove:" << endl;
    cin >> id;
  } while (cin.fail());

  //removes ALL students who have that ID
  for (int i = 0; i < s.size(); i++) {
    if ((*(s.at(i))).ID == id) {
      //deletes student and gets rid of pointer
      delete s.at(i);
      s.erase(s.begin() + i);
      i--;
    }
  }
}
