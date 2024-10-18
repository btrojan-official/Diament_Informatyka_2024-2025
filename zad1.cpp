#include <bits/stdc++.h>
using namespace std;

string island[501];
bool visited[501][501];

int n,m;

void take_a_walk(int i, int j){
	visited[i][j] = 1;
	
	if (j!=0 && visited[i][j-1] == 0 && island[i][j-1] == 'l') take_a_walk(i, j-1);
	if (j!=n-1 && visited[i][j+1] == 0 && island[i][j+1] == 'l') take_a_walk(i, j+1);
	if (i!=0 && visited[i-1][j] == 0 && island[i-1][j] == 'l') take_a_walk(i-1, j);
	if (i!=m-1 && visited[i+1][j] == 0 && island[i+1][j] == 'l') take_a_walk(i+1, j);
}

int main(){		
	cin >> m >> n;
	
	for(int i=0;i<m;i++){
		cin >> island[i];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			visited[m][n] = 0;
		}
	}
	
	for(int i=0;i<n;i++){
		if(visited[i][0] == 0 && island[i][0] == 'l') take_a_walk(i, 0);
		if(visited[i][n-1] == 0 && island[i][n-1] == 'l') take_a_walk(i, n-1);
	}
	
	for(int i=0;i<n;i++){
		if(visited[0][i] == 0 && island[0][i] == 'l') take_a_walk(0, i);
		if(visited[m-1][i] == 0 && island[m-1][i] == 'l') take_a_walk(m-1, i);
	}
	
	int counter = 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(visited[i][j]==0 && island[i][j]=='l') counter++;
		}
	}
	
	cout << counter;
	
	return 0;
}











