#include<bits/stdc++.h>

using namespace std;



void fun(string a, string b,map<string ,int> &mp){
    size_t n = a.size();
    size_t m = b.size();
    
    
    long long h[n];
    
    long long p[n];
    long long q = LONG_LONG_MAX;

    p[0] = 1;
    int cnt = 0;

    for(size_t i = 1; i<n; i++){
        p[i] = (p[i-1] * 31) % q;
    }

    for(size_t i = 0; i< n; i++){
        h[i] = ((a[i] - int('a')+1) * p[i])%q;
        
        if(i>0){
            h[i] = (h[i] + h[i-1])%q;
            
        }
    }


    long long h_s = 0;
    for(size_t i =0; i<m; i++){
        h_s = (h_s + (( b[i] - int('a')+1 )*p[i] ) %q) %q;
    }
    
    
    for(size_t i = 0; i + m-1<n; i++){
        long long d = h[i+m-1];
        
        if(i> 0){
            d -= h[i-1];
          
        }
        if(d == (h_s * p[i])){
            cnt++;
            
        }
    }
    if(cnt!= 0){
        mp[b]++;
    }
    
}



int main(){
    int x; cin>>x;
    map<string, int> m;
    vector<string> a;

    for(int i =0; i<x; i++){
        string s; 
        cin>>s;
        a.push_back(s);
    }    
    set<string> st;
    for(int xx = 0; xx< x; xx++){
        for(int i =0; i<a[0].size(); i++){
            for(int j = 1; j<=a[0].size(); j++){
                fun(a[xx],a[0].substr(i,j),m);
            }       
    }
    }
    
    string res = "";
    map<string, int>::iterator itr;
    for (itr = m.begin(); itr != m.end(); ++itr) {
        if(itr->second == x-1 && res.length() <itr->first.size()){
            res = itr->first;
        }    
    }
    
    cout<<res;
    

}