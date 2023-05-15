#include <bits/stdc++.h>

using namespace std;

int bin_search(vector<int> v, int l, int r, int x){
	int mid;
	while(l <= r){
		mid = (l + r) / 2;

		if(v[mid] == x)
			return mid;

		if(x > v[mid])
			l = mid + 1;
		else
			r = mid - 1;
	}
	return -1;
}

int main(){
	int k;
	cin >> k;
	int arr[k];
	for(int i=0; i<k; i++)
		cin >> arr[i];

	int n, m, x;
	cin >> n >> m;
	vector <vector<int>> v;
	for(int i=0; i<n; i++){
		vector <int> temp;
		for(int j=0; j<m; j++){
			cin >> x;
			temp.push_back(x);
		}
		v.push_back(temp);
	}

	vector <pair<int, int>> res(k);
	for(int i=0; i<k; i++){
		int ind = 0;
		bool found = true;
		while(arr[i] < v[ind][0] && arr[i] < v[ind][m-1]){
			ind++;

			if(ind == n){
				found = false;
				break;
			}
		}
		if(!found){
			res[i] = make_pair(-1, -1);
			continue;
		}

		vector<int> a = v[ind];
		if(ind % 2 == 0)
			reverse(a.begin(), a.end());
		
		int ind_2 = bin_search(a, 0, m-1, arr[i]);
		if(ind_2 == -1){
			res[i] = make_pair(-1, -1);
			continue;
		}

		if(ind % 2 == 0)
			ind_2 = m - 1 - ind_2;

		res[i] = make_pair(ind, ind_2);
	}

	for(int i=0; i<k; i++){
		if(res[i].first == -1 && res[i].second == -1)
			cout << -1 << '\n';
		else
			cout << res[i].first << ' ' << res[i].second << '\n';
	}
}