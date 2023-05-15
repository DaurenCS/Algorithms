#include<bits/stdc++.h>

using namespace std;

int partition(vector<int> &a, int low, int hight){
    int pivot = hight;
    int i = low-1;
    for(int j = low; j<hight; j++){
        if(a[j]>a[pivot]){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[pivot]);
    return i+1;
}

void qsort(vector<int> &a, int low, int hight){
    if(low<hight){
        int pivot = partition(a,low,hight);
        qsort(a,low,pivot-1);
        qsort(a,pivot+1, hight);
    }
}

int main(){
    int a,b; cin>>a>>b;
    vector<vector<int>>v;
    for(int i =0; i<a; i++){
        vector<int> x;
        for(int j = 0; j<b; j++){
            int s; cin>>s;
            x.push_back(s);
        }
        v.push_back(x);
    }
    vector<vector<int>>v1;
    for(int i=0; i<b; i++){
        vector<int>x;
        for(int j =0; j<a; j++){
            x.push_back(v[j][i]);
        }
        v1.push_back(x);
    }

    for(int i =0; i<v1.size(); i++){
        qsort(v1[i], 0, v1[i].size()-1);
    }

    for(int i =0; i<a; i++){
        for(int j =0; j<v1.size(); j++){
            cout<<v1[j][i]<<" ";
        }
        cout<<endl;
    }
}