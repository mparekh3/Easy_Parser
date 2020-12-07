#include <fstream>
#include <iostream>
#include <regex>
#include <string>
using namespace std;
class Compiler {
 private:
  string source;

 public:
  void foundIdentifier(uint32_t start, uint32_t end) {}
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
  bool CheckintCont(string s) {
    fstream key;
    string word = "-?[\\d]+";
    bool match;
    regex e(word);
    match = regex_match(s, e);
    if (match) return match;

    return false;
  }
  bool CheckfloatCont(string s) {
    fstream key;
    string word = "-?[\\d]+\\.[\\d]{1,8}";
    bool match;
    regex e(word);
    match = regex_match(s, e);
    if (match) return match;

    return false;
  }
  bool CheckWhiteSpace(string s) {
    fstream key;
    string word = "([ \\ t \\ r \\n] +)";
    bool match;
    regex e(word);
    match = regex_match(s, e);
    if (match) return match;
  }
};
int main() {
  string fileName;
  cout << "Enter File Name:";
  cin >> fileName;
  fstream input;

  input.open(fileName);
  string b;
  getline(input, b, '\0');
  if (input.is_open())
    cout << "file is open." << endl;
  else {
    cout << "file not found." << endl;
    return 1;
  }
  RXEng r;

  int x = 0;
  if (r.CheckWhiteSpace(b)) cout << "found white space" << endl;
  /*  while(!input.eof()){
       string temp;
       input>>temp;

       if(r.CheckKeyWord(temp)){
           cout<<"KeyWord:"<<temp<<'\n';
           x++;
       }
       else if(r.CheckintCont(temp)){
           cout<<"intCon:"<<temp<<'\n';

       }
        else if(r.CheckfloatCont(temp)){
           cout<<"floatCon:"<<temp<<'\n';

       }
   }
  int start = 0;
  int end = sizeof(b) * sizeof(string);
  for (int i = start; i <= sizeof(b) * sizeof(string); i++) {
    if (b[i] == r.ch) }
}
}*/
}
