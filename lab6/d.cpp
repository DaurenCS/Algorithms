#include<bits/stdc++.h>

using namespace std;

int partition(vector<vector<int>> &a, int low, int hight){
    int pivot = hight;
    int i = low -1;
    for(int j =low; j<hight; j++){
        if(a[j]<a[pivot]){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[pivot]);
    return i+1;
}

void qsort(vector<vector<int>> &a, int low, int hight){
    if(low < hight){
        int pivot = partition(a, low, hight);
        qsort(a, low, pivot-1);
        qsort(a, pivot+1, hight);
    }
}
void toInt(string s, vector<int> &v, vector<vector<int>> &b){
    string d = s.substr(0,2);
    string m = s.substr(3,2);
    string y = s.substr(6,4);
    v.push_back(stoi(y));
    v.push_back(stoi(m));
    v.push_back(stoi(d));
    b.push_back(v);
}


int main(){
    int x; cin>>x;
    vector<vector<int>> a;
    
    for(int i =0; i<x; i++){
        string s; cin>>s;
        vector<int> v;
        toInt(s,v,a);
        
    }
    qsort(a,0,a.size()-1);

     for (int i = 0; i < a.size(); i++) {
        if(a[i][2]<10 && a[i][1]<10){
            cout<<"0"<<a[i][2]<<"-0"<<a[i][1]<<"-"<<a[i][0]<<endl;
        }
        else if(a[i][1]<10){
            cout<<a[i][2]<<"-0"<<a[i][1]<<"-"<<a[i][0]<<endl;
        }
        else if(a[i][2]<10 ){
            cout<<"0"<<a[i][2]<<"-"<<a[i][1]<<"-"<<a[i][0]<<endl;
        }
        else
            cout<<a[i][2]<<"-"<<a[i][1]<<"-"<<a[i][0]<<endl;
    }
}