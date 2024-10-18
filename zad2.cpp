#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int k;
	
	cin >> n >> k;
	
	string squares;
	int flips[n];
	
	cin >> squares;
	
	for(int i=0;i<n;i++){
		flips[i] = 0;
	}
	
	int counter = 0;

	for(int i=0;i<n;i++){
		cout << i << endl;
		if(i==0 && squares[i] == 'b'){ flips[i] = 1; counter++;}
		else if(i==0) continue;
		else if(i<k){
			if((squares[i] == 'b' && flips[i-1]%2!=1) || (squares[i] == 'w' && flips[i-1]%2==1)){
				if(flips[i-1] + 1 < 4) flips[i] = flips[i-1] + 1;
				else flips[i] = 0;
				counter++;
				
				if(i>(n-k)){
					counter = -1;
					break;
				}
			}else{
				flips[i] = flips[i-1];
			}
		}else{
			if((squares[i] == 'b' && (flips[i-1]-flips[i-k])%2!=1) || (squares[i] == 'w' && (flips[i-1]-flips[i-k])%2==1)){
				flips[i] = flips[i-1] + 1;
				counter++;
				
				if(i>(n-k)){
					counter = -1;
					break;
				}
				
			}else{
				flips[i] = flips[i-1];
			}
		}
	}
	
	cout << counter;

	return 0;
}
