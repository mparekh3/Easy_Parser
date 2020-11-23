#include <fstream>
#include <iostream>
#include <regex>
#include <string>
using namespace std;
class Compiler {
 private:
  string source;

 public:
  void foundIdentifier(uint32_t start, uint32_t end);
  void foundIntConst(uint32_t start, uint32_t end);
  void foundLongConst(uint32_t start, uint32_t end);
};
class RXEng {
 public:
  bool CheckKeyWord(string s) {
    fstream key;
    string word;
    bool match;
    key.open("KeyWords.txt");
    while (key >> word) {
      regex e(word);
      match = regex_match(s, e);
      if (match) return match;
    }
    return false;
  }
  string identifier(string s) {
    regex r("[a-zA-Z_][a-zA-Z_0-9]*");
    regex_token_iterator<string::iterator> rend;
    regex_token_iterator<string::iterator> a(s.begin(), s.end(), r);
    while (!(a == rend)) {
      return a->str();
    }
  }
};

int main() {
  string fileName;
  cout << "Enter File Name:";
  cin >> fileName;
  fstream input;
  input.open(fileName);
  if (input.is_open())
    cout << "file is open." << endl;
  else {
    cout << "file not found." << endl;
    return 1;
  }
  RXEng r;
  int x = 0;
  while (!input.eof()) {
    string temp;
    input >> temp;

    /* Identifier is not working completly */
    if (r.CheckKeyWord(temp)) {
      cout << "KeyWords: " << temp << '\n';
      x++;
    }
    string temp2 = r.identifier(temp);
    if (temp2.length() != 0 && temp2 != temp) {
      cout << "Identifier:" << temp2 << endl;
    }
  }
  cout << "Total " << x << " KeyWords Found in file.\n";
}
