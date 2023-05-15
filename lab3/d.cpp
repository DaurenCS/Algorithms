#include <bits/stdc++.h>
using namespace std;

int bin(int a[], int n, int x){
    int l = 0, r = n-1;
    int large = n, sum = 0;
    while(l <= r){
        int m = l + (r-l)/2;
        if(a[m] > x){
            r = m-1;
            large = m;
        }else l = m+1;
    }

    return large;
}

int find(int a[], int n, int l1, int r1, int l2, int r2){
    int cnt = 0, d  = 0;
    int first = bin(a, n, r1) - bin(a, n, l1-1);
    int second = bin(a, n, r2) - bin(a, n, l2-1);
    if(l2 <= l1 and r2 >= r1)
        return second;
    else if(l1 <= l2 and r1 >= r2)
        return first;
    else if(l1 < r2 and r1 >= r2)   
        d = bin(a, n, r2) - bin(a, n, l1-1);
    else if(l2 < r1 and r2 >= r1)
        d = bin(a, n, r1) - bin(a, n, l2-1);
    

    return first + second - d;
}

int main(){
    int n,  q;
    cin >> n >> q;
    int a[n];
    for(int i = 0; i < n; i++)cin >> a[i];
    sort(a, a+n);

    for(int i = 0; i < q; i++){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        cout << find(a, n, l1, r1, l2, r2) << endl;
    
    }
}