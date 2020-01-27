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
  std::map<int, int> Guard_Minutes;
  std::map<int, int> Most_Common_Minute;
  string line;
  std::string filename = "data.txt";
  ifstream myfile;
  string timestamps[1133];
  string current;
  int out;
  int Current_Guard;
  int max_guard;
  int max_time;
  int time_sleep;
  int time_awake;
  int time_diff;
  int time_stamp_type;
  int index = 0;
  int i,j;

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
    
    if (time_stamp_type == 0){
      time_sleep = time(current);
    }
    else if (time_stamp_type == 1){
      time_awake = time(current);
      time_diff = time_awake - time_sleep;
      if (Guard_Minutes.count(Current_Guard)){
        Guard_Minutes[Current_Guard] += time_diff;
      }
      else {
        Guard_Minutes[Current_Guard] = time_diff;        
      }
    }
    else {
      Current_Guard = Guard(current);
    }
  }

  auto x = std::max_element(Guard_Minutes.begin(), Guard_Minutes.end(),
    [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second; });
  
  max_guard = x->first;

  for (i = 0; i < 1133; i++){
    current = timestamps[i];
    time_stamp_type = time_type(current);

    if (time_stamp_type == 2){
      Current_Guard = Guard(current);
    }
    else if (Current_Guard == max_guard){
    
      if (time_stamp_type == 0){
        time_sleep = time(current);
      }
      else if (time_stamp_type == 1){
        time_awake = time(current);
        for (j=time_sleep; j <= time_awake; j++){
          if (Most_Common_Minute.count(j)){
            Most_Common_Minute[j] ++;
        }
        else {
          Most_Common_Minute[j] = 1;        
          }
        }
      }
    }
  }

  x = std::max_element(Most_Common_Minute.begin(), Most_Common_Minute.end(),
    [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second; });

  max_time = x->first;

  out = max_time*max_guard;


  printf("Answer, Part 1: %d\n", out);
  return 0;
}