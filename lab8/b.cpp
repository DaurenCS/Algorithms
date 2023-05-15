#include<bits/stdc++.h>

using namespace std;

void fun(string x,string a, string b){
    size_t n = a.size();
    size_t m = b.size();
    size_t l = x.size();
    
    long long h[n];
    long long h1[l];
    long long p[max(n,l)];
    long long q = (1 << 6) - 1;

    p[0] = 1;
    int cnt = 0;

    for(size_t i = 1; i<max(n,l); i++){
        p[i] = (p[i-1] * 6) % q;
    }

    for(size_t i = 0; i< n; i++){
        h[i] = ((a[i] - int('a')+1) * p[i])%q;
        h1[i] = ((x[i] - int('a')+1) * p[i])%q;
        if(i>0){
            h[i] = (h[i] + h[i-1])%q;
            h1[i] = (h1[i] + h1[i-1])%q;
        }
    }


    long long h_s = 0;
    for(size_t i =0; i<m; i++){
        h_s = (h_s + (( b[i] - int('a')+1 )*p[i] ) %q) %q;
    }
    

    for(size_t i = 0; i + m-1<n; i++){
        long long d = h[i+m-1];
        long long d1 = h1[i+m-1];
        if(i> 0){
            d = (d - h[i-1] +q)%q;
            d1 = (d1 - h1[i-1] +q)%q;
        }
        if((d == (h_s * p[i])%q && d1 == (h_s * p[i])%q)){
            cnt++;
        }
    }
    cout<<cnt;
    
}


int main(){
    vector<int >a1,b1;
    string a,b,c; 
    cin>>a>>b>>c;
    fun(a,b,c);
   
}