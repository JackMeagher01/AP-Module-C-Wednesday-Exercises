//
// Public link - https://repl.it/@Meagher01/File-Writer#main.cpp
// Invite link - https://repl.it/join/cdiibxpf-meagher01
//
#include <iostream>
#include <fstream>

using namespace std;

// Gets the name to be entered by the user.
string getName() {
  string name;
  cout << "Enter name: ";
  getline(cin, name);
  return name;
}

// Checks whether the user has entered a valid value. e.g. 'Y' or 'N'.
bool validInput(string input) {
  if (input.length() > 1) {
    cout << "Enter a valid value." << endl;
    return false;
  }
  char formatInput = toupper(input[0]);
  switch (formatInput) {
    case 'Y': return true;
    case 'N': return true;
    default: cout << "Enter a valid value" << endl; return false;
  }
}

// Asks user if they want to enter another name.
bool addAnother() {
  string input;
  do {
    cout << "Add another (y/n)? ";
    getline(cin, input);
  } while (!validInput(input));
  
  return (input[0] == 'y') || (input[0] == 'Y');
}

// init function for File Writer.
int main() {
  string name;
  ofstream file;
  file.open("list.csv");
  do {
    name = getName();
    cout << name << endl;
    cout << "Updating file..." << endl;
    file << name << endl; 
  } while (addAnother());
  file.close();

  cout << "Goodbye"; 

  return 0;
}
