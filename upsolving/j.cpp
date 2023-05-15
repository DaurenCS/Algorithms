#include<bits/stdc++.h>

using namespace std;

long long bin_seacrh(long long * a, int l, int r, long long t){
    while(l<=r){
        long long mid = (l+r)/2;
        if(a[mid] == t)return mid;
        else if(a[mid] > t){
            r = mid -1;
        }
        else if(a[mid] < t){
            l = mid + 1;
        }
    }
    return -1;
}

int main(){
    long long x; cin>>x;
    int a; cin>>a;
    long long arr[a];
    
    for(int i =0; i<a; i++){
        cin>>arr[i];
    }

    sort(arr,arr+a);

    for(int i =0; i< a-1; i++){
        long long val = x - arr[i];
        if(bin_seacrh(arr,0,a, val) != -1){
            cout<<arr[i]<<" "<< val;
            return 0;
        }
    }



}