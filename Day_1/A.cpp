#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int main () {
  int ans = 0;
  string line,number;
  std::string filename = "data.txt";
  ifstream myfile;
  myfile.open (filename);
  if (myfile.is_open())
  {
    while (getline (myfile,line) )
    {
      number = line.substr(1);
      if (line.find("+")==0){
        ans = ans + std::stoi(number);
      }
      else {
        ans = ans - std::stoi(number);
      }
    }
    myfile.close();
  }
  printf("Answer, Part 1: ");
  printf("%i\n", ans);
  return 0;
}