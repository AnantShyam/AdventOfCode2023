#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <string.h>

using namespace std;

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
        num_rows++;
        
        vector<string> row;
        num_columns = file_line.length();
        for (int i = 0; i < file_line.length(); i++) {
            row.push_back(string(1, file_line[i]));
        }
        input.push_back(row);
    }
    int result = 0;
    

    
    for (int i = 2; i < 3;i++) {
        vector<string> winning_cards;
        vector<string> player_cards;
        string acc = "";

        bool seperator_seen = false;
        for (int j = 0; j < num_columns; j++) {
            if (input[i][j] == " ") {
                //cout << "here1";
                if (seperator_seen) {
                    if (acc != "") {
                        player_cards.push_back(acc); acc = "";
                    }
                } else {
                    if (acc != "") {
                        winning_cards.push_back(acc); acc = "";
                    }
                }
            } else if (input[i][j] == "|") {
                seperator_seen = true;
            } else {
                acc = acc + input[i][j];
            }
        }

        vector<string> processed_win_cards;
        bool semicolon_not_seen = true;
        for (int j = 0; j < winning_cards.size(); j++) {
            if (winning_cards[j].substr(1) == ":") {
                semicolon_not_seen = false;
            } else {
                if (!semicolon_not_seen) {
                    processed_win_cards.push_back(winning_cards[j]);
                }
            }
            
        }


        int score = 0;
        for (int j = 0; j < player_cards.size(); j++) {
            string player_card = player_cards[j];
            for (int n = 0; n < processed_win_cards.size(); n++) {
                string win_card = processed_win_cards[n];
                if (player_card == win_card) {
                    score += 1;
                }
            }
        }
        cout << score;
        
        

    }
    //cout << result;
    return 0;
}