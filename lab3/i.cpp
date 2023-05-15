#include <bits/stdc++.h>

using namespace std;

string binary(int a[], int n, int t){
    int l = 0, r = n-1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(a[mid] == t) 
            return "Yes";
       
        else if(a[mid] > t)
            r = mid-1;
       
        else 
            l = mid+1;
    }

    return "No";
}

int main(){
    int n;cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)cin >> a[i];
    int t;cin >> t;

    cout << binary(a, n, t);
}