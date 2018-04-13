#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <map>
using namespace std;

list <string> lst;
int main(int argc, char **argv)
{
  ifstream file(argv[1]);

  // Read data
  while (!file.eof()) {
    string word, nopunct="";
    file >> word;
    
    for(auto &c : word) { // Remove Punctuation      
      if (isalpha(c)) {
        nopunct +=c;       
      }
    }
    lst.push_back(nopunct);
  }

  map<string, vector<string>> wordmap;
  string state = "";
  for(list<string>::iterator it=lst.begin(); it !=lst.end(); it++) {
    wordmap[state].push_back(*it);
    state = *it;
  }
  
  srand(time(NULL)); // this line initializes the random number generated
                     // so you dont get the same thing every time
  state = "";
  for (int i = 0; i < 100; i++) {
    int ind = rand() % wordmap[state].size();
    cout << wordmap[state][ind] << " ";
    state = wordmap[state][ind];
  }
  cout << endl;
  cout << endl;
}
