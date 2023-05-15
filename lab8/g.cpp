#include<bits/stdc++.h>

using namespace std;

void fun(string a, string b){
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
    cout<<cnt<<endl;
    
}

int main(){
    string a; int x;
    cin>>a>>x;

    for(int i =0; i<x; i++){
        int l,r;
        cin>>l>>r;
        fun(a,a.substr(l-1, r - l +1));
    }
    
}