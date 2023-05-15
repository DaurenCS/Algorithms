#include<bits/stdc++.h>

using namespace std;

vector<size_t> f(string s){
    size_t n = s.size();
    vector<size_t> v(n); 
    v[0]= 0;

    for(size_t i =1; i< n; i++){
        size_t j = v[i-1];
        while(j>0 && s[i] != s[j]){
            j = v[j-1];
        }
        if(s[i] == s[j]){
            v[i] = j+1;
        }
    }
    return v;
}

bool fl(vector<size_t> &a, string b){
    for(int i = 0; i< a.size(); i++){
        if(a[i] == b.size()){
            return true;
        }
    }
    return false;
}
int main(){
    string a,b; 
    cin>>a>>b;
    string res = b+"#"+a;

    
    vector<size_t> v = f(res);
    int cnt = 0;
    for(int i =0; i<a.size()+1; i++){
        if(fl(v,b)){
            cout<<cnt;  
            return 0;
        }
        else{
            rotate(b.begin(),b.begin()+1,b.end());
            res = b + "#" + a;
            v = f(res);
            cnt++;
        }
    }

    cout<<"-1";
    return 0;

}