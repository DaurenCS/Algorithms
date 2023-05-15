#include<bits/stdc++.h>

using namespace std;

int a[100][100];
int x;

int bfs(int ax, int b, vector<bool> ind){
    queue<int> q;
    q.push(ax);
    ind[ax] = true;
    int cnt = 0;

    while(q.size()> 0){
        int i = q.front();
        q.pop();
        cnt++;
        for(int j =0; j<x; j++){
            if(!ind[j] && a[i][j] == 1){
                if(j == b){
                    return cnt;
                }
                ind[j] = true;
                q.push(j);
            }
        }
    }
    return -1;
}

int main(){
     cin>>x;

    

    for(int i =0; i<x; i++){
        for(int j =0; j<x; j++){
            cin>>a[i][j];
        }
    }

    int ax,b; cin>>ax>>b;

    vector<bool> ind(x);
    
       
     cout<<bfs(ax-1, b-1, ind);

}