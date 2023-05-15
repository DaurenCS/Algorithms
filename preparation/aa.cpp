#include<bits/stdc++.h>

using namespace std;

int main(){
    	char a[8][8];
		for(int i = 0; i<8; i++) {
			for(int j = 0; j<8; j++ ) {
				if(i == 0) {
					a[i][j] = '*';
				}
                else
                    a[i][j]='1'; 
				
			}
		}
		
		for(int i = 0; i<8; i++) {
			for(int j = 0; j<8; j++ ) {
				cout<<a[i][j]<<" ";
				
				}
               cout<<endl; 
            }
				
			
}