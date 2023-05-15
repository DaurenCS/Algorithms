#include<bits/stdc++.h>

using namespace std;

int main(){
	vector<int> a;
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int s;
		cin>>s;
		if(!a.empty()){
			while(s - a.front() > 3000 && !a.empty())
				a.erase(a.begin());
		}
		a.push_back(s);
		cout<<a.size()<<' ';
	}


}