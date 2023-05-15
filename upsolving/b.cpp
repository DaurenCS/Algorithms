#include<bits/stdc++.h>

using namespace std;

bool isPrime(int x){
    int cnt = 0;
    for(int i = 2; i*i<= x; i++ ){
        if(x%i==0){
            cnt++;
        }
    }
    if(cnt != 0) return false;
    
    return true;
}


int main(){
    int x; cin>>x;
    
    

    for(int i = 2; i<= x/2; i++){
        if(isPrime(i)){
            if(isPrime(x-i)){
                cout<< i <<" "<< x-i;
                return 0;
            }
        }
    }
    
}

   
