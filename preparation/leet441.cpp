#include<bits/stdc++.h>

using namespace std;

int bin(int x){
    int l = 1; 
    int r = x;
    int res = 0;
    while( l <= r){
        int mid = l + (r - l)/2;
        int coin = (mid/2)*(mid + 1);
        if(coin > x){
            r = mid - 1;
        }
        else{
            l = mid + 1;
            res = max(mid, res);
        }
    }
    return res;    

}

int main(){
    int x; cin>>x;
    cout<< bin(x);
}