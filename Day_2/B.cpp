#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

bool one_differ(string s1, string s2){
  int i = s1.length();
  int differ = 0;

  for (int j = 0; j < i; j++){
    if (s1[j] != s2[j]){
      differ ++;
    }
  }
  if (differ == 1){
    return true;
  }
  return false;
}

string resulting_str(string s1, string s2){
  int i = 0;
  int len = s1.length();
  string out;
  for (int j = 0; j < len; j++){
    if (s1[j]==s2[j]){
      out += s1[j];
      i++;
    }
  }
  return out;
}

int main () {
  std::string ans = "";
  int size = 0;
  int i = 0;
  string line;
  std::string filename = "data.txt";
  ifstream myfile;

  myfile.open(filename);
  while (getline (myfile,line)){
    size ++;
  }
  myfile.close();

  std::string s[size];

  myfile.open(filename);
  while (getline (myfile,line)){
    s[i] = line;
    i ++;
  }
  myfile.close();

  for (i = 0; i < size-1; i++){
    for (int j = i+1; j < size; j++){
      if (one_differ(s[i],s[j])){
        ans = resulting_str(s[i],s[j]);
        goto END;
      }
    }
  }

  END:
  printf("Answer, Part 1: ");
  printf("%s\n", ans.c_str());
  return 0;
}