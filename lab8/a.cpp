#include <bits/stdc++.h>

using namespace std;

int f(string s){
    
    size_t m = s.size();

    
    long long p[m];
    long long q = pow(10,9)+7;

    p[0] = 1;

    for(size_t i = 1; i < m; ++i){
        p[i] = (p[i - 1] * 11) % q;
    }

    
    long long h_s = 0;
    for(size_t i = 0; i < m; ++i){
        h_s = (h_s + ((s[i] - 47) * p[i]) % q) % q;
    }

    return h_s;
}

int main(){
    string a;
    cin>>a;
    cout<<f(a);
    // int x; cin>>x;
    // vector<string> a;
    // set<string> st;

    // for(int i =0; i<x*2; i++){
    //     string s;
    //     cin>>s;
    //     a.push_back(s);
    //     st.insert(s);
    // }
    // int cnt =0;
    // for(int i =0; i<a.size(); i++){    
    //         string h = to_string(f(a[i]));
    //         if(st.find(h)!= st.end()){
    //             cout<<"Hash of string \"" << a[i] << "\" is " << h<<endl; 
    //             cnt++;
    //         }
    //         if(cnt == x)break;
            
    //     }
    }

