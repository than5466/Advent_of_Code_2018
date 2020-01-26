#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

int get_sub_str(string s, char delim){
  std::string out;
  int i = 0;
  while (s[i] != delim){
    out += s[i];
    i++;
  }
  return std::stoi(out);
}

string update_str(string s, char delim){
  int i = 0;
  while (s[i] != delim){
    i ++;
  }
  return s.substr(i+1);
}

int main () {
  unordered_set<string> visited;
  unordered_set<string> counted;
  string line, s;
  std::string filename = "data.txt";
  ifstream myfile;
  int start_x, start_y, delta_x, delta_y;
  int out = 0;
  int k = 0;

  myfile.open(filename);
  while (getline (myfile,line)){
    line = update_str(line, ' ');
    line = update_str(line, ' ');
    start_x = get_sub_str(line, ',');
    line = update_str(line, ',');
    start_y = get_sub_str(line, ':');
    line = update_str(line, ' ');
    delta_x = get_sub_str(line, 'x');
    line = update_str(line, 'x');
    delta_y = std::stoi(line);

    for (int i = 0; i < delta_x; i++){
      for (int j = 0; j < delta_y; j++){
        s += std::to_string(start_x+i);
        s += ",";
        s += std::to_string(start_y+j);
        
        if (!counted.count(s)){
          if (visited.count(s)){
            out += 1;
            counted.insert(s);
            visited.erase(s);
          }
          else {
            visited.insert(s);

          }
        }
        s.clear();
      }
    }
  }
  myfile.close();

  printf("Answer, Part 1: %i\n", out);
  return 0;
}