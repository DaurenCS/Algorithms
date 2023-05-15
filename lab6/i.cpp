#include<bits/stdc++.h>

using namespace std;

int part(vector<char> &a, int low, int hight){
    int pivot = hight;
    int i = low -1;
    for(int j =low; j<hight; j++){
        if(a[j]<a[pivot]){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1], a[pivot]);
    return i+1;
}

void qsort(vector<char>&a, int low, int hight){
    if(low<hight){
        int pivot = part(a, low, hight);
        qsort(a,low,pivot-1);
        qsort(a,pivot+1, hight);
    }
}

int main(){
    vector<char> a;

    string s; cin>>s;
    for(int i =0; i<s.size(); i++){
        a.push_back(s[i]);
    }

    qsort(a,0,s.size()-1);

    for(int i =0; i<a.size(); i++){
        cout<<a[i];
    }
}