#include <iostream>
#include <fstream>

// Outputs each line of a file numbered and on a separate line
// followed by the number of lines in the file
void printLines(std::string filename) {
  std::string line;
  int counter = 1;
  std::ifstream myfile(filename);
  if (myfile.is_open()) {
    while(getline(myfile, line)) {
      std::cout << counter++ << ": " << line << '\n';
    }
    myfile.close();
    std::cout << "Total number of lines read: " << --counter;
  }
}

int main() {
  std::string filename;
  std::cout << "Please enter a valid filename: ";
  getline(std::cin, filename);

  std::fstream fileStream;
  fileStream.open(filename);
  if (fileStream) {
    printLines(filename);
  } else {
    std::cout << "Sorry, '" <<filename << "' does not exist.\n";
    main();
  }
  return 0;
}
