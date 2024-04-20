#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_set>

using namespace std;


char** grid;
int row = 0;
int column = 0;
unordered_set<string> dictionary;


void load_grid(string file) {
  ifstream infile;
  infile.open(file);
  if(infile.fail()){
    cout<<"Opening file - failed." << endl;
    exit(1);
  }
  vector<string> v;
  string temp;
  while(getline(infile,temp)) {
    v.push_back(temp);
    row++;
  }
  column = (v[0].size() + 1) / 2;
  grid = new char*[row];
  for(int i = 0; i < row; i++){
    grid[i] = new char[column];
  }
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      grid[i][j] = v[i][2*j];
    }
  }
}

void load_words(string file) {
  ifstream infile;
  infile.open(file);
  if(infile.fail()){
    cout<<"Opening file - failed." << endl;
    exit(1);
  }
  string temp;
  while(getline(infile, temp)) {
    if(temp.length() >= 6) {
      dictionary.insert(temp);
    }
  }
}

string get_right(int row, int column, int length){
  string temp = "";
  for(int i = 0; i < length; i++){
    temp += grid[row][column + i];
  }
  return temp;
}

string get_left(int row, int column, int length){
  string temp = "";
  for(int i = 0; i < length; i++){
    temp += grid[row][column - i];
  }
  return temp;
}

string get_up(int row, int column, int length){
  string temp = "";
  for(int i = 0; i < length; i++){
    temp += grid[row - i][column];
  }
  return temp;
}

string get_down(int row, int column, int length){
  string temp = "";
  for(int i = 0; i < length; i++){
    temp += grid[row + i][column];
  }
  return temp;
}

string get_upper_right(int row, int column, int length){
  string temp = "";
  for(int i = 0; i < length; i++){
    temp += grid[row - i][column + i];
  }
  return temp;
}

string get_upper_left(int row, int column, int length){
  string temp = "";
  for(int i = 0; i < length; i++){
    temp += grid[row - i][column - i];
  }
  return temp;
}

string get_lower_right(int row, int column, int length){
  string temp = "";
  for(int i = 0; i < length; i++){
    temp += grid[row + i][column + i];
  }
  return temp;
}

string get_lower_left(int row, int column, int length){
  string temp = "";
  for(int i = 0; i < length; i++){
    temp += grid[row + i][column - i];
  }
  return temp;
}



bool search(string word, int rows, int columns) {
  int length = word.length();
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns; j++){
      if((j+length-1) < columns) {
        if(word == get_right(i,j,word.length())) {
          cout << word << " from (" << j << "," << i << ") to (" << to_string(j+word.length()-1) << "," << i << ")" << endl;
          return true;
        }
      }
      if((j-length+1) >= 0) {
        if(word == get_left(i,j,word.length())) {
          cout << word << " from (" << j << "," << i << ") to (" << to_string(j-word.length()+1) << "," << i << ")" << endl;
          return true;
        }
      }
      if((i+length-1) < rows) {
        if(word == get_down(i,j,word.length())) {
          cout << word << " from (" << j << "," << i << ") to (" << j << "," << to_string(i+word.length()-1) << ")" << endl;
          return true;
        }
      }
      if((i-length+1) >= 0) {
        if(word == get_up(i,j,word.length())) {
          cout << word << " from (" << j + "," << i << ") to (" << j << "," << to_string(i-word.length()+1) << ")" << endl;
          return true;
        }
      }
      if((j+length-1) < columns && (i+length-1) < rows) {
        if(word == get_lower_right(i,j,word.length())) {
          cout << word << " from (" << j << "," << i << ") to (" << to_string(j+word.length()-1) << "," << to_string(i+word.length()-1) << ")" << endl;
          return true;
        }
      }
      if((j-length+1) >= 0 && (i+length-1) < rows) {
        if(word == get_lower_left(i,j,word.length())) {
          cout << word << " from (" << j << "," << i << ") to (" << to_string(j-word.length()+1) << "," << to_string(i+word.length()-1) << ")" << endl;
          return true;
        }
      }
      if((j+length-1) < columns && (i-length+1) >= 0) {
        if(word == get_upper_right(i,j,word.length())) {
          cout << word << " from (" << j << "," << i << ") to (" << to_string(j+word.length()-1) << "," << to_string(i-word.length()+1) << ")" << endl;
          return true;
        }
      }
      if((j-length+1) >= 0 && (i-length+1) >= 0) {
        if(word == get_upper_left(i,j,word.length())) {
          cout << word << " from (" << j << "," << i << ") to (" << to_string(j-word.length()+1) << "," << to_string(i-word.length()+1) << ")" << endl;
          return true;
        }
      }
    }
  }
  return false;
}



int main() {
    load_grid("puzzle.txt");
    load_words("words.txt");
    cout << dictionary.size() << endl;
    for(string temp : dictionary) {
      search(temp,row,column);
    }
    return 0;
}
