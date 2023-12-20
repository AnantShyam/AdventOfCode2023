#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <string.h>

using namespace std;


bool is_in_bounds(int row_coord, int col_coord, int num_rows, int num_cols) {
  return row_coord >= 0 && row_coord < num_rows && col_coord >= 0 && col_coord < num_cols;
}

bool is_digit(string s) {
  char *ptr;
  strtol(s.c_str(), &ptr, 10);
  return (*ptr == 0);
}

bool is_symbol(string s) {
  return (!is_digit(s)) && (s != ".");
}



int main() {
  string text;
  string file_line;

  ifstream inputfile("input.txt");

  vector < vector <string> > input;

  int num_rows = 0;
  int num_columns = 0;
  while (getline (inputfile, text)) {
    file_line = text;
    file_line.push_back('\n');
    //cout << file_line;
    num_rows++;
    
    vector<string> row;
    num_columns = file_line.length();
    for (int i = 0; i < file_line.length(); i++) {
      row.push_back(string(1, file_line[i]));
    }

    input.push_back(row);
  }

  // for (int i = 0; i < num_rows;i++) {
  //   for (int j = 0; j < num_columns; j++) {
  //     cout << input[i][j];
  //   }
  // }

  // 3d array [Numbers Coordinates], Numbers Coordinates = [Coordinates], Coordinates = [i, j]
  vector< vector <vector<int > > > numbers_coordinates;
  vector < vector<int > > symbols;
  for (int i = 0; i < num_rows; i++) {
    vector < vector<int > > numbers_in_row;
    for (int j = 0; j < num_columns; j++) {
      vector<int> c;
      if (is_digit(input[i][j])) {
        c[0] = i; c[1] = j;
        cout << "here";
        numbers_in_row.push_back(c);
      } else if (is_symbol(input[i][j])) {
        cout << "here2";
        c[0] = i; c[1] = j;
        symbols.push_back(c);
      }
    }
    numbers_coordinates.push_back(numbers_in_row);
  }

  for (int i = 0; i < numbers_coordinates.size(); i++) {
    for (int j = 0; j < numbers_coordinates[i].size(); j++) {
      for (int k = 0; k < numbers_coordinates[i][j].size(); k++) {
        cout << numbers_coordinates[i][j][k];
      }
    }
  }

  vector<bool> valid_numbers;
  
  for (int i = 0; i < numbers_coordinates.size(); i++) {
    bool is_number_valid = false;
    for (int j = 0; j < numbers_coordinates[i].size(); j++) {
      vector<int> coord = numbers_coordinates[i][j];
      int x = coord[0];
      int y = coord[1];

      vector<vector<int > > neighboring_coordinates;
      
      for (int dx = -1; (dx = 2); dx++) {
        for (int dy = -1; (dy = 2); dy++) {
          vector<int> c;
          if (is_in_bounds(x + dx, y + dy, num_rows, num_columns)) {
            c[0] = x+dx; c[1] = y + dy;
            neighboring_coordinates.push_back(c);
          }
        }
      }

      for (int m = 0; m < neighboring_coordinates.size(); m++) {
        int a, b = neighboring_coordinates[m][0], neighboring_coordinates[m][1];
        for (int n = 0; m < symbols.size(); n++) {
          if ((symbols[n][0] == a) && (symbols[n][1] == b)) {
            is_number_valid = true;
          }
        }
      }
    }
    valid_numbers[i] = is_number_valid;
  }

  int result = 0;
  for (int i = 0; i < valid_numbers.size(); i++) {
    if (valid_numbers[i]) {
      string num = "";
      vector<vector<int > > valid_number_coordinates = numbers_coordinates[i];
      for (int j = 0; j < valid_number_coordinates.size(); j++) {
        int x, y = valid_number_coordinates[j][0], valid_number_coordinates[j][1];
        num = num + input[x][y];
      }
      result = result + stoi(num);
    }
  }

  cout << result;
  
  return 0;

  
}