//
// Public link - https://repl.it/@Meagher01/File-Reader#main.cpp
// Invite link - https://repl.it/join/ewwrbsad-meagher01
//
#include <iostream>
#include <fstream>
#include <sys/stat.h>

using namespace std;

// Gets a filename from the user.
string getFileToSearch() {
  string file;
  cout << "Please enter a valid filename: ";
  getline(cin, file);
  return file;
}

// Message to display if a file doesn't exist.
void displayFileNotExist(string file) {
  cout << "Sorry, ' "<< file << "' does not exist\n" << endl;;
}

// Checks whether a file exists.
bool fileExists(string file) {
  struct stat buffer;   
  bool exists = stat(file.c_str(), &buffer) == 0;
  if (exists) {
    return true;
  }
  displayFileNotExist(file);
  return (stat (file.c_str(), &buffer) == 0);
}

// Displays contents of the file and number of lines.
void displayFile(string file) {
  string line;
  int count = 0;
  ifstream myfile(file.c_str());
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      count++;
      cout << count << ": " << line << endl;
    }
    myfile.close();
  } 
  cout << "\nTotal number of lines read: " << count << endl;
}

// init function for File Reader.
int main() {
  string file;
  do {
    file = getFileToSearch();
  } while (!fileExists(file));

  displayFile(file);
}
