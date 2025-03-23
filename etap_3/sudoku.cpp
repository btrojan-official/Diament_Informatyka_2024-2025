#include <bits/stdc++.h>
using namespace std;

int main(){
    int sudoku[9][9];

    for(int i=0;i<9i++){
        for (int j=0;j<9;j++){
            cin >> sudoku[i][j];
        }
    }

    bool was[9];
    for(int i=0;i<9;i++) was[i] = false;

    bool error[9];
    for(int i=0;i<9;i++) error[i] = false;

    for(int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            if(was[sudoku[i][j]]){
                if(i<3){
                    error[0] = true;
                    error[1] = true;
                    error[2] = true;
                }
                else if(i<6){
                    error[3] = true;
                    error[4] = true;
                    error[5] = true;
                }else{
                    error[6] = true;
                    error[7] = true;
                    error[8] = true;
                }
            }
            was[sudoku[i][j]] = true;
        }
        for(int i=0;i<9;i++) was[i] = false;
    }

    int first = -1;
    int second = -1;

    for(int j=0;j<9;j++){
        for (int i=0;i<9;i++){
            if(was[sudoku[i][j]]){
                if(j<3){
                    if(error[0] == true) {
                        if(first == -1) first = 0;
                        else if(first != 0){
                                second = 0;
                                cout << first << " " << second;
                        }
                    }
                    if(error[3] == true) {
                        if(first == -1) first = 3;
                        else if(first != 3){
                                second = 3
                                cout << first << " " << second;
                        }
                    }
                    if(error[6] == true) {
                        if(first == -1) first = 6;
                        else if(first != 6{
                                second = 6;
                                cout << first << " " << second;
                        }
                    }
                }
                else if(i<6){
                    if(error[1] == true) {
                        if(first == -1) first = 1;
                        else if(first != 1{
                                second = 1;
                                cout << first << " " << second;
                        }
                    }
                    if(error[4] == true) {
                        if(first == -1) first = 4;
                        else if(first != 4{
                                second = 4;
                                cout << first << " " << second;
                        }
                    }
                    if(error[7] == true) {
                        if(first == -1) first = 7;
                        else if(first != 7{
                                second = 7;
                                cout << first << " " << second;
                        }
                    }
                }else{
                    if(error[2] == true) {
                        if(first == -1) first = 2;
                        else if(first != 2{
                                second = 2;
                                cout << first << " " << second;
                        }
                    }
                    if(error[5] == true) {
                        if(first == -1) first = 5;
                        else if(first != 5{
                                second = 5;
                                cout << first << " " << second;
                        }
                    }
                    if(error[8] == true) {
                        if(first == -1) first = 8;
                        else if(first != 8{
                                second = 8;
                                cout << first << " " << second;
                        }
                    }
                }
            }
            was[sudoku[i][j]] = true;
        }
        for(int i=0;i<9;i++) was[i] = false;
    }

    return 0;
}
