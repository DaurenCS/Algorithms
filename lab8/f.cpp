#include<bits/stdc++.h>

using namespace std;

void fun(string a){
    size_t n = a.size();
    long long h[n];
    long long p[n];
    long long q = LONG_LONG_MAX;
    p[0] = 1;
    for(size_t i = 1; i<n; i++){
        p[i] =(p[i-1]*31) % q;
    }

    for(size_t i =0; i<n; i++){
        h[i] = ((a[i] - int('a')+1)*p[i])%q;
        
        if(i>0){
            h[i] = (h[i-1] + h[i])%q;
            
        }
    }
    // for(size_t i =0; i<n ; i++){
    //     t.insert(h[i]);
    // }
    
    int cnt = 0;
    for(size_t i = 1; i <= n; i++){
        set <long long> st;
        for(size_t j = 0; j +i < n + 1; j++){
            long long d = h[j + i - 1];
            if(j > 0){
                d -= h[j - 1];
            }
            d *= p[n - j - 1];
            st.insert(d);
        }
        cnt +=  st.size();
    }
    cout<<cnt;


}

int main(){
    string s;
    cin>>s;
    fun(s);
}