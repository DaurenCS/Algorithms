#include<bits/stdc++.h>

using namespace std;

int main(){

    int x; cin>>x;
    vector<string> a;


    for(int i =0; i<x+1; i++){
        string s; getline(cin, s);
        a.push_back(s);
    }
    for(int i =0; i<a.size(); i++){
        cout<<a[i]<<endl;
    }
    
}