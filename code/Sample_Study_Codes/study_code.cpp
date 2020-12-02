#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main() {
  const string path = "text.txt";
  ifstream input(path.c_str());
  if (!input) {
    cout << "Error opening file." << endl;
    return 0;
  }
  multimap<string, int, less<string> > words;
  int line;
  string word;
  // For each line of text
  for (line = 1; input; line++) {
    char buf[256];
    input.getline(buf, 128);
    // Discard all punctuation characters, leaving only words
    for (char *p = buf; *p != '\0'; p++) {
      if (!isalpha(*p)) *p = ' ';
    }
    istringstream i(buf);
    while (i) {
      i >> word;
      if (word != "") {
        words.insert(pair<const string, int>(word, line));
      }
    }
  }

  input.close();
  // Output results
  multimap<string, int, less<string> >::iterator it1;
  multimap<string, int, less<string> >::iterator it2;

  for (it1 = words.begin(); it1 != words.end();) {
    it2 = words.upper_bound((*it1).first);

    cout << (*it1).first << " : ";

    for (; it1 != it2; it1++) {
      cout << (*it1).second << " ";
    }
    cout << endl;
  }

  return 0;
}
