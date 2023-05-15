#include<bits/stdc++.h>

using namespace std;

vector<size_t> f(string s){
    size_t n = s.size();
    vector<size_t> v(n);
    v[0] = 0;
    for(size_t i = 1; i< n; i++){
        size_t j = v[i-1];
        while(j > 0 && s[i]!= s[j]){
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
    int x;
    cin>>a>>x>>b;
    int cnt = 0;
    string res = a + "#" + b;
    vector<size_t> arr = f(res);
    for(int i =0; i<arr.size(); i++){
        if(arr[i] == a.size()){
            cnt++;
        }
    }
    if(cnt >= x){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}