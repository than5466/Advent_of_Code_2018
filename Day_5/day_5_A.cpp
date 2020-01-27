#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <map>

using namespace std;

string removeSubstrs(string s, string p) { 
  string::size_type n = p.length();
  for (string::size_type i = s.find(p);
      i != string::npos;
      i = s.find(p))
      s.erase(i, n);
  return s;
}

string parse(string s){
  char small = 'a';
  char capital = 'A';
  string p,q;
  while (small <= 'z'){
    p = capital;
    p += small;
    q = small;
    q += capital;
  
    s = removeSubstrs(s, q);
    s = removeSubstrs(s, p);
    small ++;
    capital ++;
  }
  return s;
}


int main () {
  string line;
  int len;
  std::string filename = "data.txt";
  ifstream myfile;

  myfile.open(filename);
  while (getline (myfile,line) ){
    break;
  }

  myfile.close();

  while (1){
    len = line.length();
    line = parse(line);
    if (line.length()==len){
      break;
    }
  }
  len = line.length();
  printf("%d\n",len);
  return 0;
}