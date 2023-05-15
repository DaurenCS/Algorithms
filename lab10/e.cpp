#include<bits/stdc++.h>

using namespace std;

int x;
int a[1000][1000];

void bfs(int ax, int b, int c){
    queue<int> q;
    vector<bool> ind(x+1,false);
    q.push(ax);
    ind[ax] = true;

    while(q.size()>0){
        int i = q.front();
        q.pop();
        if(a[i][b] == 1 && a[b][c] == 1 && a[i][c]==1){
            cout<<"YES"<<endl;
        }
        else    
            cout<<"NO"<<endl;
    }
}

int main(){
    int b;
    cin>>x>>b;

    
    for(int i =0; i<x; i++){
        for(int j =0; j<x; j++){
            cin>>a[i][j];
        }
    }

    
    for(int i = 0; i<b; i++){
        int d,f,g;
        cin>>d>>f>>g;
        bfs(d-1,f-1,g-1);
    }
    
}