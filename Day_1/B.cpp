#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

int main () {
  int len = 0;
  int i = 0;
  std::unordered_set<int> resulting_frequencies;
  int ans;
  string line,number;
  std::string filename = "data.txt";
  ifstream myfile;

  myfile.open (filename);
  while (getline (myfile,line) ){
    len ++;
  }
  myfile.close();

  int s[len];

  myfile.open(filename);
  while (getline (myfile,line)){
    number = line.substr(1);
    if (line.find("+")==0){
        ans = std::stoi(number);
      }
      else {
        ans = -std::stoi(number);
      }
    s[i] = ans;
    i++;
  }
  myfile.close();

  ans = 0;
  i = 0;
  while (1) {
    if (i == len){
      i = 0;
    }
    ans = ans + s[i];
    if (resulting_frequencies.count(ans)){
      break;
    }
    resulting_frequencies.insert(ans);
    i++;
    
  }
  printf("Answer, Part 2: ");
  printf("%i\n", ans);
  return 0;
}