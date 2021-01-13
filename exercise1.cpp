#include <iostream>
#include <fstream>
#include <sys/stat.h>

int main() {
  std::string filename;
  std::cout << "Filename to check: ";
  getline(std::cin, filename);

  std::fstream fileStream;
  fileStream.open(filename);
  if (fileStream) {
    struct stat file;
    stat(&filename[0], &file); // Stores file stats in file

    char lastModifiedDate [30]; // String buffer for storing readable datetime
    // Format the instant into a readable date and time
    strftime(lastModifiedDate, 30, "%a %b %d %H:%M:%S %Y", localtime(&file.st_mtime));

    std::cout << filename << ", " << file.st_size << " bytes, last modified: " << lastModifiedDate << std::endl;
  } else {
    std::cout << filename << " does not exist\n";
  }
}
