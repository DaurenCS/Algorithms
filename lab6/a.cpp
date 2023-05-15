#include <bits/stdc++.h>

using namespace std;


int partition(vector<char> &a, int low, int hight){
    int pivot = hight;
    int i = low - 1;

    for(int j = low; j < hight; j++){
        if(a[j] < a[pivot]){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[pivot]);
    return i+1;
}

void qsort(vector<char> &a, int low, int hight){
    if(low < hight){
        int pivot = partition(a, low, hight);
        qsort(a, low, pivot-1);
        qsort(a,pivot+1, hight);
    }
}

bool isVowel(char a){
    string s = "aeiou";

    for(int i =0; i<s.size(); i++){
        if(a == s[i]){
            return true;
        }
    }
    return false;
}



int main(){
    int x; cin>>x;
    vector<char> a,b;
    string s; cin>>s;
    for(int i = 0; i<x; i++){
        if(isVowel(s[i])){
            a.push_back(s[i]);
        }
        else b.push_back(s[i]);
    }

    qsort(a,0,a.size()-1);
    qsort(b,0,b.size()-1);

    for(int i = 0; i<a.size(); i++){
        cout<<a[i];
    }
    for(int i = 0; i<b.size(); i++){
        cout<<b[i];
    }

}