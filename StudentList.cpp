/*
  This program serves as a database for students. The user may add and remove students, as
  well as see the complete list of students they've entered. Each student has a first and last
  name, as well as an ID number and a GPA (0.0-5.0).
  git 
  Author: Luca Ardanaz
  Last Updated: 9/9/2025
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

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
void cinReset();

int main() {

  vector<Student*> students;
  char input[20];

  //This loop will run until the user enters "QUIT"
  do {
    //ask for user input
    cout << endl << endl << endl << "Enter command (type \"HELP\" for all commands):" << endl; 
    cin.get(input, 20);
    cinReset();
    
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
  
  cout << "Ending program." << endl;
  

  return 0;
}

void addStudent(vector<Student*> &s) {
  Student* sPtr = new Student();

  //asks for first name
  cout <<"Adding a new student..." << endl;
  cout << "Enter first name:" << endl;
  cin.get((*sPtr).firstName, 20);
  cin.get();

  //asks for last name
  cout << "Enter last name:" << endl;
  cin.get((*sPtr).lastName, 20);
  cin.get();

  //gets student id and verifies that its valid
  do {
    if (cin.fail()) {
      cinReset();
      
    }
    cout << "Enter student ID:" << endl;
    cin >> (*sPtr).ID;
  } while (cin.fail() || (*sPtr).ID <= 0);


  //gets student GPA and verifies its valid
  do {
    if (cin.fail()) {
      cinReset();
      
    }
    cout << "Enter GPA:" << endl;
    cin >> (*sPtr).GPA;
  } while (cin.fail() || (*sPtr).GPA < 0 || (*sPtr).GPA > 5.0);

  cinReset();
 
  //adds student to vector of student pointers
  s.push_back(sPtr);
}

void printStudents(vector<Student*> s) {
  
  if (s.size() > 0) {
    //prints out each student's complete information
    for (int i = 0; i < s.size(); i++) {
      cout << "Complete list of students:" << endl;
      /*
	The confusing looking logic with the modulos fixes the issue where numbers like 4.00 are displayed as 4.
	Essentially it just adds the ".00" to 4 or similarly a "0" to 3.2. That way the precision always shows the same.
      */
      cout << s.at(i) -> firstName << " " << s.at(i) -> lastName << ", " << s.at(i) -> ID << ", " << round((s.at(i) -> GPA) * 100) / 100 << (int(round((s.at(i) -> GPA) * 100)) % 10 == 0 ? (int(round((s.at(i) -> GPA) * 100)) % 100 == 0 ? ".00" : "0") : "")<< endl;
    }
  }
  else {
    cout << "There are no students in the database." << endl;
  }
}

void removeStudent(vector<Student*> &s) {
  //asks for ID and saves it
  //keeps asking till it gets an int
  int id = 0;
  do {
    if (cin.fail()) {
      cinReset();
    }
    cout << "Enter the student ID of the student to remove:" << endl;
    cin >> id;
  } while (cin.fail());

  cinReset();

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

//this clears all errors with cin so that cin always works as expected.
void cinReset() {
  cin.clear();
  cin.ignore(10000, '\n');
}
