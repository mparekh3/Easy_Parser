  
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <vector>



using namespace std;
class RXEng {
 public:
  string source;

  bool CheckKeyWord(string s) {
    fstream key;
    string word;
    smatch m;
    key.open("KeyWords.txt");

    while (key >> word) {
      regex e(word);
      return regex_search(s, m, e);
    }
    return false;
  }

  bool CheckintCont(string s) {
    smatch m;
    regex e("-?[\\d]+");
    return regex_match(s, m, e);
  }

  bool CheckfloatCont(string s) {
    regex e("-?[\\d]+\\.[\\d]{1,8}");
    return regex_match(s,e);
  }
  bool CheckSpecialChar(string s) {
    smatch m;
    regex e("[^a-zA-Z0-9]+");
    return regex_search(s, m, e);
  }
  bool CheckWhiteSpace(string s) {
    smatch m;
    regex e("[\\t\\r\\n]+");
    return regex_search(s, m, e);
  }
};

int main() {
  string fileName = "TestFile.cpp";
  fstream input;
  input.open(fileName.c_str());
  string word;
  map<string, vector<string> > token;
  RXEng r;
  while (input >> word) {
    if (r.CheckKeyWord(word)) {
      token["KeyWords"].push_back(word);
   
    } else if (r.CheckintCont(word)) {
      token["IntConts"].push_back(word);
    } else if (r.CheckfloatCont(word)) {
      token["floatConts"].push_back(word);
   } else if (r.CheckSpecialChar(word)) {
      token["spec"].push_back(word);
      
    }
    
  }
  for (map<string, vector<string> >::const_iterator ptr = token.begin();
       ptr != token.end(); ptr++) {
    cout << ptr->first << ": ";
    for (vector<string>::const_iterator eptr = ptr->second.begin();
         eptr != ptr->second.end(); eptr++)
      cout << *eptr << " ";
    cout << endl;
  }
}
