#include<bits/stdc++.h>

using namespace std;

vector<size_t> f(string s){
    size_t n = s.size();
    vector<size_t> v(n);

    v[0] = 0;

    for(size_t i = 1; i<n; i++){
        size_t j = v[i-1];
        while( j>0 && s[j] != s[i]){
            j = v[j-1];
        }

        if(s[i]==s[j]){
            v[i] = j+1;
        }
    }
    return v;
}
bool fl(vector<size_t> &a, string b){
    for(int i =a.size()-1; i>0; i--){
        if(a[i] == b.size()){
            return true;
        }
    }
    return false;
}
int main(){
    string a,b;

    cin>>a>>b;
    string res = b + "#" + a;
    int cnt = 1;
    string s = "";

    while(a.size()+s.size() <= b.size()*2){
        s +=a;
        cnt++;
        
    }
    res += s;
    
    vector<size_t> ar = f(res);
    int flag = 0;
    
    if(fl(ar,b)){
        flag = 1;
    }

    for(int i =0; i< ar.size(); i++){
        if(flag == 1){
            if(!fl(ar,b)){
                cout<<cnt+1;
                return 0;
            }
            else{
                ar.resize(ar.size()-a.size());
                cnt--;
            }
        }
    }
   
    cout<<"-1";
    return 0;

}