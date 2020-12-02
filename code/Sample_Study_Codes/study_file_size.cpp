#include <fstream>
#include <iostream>
using namespace std;
int main() {
  ifstream in_file("text.txt", ios::binary);
  in_file.seekg(0, ios::end);
  int file_size = in_file.tellg();
  cout << "Size of the file is"
       << " " << file_size << " "
       << "bytes";
  
}
