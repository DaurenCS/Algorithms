#include<bits/stdc++.h>

using namespace std;

int bin(int * a, int l, int r, int res){
    
    while(l<=r){
        if(a[l] < a[r]){
            return min(res, a[l]);
        }
        int mid = (l + r)/2;
        res = min(res, a[mid]);
        if(a[mid] >= a[l]){
            l = mid + 1;
        }
        else
            r = mid - 1;
    }    
    return res;


}

int main(){
    int a; cin>>a;
    int arr[a];
    for(int i = 0; i<a; i++ ){
        cin>>arr[i];
    }

    cout<<bin(arr,0,a,arr[0]);
}
// 4 5 6 7 0 1 2

// l = 0  r = 7  mid = 3  res = 7
// l = 4  r = 7  mid = 5  res = 1 
// l = 6  r = 6  mid = 6  res =  2
// l = 6  r = 6   mid = 6  res =  1
