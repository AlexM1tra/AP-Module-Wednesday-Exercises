#include <iostream>
#include <fstream>

// Checks whether all characters of a string are letters or spaces
bool isAllAlpha(std::string input) {
  for (char c : input) if (!isalpha(c) && !isspace(c)) return false;
  return true;
}

// Writes text to a new line of a file and returns an error code
// if something goes wrong
int writeToFile(std::string text) {
  try {
    std::ofstream myfile;
    myfile.open("list.csv", std::ios::out | std::ios::app);
    myfile << text << "\n";
    myfile.close();
    return 0;
  } catch (...) {
    return 1;
  }
}

// Runs the UI of the program
void run() {
  std::cout << "Enter name: ";
  std::string name;
  getline(std::cin, name);
  while (!isAllAlpha(name)) {
    std::cout << "Invalid name. Please enter a name containing only letters:\n";
    getline(std::cin, name);
  }
  std::cout << "Updating file...\n";
  if (writeToFile(name) != 0) {
    std::cout << "Unable to update file. Please try again.\n";
  }
  return;
}

// Asks the user if they would like to input another name
bool askAgain() {
  std::cout << "Add another (y/n)? ";
  std::string again;
  getline(std::cin, again);
  return toupper(again[0]) == 'Y';
}

int main() {
  bool again = true;
  while (again) {
    run();
    again = askAgain();
  }
}
