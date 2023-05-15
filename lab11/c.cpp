#include<bits/stdc++.h>

using namespace std;

vector<pair<int, pair<int,int>>> g;
int p[1000];
int size[1000];

void create_set(int x){
    for(int i =1 ; i<= x; i++){
        p[i] = i;
        size[i] = i;
    }
}

int find(int x){
    if(x == p[x])return x;
    return p[x] = find(p[x]); 
}

void union_s(int a, int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(size[a]<size[b]) swap(size[a],size[b]);
        p[b] = a;
        size[a] += size[b]; 
    }
}

void make_r(int a, int b, int c){
    g.push_back(make_pair(c,make_pair(a,b)));
}

int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;

    int minn = min(x,y);

    for(int i =0; i<m; i++){
        string s; int a,b,c;
        cin>>s>>a>>b>>c;
        if(s == "small"){
            make_r(a,b,c*y);
        }
        else if(s == "big"){
            make_r(a,b,c*x);
        }
        else{
            make_r(a,b,c*minn);
        }
    }

    sort(g.begin(), g.end());
    create_set(n);
    int res = 0;

    for(auto i : g){
        int a = i.second.first, b = i.second.second, c = i.first;

        if(find(a) != find(b)){
            res += c;
            union_s(a,b);
        }
    }
    cout<<res;
}