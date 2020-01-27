#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

bool count(string s, int n) {
  int before, after;
  char ch;
  while (s != ""){
    ch = s[0];
    before = s.length();
    s.erase(std::remove(s.begin(), s.end(), ch), s.end());
    after = s.length();

    if (before - after == n){
      return true;
    }
  }
  return false;
}

int main () {
  int ans;
  int doubles = 0;
  int triples = 0;
  string line;
  std::string filename = "data.txt";
  ifstream myfile;

  myfile.open(filename);
  while (getline (myfile,line)){
    if (count(line, 2)) {
      doubles++;
    }
    if (count(line, 3)){
      triples ++;
    }
  }
  myfile.close();

  ans = doubles * triples;
  
  printf("Answer, Part 1: ");
  printf("%i\n", ans);
  return 0;
}