#include <fstream>
#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main() {
  fstream file;
  string s;
  smatch match;
  regex e("test");
  file.open("text.txt");
  int i = 0;
  while (file >> s) {
    if (regex_search(s, match, e)) {
      cout << s;
      cout << "match " << i << " (" << match[i] << ") ";
      cout << "at position " << match.position(i) << endl;
      i++;
    }
  }

  for (unsigned i = 0; i < match.size(); ++i) {
  }
  return 0;
}
