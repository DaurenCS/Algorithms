#include<bits/stdc++.h>

using namespace std;

void f(string s){
    size_t n =s.size();
    vector<size_t> v(n);

    v[0] = 0;

    for(size_t i =1; i<n; i++){
        size_t j = v[i-1];
        while(j>0 && s[i]!= s[j]){
            j = v[j-1];
        }

        if(s[i]==s[j]){
            v[i] = j+1;
        }
    }


    cout<<v.size()-v.back();
}

int main(){
    string s; cin>>s;
    f(s);
}