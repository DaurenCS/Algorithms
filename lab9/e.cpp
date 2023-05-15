#include<bits/stdc++.h>

using namespace std;

void f(string s,int x){
    size_t n =s.size();
    vector<size_t> v(n);

    v[0] = 0;
    int cnt = 0;
    for(size_t i =1; i<n; i++){
        size_t j = v[i-1];
        while(j>0 && s[i]!= s[j]){
            j = v[j-1];
        }
        if(s[i] == s[j]){
            v[i] = j+1;
        }
    }

    cout<< (n - v.back()) * (x-1) + n<<endl;
    
}
// nugmanugmanugmanugmanugmanugmanugman
int main(){
    int x;
    cin>>x;
    for(int i =0; i<x; i++){
        string s; cin>>s;
        int a; cin>>a;
        f(s,a);
    }
    
}