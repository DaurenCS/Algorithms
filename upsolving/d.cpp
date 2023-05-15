#include<bits/stdc++.h>

using namespace std;

bool isPrime(int x){
    int cnt = 0;
    for(int i = 2; i*i<=x; i++){
        if(x%i==0)cnt++;
    }
    if(cnt!=0)return false;
    return true;
}

int count(int n){
    int i = 2;
    set <int> st;
    while(n > 1){
        if(n%i==0){
            n /= i;
            st.insert(i);
        }
        else{
            i++;
        }
    }
    return st.size();
}

int main(){
    int x; cin>>x;
    cout<<count(x);
}