#include <bits/stdc++.h>
using namespace std;

size_t f(string str){
    size_t n = str.size();
    vector <size_t> v(n);
    v[0] = 0;
    size_t max = 0;
    for(size_t i = 1; i < n; i++){
        size_t j = v[i-1];
        while(j > 0 && str[i] != str[j]){
            j = v[j-1];
        }
        if(str[i] == str[j]){
            v[i] = j + 1;
            if(v[i] > max && str.substr(0, v[i]) == str.substr(n - v[i], v[i])){
                max = v[i];
            }
        }
    }
    return max;
}

int main(){
    string text;
    int n;
    cin >> text >> n;
    size_t max = 0;
    vector <pair <size_t, string>> v(n);
    for(int i = 0; i < n; i++){
        string pattern;
        cin >> pattern;
        string p = pattern;
        p[0] = tolower(p[0]);
        string str = p + "#" + text;
        if(f(str) > max){
            max = f(str);
        }
        v[i] = {f(str), pattern};
    }
    if(max == 0){
        cout << 0;
        return 0;
    }
    int cnt = 0;
    for(auto x: v){
        if(x.first == max){
            cnt++;
        }
    }
    cout << cnt << endl;
    for(auto x: v){
        if(x.first == max){
            cout << x.second << endl;
        }
    }
}