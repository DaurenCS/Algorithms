#include<bits/stdc++.h>

using namespace std;

int part(vector<vector<string>>&a, int low, int hight){
    int pivot = hight;
    int i = low-1;
    for(int j =low; j<hight; j++){
        if(a[j]< a[pivot]){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[pivot]);
    return i+1;
}

void qsort(vector<vector<string>>&a, int low,int hight){
    if(low<hight){
        int pivot = part(a,low,hight);
        qsort(a,low,pivot-1);
        qsort(a,pivot+1, hight);
    }
}
int fun(vector<vector<string>>&a){
    for(int i =0; i<a.size()-1; i++){
        for(int j =i+1; j<a.size(); j++){
            if(a[i][1]==a[j][0]){
                a[i][1]=a[j][1];
                a.erase(a.begin()+j);
            }
            else if(a[i][0] == a[j][1]){
                a[i][0] = a[j][0];
                a.erase(a.begin()+j);
            }
        }   
    }
    return a.size();
}

int main(){
    int x; cin>>x;
    vector<vector<string>> a;
    for(int i =0; i<x; i++){    
        vector<string> x;
        string n,s;cin>>n>>s;
        x.push_back(n);
        x.push_back(s);
        a.push_back(x);
    }

    qsort(a,0,a.size()-1);

    while(true){
        int fl = fun(a);
        if(fl == fun(a)){
            break;
        }
    }

    
    cout<<a.size()<<endl;
    for(int i =0; i<a.size(); i++){
        for(int j =0; j<a[i].size(); j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
        

}