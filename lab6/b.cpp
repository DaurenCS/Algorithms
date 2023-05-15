#include<bits/stdc++.h>
#include <algorithm>

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
    swap(a[i+1], a[pivot]);
    return i+1;
}

void qsort(vector<int> &a, int low, int hight){
    if(low < hight){
        int pivot = partition(a, low, hight);
        qsort(a,low, pivot-1);
        qsort(a,pivot+1, hight);
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

    qsort(x,0,x.size()-1);
    qsort(y,0,y.size()-1);

    for(int i =0; i<y.size(); i++){
        for(int j =0; j<x.size(); j++){
            if(x[j]==y[i]){
                cout<<x[j]<<" ";
                x[j] = y[i] = -1;
            }
        }
    }
    
}