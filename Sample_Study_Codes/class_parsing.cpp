#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

int main() {
    regex r( "class\\s+([a-zA-Z_][a-zA-Z0-9_]*)*\\s*:*\\s*((public|private) ([a-zA-Z_][a-zA-Z0-9_]*))*\\s*\\{");
    ifstream f("class.txt");
    char line[1000];
	int i=1;
    cmatch m;
          
    if(f.is_open()) {
        while (f) {
            f.getline(line,1000);
	    if (regex_search (line,m,r)) {
            		  cout <<i <<". CLASS_NAME_IS:  " <<m[1]<< "\t\t\t";
		if(m[4]=="")
			cout<<"Inheritance_Base_Name_Is: None"<<endl;
		else cout<<"Inheritance_Base_Name_Is: "<<m[4]<<endl;
		i++;
            }
        }
    }
}
