#include<bits/stdc++.h>

using namespace std;

void merge(int *a,vector<int> &x,vector<int> &y, int l1, int r1,int l2,int r2){
    int n1 = r1-l1 +1;
    int n2 = r2 - l2 +1;
   

    int i = l1;
    int i1 = 0;
    int i2 = 0;

    while(i1<n1 && i2<n2){
        if(x[i1] < y[i2]){
            a[i++] = x[i1++];
        }
        else
            a[i++]= y[i2++];
    }

    while (i1<n1){   
        a[i++] = x[i1++];
    }

    while (i2<n2){
        a[i++] = y[i2++];
    }
}

// void msort(vector<int> &a, int l, int r){
//     if(l<r){
//         int m = ceil((l+r)/2.0);
//         msort(a,l,m-1);
//         msort(a,m,r);
//         merge(a,l,m-1,m,r);
//     }
// }

int main(){
    int a,b;
    vector<int> x,y;
    cin>>a;
    for(int i =0; i<a; i++){
        int s; cin>>s;
        x.push_back(s);
    }
    
    cin>>b;
    for(int i =0; i<b; i++){
        int s; cin>>s;
        y.push_back(s);
    }
    int arr[a+b];

    merge(arr,x,y,0,a-1,1,b);

    for(int i =0; i<a+b; i++){
        cout<<arr[i]<<" ";
    }
}