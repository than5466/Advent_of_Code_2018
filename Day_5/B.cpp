#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
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
  string line, s;
  int len;
  int min_len = 100000;
  std::string filename = "data.txt";
  ifstream myfile;

  myfile.open(filename);
  while (getline (myfile,line) ){
    break;
  }

  myfile.close();

  char lower = 'a';
  char capital = 'A';

  for (int i = 0; i<26;i++){
    s = line;
    s.erase(std::remove(s.begin(), s.end(), lower), s.end());
    s.erase(std::remove(s.begin(), s.end(), capital), s.end());
    lower ++;
    capital ++;
    while (1){
      len = s.length();
      s = parse(s);
      if (s.length()==len){
        if (len < min_len){
          min_len = len;
        }
        break;
      }

    }
  }
  printf("%d\n",min_len);
  return 0;
}