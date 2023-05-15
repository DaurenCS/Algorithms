#include<bits/stdc++.h>

using namespace std;

int part(vector<char>&a, int low, int hight){
    int pivot = hight;
    int i = low-1;
    for(int j =low; j<hight; j++){
        if(a[j]<a[pivot]){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1],a[pivot]);
    return i+1;
}

void qsort(vector<char>&a, int low, int hight){
    if(low<hight){
        int pivot = part(a,low,hight);
        qsort(a,low,pivot-1);
        qsort(a,pivot+1,hight);
    }
}

int main(){
    int x;cin>>x;
    vector<char> a;
    for(int i =0; i<x; i++){
        char s; cin>>s;
        a.push_back(s);
    }
    char b; cin>>b;

    qsort(a,0,a.size()-1);

    for(int i =0; i<a.size(); i++){
        if(a[i]>b){
            cout<<a[i];
            return 0;
        }
    }
    cout<<a[0];
    return 0;

}