#include <fstream>
#include <iostream>
#include <regex>
#include <string>

#include "comment.h"
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
 private:
  // string source;

 public:
  string source;

  bool CheckKeyWord(uint32_t start, uint32_t end) {
    fstream key;
    string word;
    string s = source.substr(start, end);
    bool match;
    key.open("KeyWords.txt");

    while (key >> word) {
      regex e(word);
      match = regex_match(s, e);
      if (match) return match;
    }
    return false;
  }
  bool CheckintCont(uint32_t start, uint32_t end) {
    fstream key;
    string word = "-?[\\d]+";
    string s = source.substr(start, end);
    bool match;
    regex e(word);
    match = regex_match(s, e);
    if (match) return match;

    return false;
  }
  bool CheckfloatCont(uint32_t start, uint32_t end) {
    fstream key;
    string word = "-?[\\d]+\\.[\\d]{1,8}";
    string s = source.substr(start, end);
    bool match;
    regex e(word);
    match = regex_match(s, e);
    if (match) return match;

    return false;
  }

  bool CheckWhiteSpace(uint32_t start, uint32_t end) {
    fstream key;
    string word = "([ \\ t \\ r \\n] +)";
    string s = source.substr(start, end);
    bool match;
    regex e(word);
    match = regex_match(s, e);
    if (match) return match;
    return false;
  }
};

int main() {
  string fileName = "TestFile.cpp";
  // cout << "Enter File Name:";
  // cin >> fileName;
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
  uint32_t start = 0;
  uint32_t end = 1;
  bool a;
  r.source = b;
  for (int i = 0; i <= sizeof(b) * sizeof(string); i++) {
    if (a = r.CheckWhiteSpace(start, end)) {
      start++;
      end++;
    }
    while (!r.CheckWhiteSpace(start, end)) {
      end++;
    }
    if (r.CheckKeyWord(start, end)) {
      if (b.substr(start, end) == "include") {
        while (r.CheckWhiteSpace(start, end)) {
          start++;
          end++;
        }
        while (!r.CheckWhiteSpace(start, end)) {
          end++;
        }
        if (b.substr(start, end) == "<") {
          continue;
        } else
          throw("Wrong harder")
      }
    } else {
      throw("error at position:", start);
    }
    if (r.CheckKeyWord() == "int") {
      while (!r.CheckWhiteSpace(start, end)) {
        start++;
        end++;
      }
      if (b.substr(start, end) == "main") {
        search(b[start]);
        search(b[end]);
        if (paren == 0) {
          start++;
          end++;
        }
        search(b[start]);

        if (brace == 1) {
          if (r.CheckfloatCont(start, end)) {
            start++;
            end++;
            /*
             if conditions for next token
            */
          }
          if (r.CheckintCont(start, end)) {
            start++;
            end++;
            /*
           if conditions for next token
           */
          }
          if (r.CheckKeyWord(start, end)) {
            start++;
            end++;
            /*
           if conditions for next token
           */
          }
        }
      }
    }
  }
}
