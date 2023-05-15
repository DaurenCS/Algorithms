#include<bits/stdc++.h>

using namespace std;

void merge(vector<int> &a, int l1, int r1, int l2, int r2){
    int n1 = r1 - l1 +1;
    vector<int> l;
    for(int i = 0; i<n1; i++){
        l.push_back(a[i+l1]);
    }

    int n2 = r2 - l2 +1;
    vector<int> r;
    for(int i = 0; i<n2; i++){
        r.push_back(a[i+l2]);
    }

    int i = l1; 
    int i1 = 0;
    int i2 = 0;

    while(i1<n1 && i2<n2){
        if(l[i1] < r[i2]){
            a[i++] = l[i1++];
        }
        else    
            a[i++] = r[i2++];
    } 

    while(i1<n1){
        a[i++] = l[i1++];
    }
    while (i2<n2){   
        a[i++] = r[i2++];
    }
    
}

void msort(vector<int>&a, int l, int r){
    if(l<r){
        int m = ceil((r+l)/2.0);
        msort(a,l,m-1);
        msort(a,m,r);
        merge(a,l,m-1,m,r);
    }
}

int main(){

    int a, b; 
    cin>>a>>b;
    vector<int > x,y;
  
    for(int i=0; i<a; i++){
        int s; cin>>s;
        x.push_back(s);
    }

        
    for(int i=0; i<b; i++){
        int s; cin>>s;
        y.push_back(s);
    }

    msort(x,0,x.size()-1);
    msort(y,0,y.size()-1);

    for(int i =0; i<y.size(); i++){
        for(int j =0; j<x.size(); j++){
            if(x[j]==y[i]){
                cout<<x[j]<<" ";
                x[j] = y[i] = -1;
            }
        }
    }
}