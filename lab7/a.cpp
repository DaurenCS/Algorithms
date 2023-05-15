#include<bits/stdc++.h>

using namespace std;

void merge(vector<string>&a, int l1, int r1, int l2,int r2){
    
    int n1 = r1 - l1 + 1;
    vector<string> l;
    for(int i =0; i<n1; i++){
        l.push_back(a[l1+i]);
    }

    int n2 = r2 -l2 +1;
    vector<string> r;
    for(int i =0; i<n2; i++){
        r.push_back(a[l2+i]);
    }

    int i = l1;
    int i1 = 0;
    int i2 = 0;

    while(i1 < n1 && i2 < n2){
        if((l[i1].size() < r[i2].size()) ){
            a[i++] = l[i1++];
        }
        else 
            a[i++] = r[i2++];
    }

    while(i1<n1){
        a[i++] = l[i1++];
    }
    while (i2 < n2)
    {
        a[i++] = r[i2++];
    }
    
}

void msort(vector<string>&a, int l, int r){
    if(l<r){
        int m = ceil((l+r)/2.0);
        msort(a, l, m-1);
        msort(a, m, r);
        merge(a,l,m-1, m, r);
    }
}



int main(){
    vector<vector<string>> a;
    vector<vector<string>> b;
     int x; cin>>x;


     for(int i = 0; i<=x; i++){
        string s; getline(cin, s);
        vector<string> v;
        vector<string> v1;
        string sub = "";
        for(auto x: s){ 
            
            if(x == ' '){
                v.push_back(sub);
                v1.push_back(sub);
                sub = "";
            }
            else{
                sub = sub + x;
            }
            
        }
        v1.push_back(sub);
        v.push_back(sub);
        b.push_back(v1);
        a.push_back(v);
     }
     for(int i = 0; i< a.size(); i++){
        msort(b[i],0,b[i].size()-1);
    }

     for(int i =1; i<a.size(); i++){
        int j = 0;
        while(b[i].size()>0){
             if(a[i][j%a[i].size()].length() == b[i][0].length()){
                cout<<a[i][j%a[i].size()]<<" ";
                a[i].erase(a[i].begin()+(j%a[i].size()));
                b[i].erase(b[i].begin());
                j = -1;
             }
             j++;
        }
           
               
            
        cout<<endl;
    }
}