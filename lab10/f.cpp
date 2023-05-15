#include<bits/stdc++.h>

using namespace std;

void bfs(int ax,int b, vector<int> a[],vector<bool> &ind){
    
    queue<int> q;
    q.push(ax);
    ind[ax] = true;
    while(q.size()>0){
        int i = q.front();
        q.pop();
        for(int j =0; j<a[i].size(); j++){
            if(!ind[a[i][j]]){
                ind[a[i][j]] = true;
                if(a[i][j] == b){
                    cout<<"YES";
                    return;
                }
                q.push(a[i][j]);  
            }
        }
    }
    cout<<"NO";
    return;
}

int main(){
    int x,y;
    cin>>x>>y;

    vector<int> a[x+1];
    vector<bool> ind(x+1,false);

    for(int i =0; i<y; i++){
        int c,d;cin>>c>>d;
        a[c].push_back(d);
        a[d].push_back(c);
    }

    int s,f;
    cin>>s>>f;
    bfs(s,f,a, ind);
}