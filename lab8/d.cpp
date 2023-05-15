#include<bits/stdc++.h>

using namespace std;

int fun(vector<pair<string,int>>&x,string a, string b){
    size_t n = a.size();
    size_t m = b.size();

    long long h[n];
    long long p[n];
    long long q = (1 << 30) -1;


    p[0] = 1;
    
    for(size_t i =1; i<n; i++){
        p[i] = (p[i-1] * 31)%q;
    }

    for(size_t i = 0; i<n; i++){
        h[i] = ((a[i] - int('a') + 1) * p[i])%q;
        if(i > 0){
            h[i] = (h[i-1] + h[i])%q;
        }
    }
    long long h_s = 0;
    for(size_t i =0; i<m; i++){
        h_s = (h_s + ((b[i] - int('a')+1)*p[i])%q) % q;
    }
    int cnt = 0;

    for(size_t i =0; i+m-1< n; i++){
        long long d = h[i+m-1];
        if(i > 0){
            d = (d - h[i-1] + q)%q;
        }
        if(d == (h_s * p[i])%q && a.substr(i,m)==b){
            cnt++;
        }
    }
    x.push_back(make_pair(b,cnt));
    return cnt;
}

int main(){
    int x;
    while(true){
        cin>>x;
        if(x == 0) return 0;
        vector<string> v;
        for(int i =0; i<x; i++){
            string s; cin>>s;
            v.push_back(s);
        }
        string a; cin>>a;
        vector<pair<string,int>> m;
        int maxi = 0;
        for(int i =0; i<v.size(); i++){
            maxi = max(fun(m,a,v[i]),maxi);
        }
        cout<<maxi<<endl;
        for(auto l:m){
            if(l.second == maxi)
            cout<<l.first<<endl;
        }
        
    }
}