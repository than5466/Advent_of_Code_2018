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

bool no_overlap(int first_start, int first_end, int second_start, int second_end){
  if (first_start > second_end){
    return true;
  }
  else if (first_end < second_start){
    return true;
  }
  return false;
}

int main () {
  unordered_set<int> duplicates;
  string line;
  int lst[1293][4];
  std::string filename = "data.txt";
  ifstream myfile;
  int start_x, start_y, delta_x, delta_y;
  int id = 0;
  bool overlapping;

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
    lst[id][0]=start_x;
    lst[id][1]=start_x+delta_x-1;
    lst[id][2]=start_y;
    lst[id][3]=start_y+delta_y-1;
    id ++;
  }

  for (id = 0; id <1293; id++){
    overlapping = false;
    for (int j = id + 1; j < 1293; j++){
      if (duplicates.count(id)){
        overlapping = true;
      }
      if (!(no_overlap(lst[id][0],lst[id][1],lst[j][0],lst[j][1]) || no_overlap(lst[id][2],lst[id][3],lst[j][2],lst[j][3]))){
        overlapping = true;
        duplicates.insert(id);
        duplicates.insert(j);
      }
    }

    if (!overlapping){
      id ++;
      break;
    }
    
  }

  myfile.close();

  printf("Answer, Part 1: %i\n", id);
  return 0;
}