#include<bits/stdc++.h>

using namespace std;

void fun(vector<long long> &a){
    int n = a.size();
    long long q = (1<<18)-1;
    long long p[n];
    p[0] = 1;

    for(size_t i =1; i<n; i++){
        p[i] = (p[i-1] * 2) % q;
    }

    for(size_t i = 0; i< n; i++){
         
        if(i == 0)cout<<(char)(((a[i]/p[i]) + int('a'))%q);
        if(i>0){
            cout<<(char)((((a[i] - a[i-1])/p[i])+int('a'))%q);
        }
    }
    


}



int main(){
    int x; cin>>x;

    vector<long long> a;

    for(int i =0; i<x; i++){
        long long s; cin>>s;
        a.push_back(s);
    }

    fun(a);


}