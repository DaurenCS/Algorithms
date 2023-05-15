#include<bits/stdc++.h>

using namespace std;

void fun(set<int>&st ,string s, string a){
    size_t n = s.size();
    size_t m = a.size();
    
    long long h[n];
    long long p[n];
    long long q = LONG_LONG_MAX;

    p[0] =1;

    for(size_t i =1; i<n; i++){
        p[i] = (p[i-1] * 31) %q;
    } 

    for(size_t i =0; i<n; i++){
        h[i] = ((s[i] - int('a') + 1) * p[i])%q;
        if(i > 0){
            h[i] = (h[i-1] + h[i])%q;
        }
    }

    long long h_s = 0;

    for(size_t i =0; i<m; i++){
        h_s = (h_s + ((a[i] - int('a')  + 1)*p[i])%q)%q;
    }

    for(size_t i =0; i + m - 1 < n; i++){
        long long d = h[i + m -1];
        if(i > 0){
            d -= h[i-1];
        }

        if(d == h_s * p[i] && s.substr(i,m)==a){
            for(int j = i; j < i + m; j++){
                st.insert(j);
            }
             
        }
    }

}

int main(){
    string s;
    int a;
    cin>>s>>a;
    set<int> st;
    
    for(int i =0; i<a;i++){
        string x; cin>>x;
        fun(st,s,x);
    }

    if(st.size() == s.size()){
        cout<<"YES";
    }
    else
        cout<<"NO";
    
}