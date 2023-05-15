#include<bits/stdc++.h>

using namespace std;

void fun(int *a,int k, int x){
    int l = 0;
    int r = 5;
    
    while(l < r){
        int mid = (l + r)/2;
        if(x - a[mid] > a[mid + k] - x){
            l = mid+1;
        }
        else
            r = mid;
    }
    for(int i = l; i< l+k; i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    int x;
    cin>>x;
    int arr[x];
    for(int i =0; i< x; i++){
        cin>>arr[i];
    }
    int k, a;
    cin>>k>>a;
    fun(arr,k,a);

   
}