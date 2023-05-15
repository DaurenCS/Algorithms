#include<bits/stdc++.h>

using namespace std;

void bin(long long x){
    vector<int> s;
    while(x>0){
        if(s.size() == 0){
            s.push_back(x%2);
        }
        else if(s.size()!=0){
            if(s.back()== 0 && x%2 == 1){
                s.pop_back();
     
            }
            else
                s.push_back(x%2);
     
    

        }
        x = x/2;
    }
    
    if(s.size()==0)cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

}


int main(){
    int x; cin>>x;

    for(int i =0; i<x; i++){
        long long s; cin>>s;
        bin(s);
    }
}