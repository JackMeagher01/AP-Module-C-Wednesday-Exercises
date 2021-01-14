//
// Public link - https://repl.it/@Meagher01/File-Exists#main.cpp
// Invite link - https://repl.it/join/lcbzlunq-meagher01
//
#include <iostream>
#include <sys/stat.h>
using namespace std;

// Checks whether a file exists.
bool fileExists(string file) {
  struct stat buffer;   
  return (stat (file.c_str(), &buffer) == 0);
}

// Gets a filename from the user.
string getFileToSearch() {
  string file;
  cout << "Filename to check: ";
  getline(cin, file);
  return file;
}

// Displays the stats of a file.
void displayFileStats(string file) {
  struct stat buf;
  stat(file.c_str(), &buf);
  cout << file << ", " << buf.st_size << " bytes, last modified: " << ctime(&buf.st_mtime);
}

// Message to display if a file doesn't exist.
void displayFileNotExist(string file) {
  cout << file << " does not exist";
}

// init function for FileToSearch.
int main() {
  string fileToSearch = getFileToSearch();

  if (fileExists(fileToSearch)) {
    displayFileStats(fileToSearch);
  } else {
    displayFileNotExist(fileToSearch);
  }

  return 0;
}
