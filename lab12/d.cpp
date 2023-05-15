#include<bits/stdc++.h>

using namespace std;

const int INF = 1000000000;
                    
 
int main() {
	int n;cin>>n;
	vector < vector < pair<int,int> > > g;
    vector<pair<int,int>> v;
    vector<bool> ind(n,false);
    
    for(int i =0; i<n; i++){    
        int a, b; cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    for(int i =0; i<n; i++){
        vector<pair<int,int>> vs;
        for(int j =0; j<n; j++){
            if(i!=j)
            vs.push_back(make_pair(j,(abs(v[i].first - v[j].first)+abs(v[i].second - v[j].second))));
        }
        g.push_back(vs);
    }

	int s = 0; // стартовая вершина
 
	vector<int> d (n, INF);
    vector<pair<int,int>> p (n);
	d[s] = 0;
	set < pair<int,int> > q;
	q.insert (make_pair (d[s], s));
	while (!q.empty()) {
		int v = q.begin()->second;
        if(q.begin()->first == INF) break;
		q.erase (q.begin());
        
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[to] > len && d[to] > d[v]) {
				q.erase (make_pair (d[to], to));
				d[to] = max(d[v],len);
				q.insert (make_pair (d[to], to));
			}
           
		}
	}

    cout<<d[n-1];
  

}