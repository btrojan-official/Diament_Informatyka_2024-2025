#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int k;
	
	cin >> n >> k;
	
	string squares;
	int flips[n];
	
	cin >> squares;
	
	for(int i=0;i<k;i++){
		flips[i] = 0;
	}
	
	int counter = 0;
	int current_rotations = 0;

	for(int i=0;i<n;i++){
		current_rotations -= flips[i];
		
		if((squares[i] == 'b' && current_rotations%2 != 1) || (squares[i] == 'w' && current_rotations%2 == 1)){
			if(i>n-k){
				counter = -1;
				break;
			}
			current_rotations += 1;
			flips[i+k] = -1;
			counter++;
		}else{
			flips[i+k] = 0;
		}
	}
	
	cout << counter;

	return 0;
}
