#include <bits/stdc++.h>
#include <algorithm>
#include <bits/types/FILE.h>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>


int state[3][3] {
    {0,0,0},
    {0,0,0},
    {0,0,0}
};


void printTable () {
    for (int i = 0; i < 3; i++) {
        std::cout << "|";
        for (int j = 0; j < 3; j++) {
            
            if(state[i][j] == 0) {
                std::cout << " |";
            } else if (state[i][j] == 1) {
                std::cout << "X|";
            } else if (state[i][j] == -1) {
                std::cout << "O|";
            }
        }
        std::cout << std::endl;
    }
}

int setCell (int position, bool player) {
    int x = (position / 3);
    int y = (position % 3);
    if (state[x][y] == 0) {
        if (player) {
            state[x][y] = 1;
        } else {
            state[x][y] = -1;
        }
        return 0;
    } else {
        return -1;
    }
}

bool check_for_free (int pos) {
    int x = ((pos) / 3);
    int y = ((pos) % 3); 

    if (state[x][y] ) return true;
    else             return false;
}

bool check_win () {
    // check for horizontal win
    for (int i = 0; i < 3; i++) {
        if (state[i][0] == state[i][1] && state[i][1] == state[i][2] && state[i][0] != 0) {
            return true;
        }
    }

    // check for vertical win
    for (int i = 0; i < 3; i++) {
        if (state[0][i] == state[1][i] && state[1][i] == state[2][i] && state[0][i] != 0) {
            return true;
        }
    }

    // check for diagonal win
    if (state[0][0] == state[1][1] && state[1][1] == state[2][2] && state[0][0] != 0) {
        return true;
    }

    if (state[0][2] == state[1][1] && state[1][1] == state[2][0] && state[0][2] != 0) {
        return true;
    }

    return false;
}
bool check_draw () {
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            if (state[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}



int AiPosition() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 8);
    return dis(gen); 
}
int main (int argc, char *argv[]) {

    bool player = 0;
    while(true) {
        int position;
        // clear the screen 

        if (check_draw()) {
            std::cout << "Draw" << std::endl;
            break;
        }

        system("clear");
        printTable();

        while (true) {
            if(!player) {
                std::cout << "Enter position: ";
                std::cin >> position;   
            } else {
                // position = 8;
                position = AiPosition();
            }

            if (position > 0 && position <=9) {
                // use the function check for free to check if the cell is free and place the value
                if (check_for_free(position-1)) {
                    std::cout << "Position already filled" << std::endl;

                } else {
                    setCell(position -1, player);
                    break;
                }

            } else {
                std::cout << "Invalid position" << std::endl;
            }

        }


        if (check_win()) {
            if (player) {
                std::cout << "AI won" << std::endl;

            } else {
                std::cout << "Player won" << std::endl;
            }
            break;
        }
        if(player) {
            player = 0;
        } else {
            player = 1;
        }
    }


    printTable();
    return 0;
}
