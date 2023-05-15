#include<bits/stdc++.h>

using namespace std;

int partition(vector<int> &a, int low, int hight){
    int pivot = hight;
    int i = low-1;
    for(int j = low; j<hight; j++){
        if(a[j]<a[pivot]){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[pivot]);
    return i+1;
}

void qsort(vector<int> &a, int low, int hight){
    if(low < hight){
        int pivot = partition(a, low, hight);
        qsort(a, low, pivot-1);
        qsort(a, pivot+1, hight);
    }
}

int main(){
    int x; cin>>x;
    vector<int> a;
    for(int i =0; i<x; i++){
        int s; cin>>s;
        a.push_back(s);
    }
    qsort(a,0,a.size()-1);
    int mini = INT_MAX;
    for(int i =0; i<a.size()-1; i++){
        if(abs(a[i]-a[i+1]) < mini){
            mini = min(mini, abs(a[i]-a[i+1])); 
        }
    }
    for(int i =0; i<a.size()-1; i++){
        if(abs(a[i]-a[i+1]) == mini){
            cout<<a[i]<<" "<<a[i+1]<<" ";
        }
    }
}