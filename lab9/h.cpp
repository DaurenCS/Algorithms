#include <bits/stdc++.h>
using namespace std;

vector<size_t>  f(string s){
    size_t n = s.size();
    vector <size_t> v(n);
    v[0] = 0;
    for(size_t i = 1; i < n; i++){
        size_t j = v[i - 1];
        while(j > 0 && s[i] != s[j]){
            j = v[j - 1];
        }
        if(s[i] == s[j]){
            v[i] = j + 1;
        }
    }
    
    return v;

 }

int main(){
    string s;
    cin >> s;
    vector<size_t> v = f(s);

    int cnt = 0;

    
    
    for(size_t j = 1; j < s.size()-1; j += 2){
        if((j + 1 ) / ( j - v[j] + 1) % 2 == 0){
            if((j+1) % (j - v[j] + 1) == 0){
                cnt++;
            }
        }
    }

    cout<<cnt;
}