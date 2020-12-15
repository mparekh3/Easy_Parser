#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <vector>

#include "comment.h"

using namespace std;
/*
class Compiler {
 private:
  string source;

 public:
  void foundIdentifier(uint32_t start, uint32_t end) {}
  void foundIntConst(uint32_t start, uint32_t end) {}
  void foundLongConst(uint32_t start, uint32_t end) {}
};
*/
class RXEng {
 private:
  // string source;

 public:
  string source;

  bool CheckKeyWord(uint32_t start, uint32_t end) {
    fstream key;
    string word;
    string s = source.substr(start, end);
    smatch m;
    key.open("KeyWords.txt");

    while (key >> word) {
      regex e(word);
      return regex_search(s, m, e);
    }
    return false;
  }

  bool CheckintCont(uint32_t start, uint32_t end) {
    string s = source.substr(start, end);
    smatch m;
    regex e("-?[\\d]+");
    return regex_search(s, m, e);
  }

  bool CheckfloatCont(uint32_t start, uint32_t end) {
    string s = source.substr(start, end);
    smatch m;
    regex e("-?[\\d]+\\.[\\d]{1,8}");
    return regex_search(s, m, e);
  }
  bool CheckSpecialChar(uint32_t start, uint32_t end) {
    string s = source.substr(start, end);
    smatch m;
    regex e("[^a-zA-Z0-9]+");
    return regex_search(s, m, e);
  }
  bool CheckWhiteSpace(uint32_t start, uint32_t end) {
    string s = source.substr(start, end);
    smatch m;
    regex e("[\\t\\r\\n]+");
    return regex_search(s, m, e);
  }
};

int main() {
  string fileName = "text.txt";
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

  // int i=0;
  // while(b[i]!='\0')
  RXEng r;
  int start = 0;
  int end = 1;
  int i = 0;
  string t;
  r.source = b;
  for (i; i <= b.length(); i++) {
    if (b[start] == ' ' || b[start] == '\n' || b[start] == '\t') {
      start++;
      end++;
      continue;
    }
    if (b[end] != ' ') {
      end++;
      continue;
    }
    break;
  }
  if (r.CheckSpecialChar(start, end)) {
    cout << "Special Char: " << b.substr(start, end) << endl;
  } else if (r.CheckKeyWord(start, end)) {
    cout << "Keyword" << b.substr(start, end) << endl;

  } else if (r.CheckintCont(start, end)) {
    cout << "IntConst" << b.substr(start, end) << endl;

  } else if (r.CheckintCont(start, end)) {
    cout << "IntConst" << b.substr(start, end) << endl;
  } else if (r.CheckfloatCont(start, end)) {
    cout << "FloatConst" << b.substr(start, end) << endl;
  }
  if (r.CheckKeyWord(start, end)) {
    cout << "keyword: " << b.substr(start, end) << endl;
  }
  if (r.CheckfloatCont(start, end)) {
    cout << "float cont: " << b.substr(start, end) << endl;
  }
  if (r.CheckintCont(start, end)) {
    cout << "Int cont: " << b.substr(start, end) << endl;
  }
  start = end;
  end++;
  for (int i = 0; i <= b.substr(start, end).length(); i++) {
    if (b[start] == ' ' || b[start] == '\n' || b[start] == '\t') {
      start++;
      end++;
      continue;
    }
    if (b[end] != ' ') {
      end++;
      continue;
    }
    break;
  }
  cout << b.substr(start, end);
}
