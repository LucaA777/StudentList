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

Student addStudent();


int main() {

  vector<Student*> students;

  Student greg = addStudent();

  students.push_back(&greg);
  
  cout << (*students.at(0)).firstName << endl;
  cout << greg.lastName << endl;
  cout << greg.ID << endl;
  cout << greg.GPA << endl;
  


  





  return 0;
}

Student addStudent() {
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

  return newS;
}
