#include <bits/stdc++.h>
using namespace std;

char garden[101][101];
bool garden_paths[101][101];
int n;

int x_solution, y_solution;

void go_through_garden_1(int x, int y, int direction){
    if(x<0 || y<0 || y>=n || x>=n) return;
    garden_paths[y][x] = true;
    if(garden[y][x]=='.'){
        if(direction == 0) go_through_garden_1(x, y-1, direction);
        if(direction == 1) go_through_garden_1(x+1, y, direction);
        if(direction == 2) go_through_garden_1(x, y+1, direction);
        if(direction == 3) go_through_garden_1(x-1, y, direction);
    }
    else if(garden[y][x]=='/'){
        if(direction == 0) go_through_garden_1(x+1, y, 1);
        if(direction == 1) go_through_garden_1(x, y-1, 0);
        if(direction == 2) go_through_garden_1(x-1, y, 3);
        if(direction == 3) go_through_garden_1(x, y+1, 2);
    }
    else if(garden[y][x]=='\\'){
        if(direction == 0) go_through_garden_1(x-1, y, 3);
        if(direction == 1) go_through_garden_1(x, y+1, 2);
        if(direction == 2) go_through_garden_1(x+1, y, 1);
        if(direction == 3) go_through_garden_1(x, y-1, 0);
    }
}

bool go_through_garden_2(int x, int y, int direction){
    if(x<0 || y<0 || y>=n || x>=n) return false;
    if(garden_paths[y][x] == true){
            x_solution = x;
            y_solution = y;
        return true;
    }

    if(garden[y][x]=='.'){
        if(direction == 0) go_through_garden_2(x, y-1, direction);
        if(direction == 1) go_through_garden_2(x+1, y, direction);
        if(direction == 2) go_through_garden_2(x, y+1, direction);
        if(direction == 3) go_through_garden_2(x-1, y, direction);
    }
    else if(garden[y][x]=='/'){
        if(direction == 0) go_through_garden_2(x+1, y, 1);
        if(direction == 1) go_through_garden_2(x, y-1, 0);
        if(direction == 2) go_through_garden_2(x-1, y, 3);
        if(direction == 3) go_through_garden_2(x, y+1, 2);
    }
    else if(garden[y][x]=='\\'){
        if(direction == 0) go_through_garden_2(x-1, y, 3);
        if(direction == 1) go_through_garden_2(x, y+1, 2);
        if(direction == 2) go_through_garden_2(x+1, y, 1);
        if(direction == 3) go_through_garden_2(x, y-1, 0);
    }
}

int main(){
    cin >> n;

    vector<int> mirrors_x;
    vector<int> mirrors_y;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> garden[i][j];
            garden_paths[i][j] = false;

            if(garden[i][j]!='.'){
                mirrors_x.push_back(j);
                mirrors_y.push_back(i);
            }
        }
    }

    for(int i=0;i<mirrors_x.size();i++){
        char temp = garden[mirrors_y[i]][mirrors_x[i]];
        garden[mirrors_y[i]][mirrors_x[i]] = '.';

        go_through_garden_1(0, 0, 2);
        bool did_found = go_through_garden_2(n-1, n-1, 0);

        if(did_found){
            cout << mirrors_x[i] << " " << mirrors_y[i] << "\n";
            cout << x_solution << " " << y_solution << "\n";
            return 0;
        }
        else{
            garden[mirrors_y[i]][mirrors_x[i]] = temp;
        }
    }

    go_through_garden_1(0, 0, 2);
    bool did_found = go_through_garden_2(n-1, n-1, 0);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << garden[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
