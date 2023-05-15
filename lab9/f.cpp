#include<bits/stdc++.h>

using namespace std;

vector<size_t> f(string s){
    size_t n =s.size();
    vector<size_t> v(n);

    v[0] = 0;

    for(size_t i = 1; i<n; i++){
        size_t j = v[i-1];

        while(j> 0 && s[i]!= s[j]){
            j = v[j-1];
        }
        if(s[i] == s[j]){
            v[i] = j+1;
        }
    }
    return v;
}

int main(){
    string a,b;
    cin>>a>>b;
    string res = b + "#" + a;

    vector<size_t> v = f(res);

    // for(auto x : v){
    //     cout<<x<<" ";
    // }
    // return 0;
    
    int cnt =0;

    for(int i =0; i< v.size(); i++){
        if(v[i] == b.size()){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    for(int i =0; i< v.size(); i++){
        if(v[i] == b.size()){
            cout<<i- (b.size()*2) +1<<" ";
        }
    }
}