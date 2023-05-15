#include <bits/stdc++.h>
using namespace std;

int bin(int v[], int x, int n){
    int ind = n;
    int l = 0, r = n-1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(v[mid] >= x){
            ind = mid;
            r = mid-1;
        }else l = mid+1;
    }

    return ind+1;
}

int main(){
    int n, m;
    cin >> n >> m;
    int blocks[n], b[n];
    for(int i = 0; i < n; i++){
        cin >> b[i];
        if(i == 0)blocks[i] = b[i];
        else blocks[i] = (b[i] + blocks[i-1]);
    }

    while(m){
        int x;cin >> x;
        cout << bin(blocks, x, n) << endl;
        m--;
    }


}