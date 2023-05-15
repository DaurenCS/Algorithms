#include<bits/stdc++.h>

using namespace std;

int a[1000000];

int ind = 0;

void add(int x){
    a[++ind]= x;
}

void del(){
    if(ind != 0){
        ind--;
    }
}

void getCur(){
    if(ind == 0) cout<<"error"<<endl;
    else{
        cout<<a[ind]<<endl;
    }
}

void getMax(){
    if(ind == 0)cout<<"error"<<endl;
    else{
        int max = 0;
        for(int i =0; i<=ind; i++){
            if(a[i]> max){
                max = a[i];
            }
        }
        cout<<max<<endl;
    }
}

int main(){
    int x; cin>>x;
    
    for(int i =0; i<x; i++){
        string s; cin>>s;
        if(s == "add"){
            int a1;cin>>a1;
            add(a1);
        }
        else if(s == "delete"){
            del();
        }
        else if(s == "getmax"){
             getMax();
        }
        else if(s == "getcur"){
            getCur();
        }
    }
}





