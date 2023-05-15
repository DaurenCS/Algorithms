#include<bits/stdc++.h>

using namespace std;

int bin(int a[], int x, int l, int r){
    int res;
    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid] == x)return mid;
        else if(a[mid] < x){
            l = mid+1;
        }
        else{
            r = mid - 1;
        }
    }

}

int main(){
    int a,x;
    cin>>a>>x;
    int arr[a];
    for(int i = 0; i < a; i++){
        cin>>arr[i];
    }

    cout<<bin(arr,x,0,a);
    
}