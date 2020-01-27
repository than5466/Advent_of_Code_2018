#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <map>

using namespace std;

int time(string s) {
  return std::stoi(s.substr(15,17));
}

int time_type(string s){
  if (s[19] == 'f')
    return 0;
  else if (s[19] == 'w')
    return 1;
  else
    return 2;
}

int Guard(string s){
  return std::stoi(s.substr(26,30));
}

int main () {
  std::map<int, std::map<int,int>> Most_Common_Minute;
  string line;
  std::string filename = "data.txt";
  ifstream myfile;
  string timestamps[1133];
  string current;
  int out;
  int Current_Guard;
  int time_sleep;
  int time_awake;
  int time_stamp_type;
  int index = 0;
  int i,j;
  int max_guard = 0;
  int max_minute = 0;
  int no_max_minutes = 0;

  myfile.open(filename);
  while (getline (myfile,line)){
    timestamps[index] = line;
    index++;
  }
  myfile.close();
  sort(timestamps,timestamps+1133);

  for (i = 0; i < 1133; i++){
    current = timestamps[i];
    time_stamp_type = time_type(current);

    if (time_stamp_type == 2){
      Current_Guard = Guard(current);
    }
    else if (time_stamp_type == 0){
      time_sleep = time(current);
    }
    else if (time_stamp_type == 1){
      time_awake = time(current);
      for (j=time_sleep; j <= time_awake; j++){
        if (Most_Common_Minute[Current_Guard].count(j)){
          Most_Common_Minute[Current_Guard][j] ++;
      }
      else {
        Most_Common_Minute[Current_Guard][j] = 1;        
        }
      }
    }
  }

  for (auto const& x : Most_Common_Minute){
    auto y = std::max_element(x.second.begin(), x.second.end(),
      [](const pair<int, int>& p1, const pair<int, int>& p2) {
          return p1.second < p2.second; });
    if (y->second > no_max_minutes){
      no_max_minutes = y->second;
      max_guard = x.first;
      max_minute =y->first;

    }
  }
  out = max_guard*max_minute;
  
  printf("Answer, Part 1: %d\n", out);
  return 0;
}