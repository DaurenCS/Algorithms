#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll n,m,cost;

ll p[200002];
pair<ll,pair<ll,ll>> pr[200002];
ll res = 0;

void create_set(ll x){
    for(ll i = 1; i<=x; i++){
        p[i] = i;
    }
    
}

ll find(ll x){
    if(x == p[x])return x;
    return p[x] = find(p[x]);
}

ll union_s(ll a,ll b){
    a = find(a);
    b = find(b);
    if(a != b){
        p[a] = b;
        res += cost;
    }
    return b;
}

int main(){
    cin>>n>>m;
    for(ll i =0; i<m; i++){
        ll l,r; cin>>l>>r>>cost;
        pr[i] = make_pair(cost,make_pair(l,r));
    }

    create_set(n);
    sort(pr, pr + m);

    for(ll i =0; i<m; i++){
        ll l = pr[i].second.first, r = pr[i].second.second;
        cost = pr[i].first;
        for(ll j =l+1; j<=r; j++){
            j = union_s(l,j);
            if(j > r)break;
        }
    }

    cout<<res;


}
