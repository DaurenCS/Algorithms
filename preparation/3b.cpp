#include<bits/stdc++.h>

using namespace std;

using ll = long long;

bool canS(ll a[],ll n, ll x,ll b){
    ll cur = 0;
    ll subarr = 0;
    for(int i = 0; i< n; i++){
        cur+= a[i];
        if(cur > x){
        subarr++;
        cur = a[i];
        }
    }
    return subarr + 1 <= b;

}

ll getSum(ll a[], ll n){  
    ll sum = 0;
    for(ll i = 0; i< n; i++){
        sum +=a[i];
    }
    return sum;
}

ll getMax(ll a[],ll n){
    ll max = a[0];
    for(ll i =0; i<n; i++){
        if(max < a[i]){
            max = a[i];
        }
    }
    return max;
}

ll bin(ll a[], ll n, ll b){
    ll l = getMax(a,n);
    ll r = getSum(a, n);
    ll res = r;
    while(l <= r){
        ll mid = (l+r)/2;
        if(canS(a,n,mid,b)){
            res = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return res;
}

int main(){
    int x,a; cin>>x>>a;
    ll arr[x];

    for(int i =0; i< x; i++){
        int s; cin>>s;
        arr[i] = s;
    }
    cout<<bin(arr,x,a);

}