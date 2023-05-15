#include<bits/stdc++.h>

using namespace std;

class heap{
    public:
        vector<int> a;

         long long parent(long long i){
            return (i-1)/2;
        }
        long long left(long long i){
            return i*2 + 1;
        }
        long long right(long long i){
            return i*2 +2;
        }

        void heap_up(long long i){
            while(i >= 0 && a[parent(i)] < a[i]){
                swap(a[i], a[parent(i)]);
                i = parent(i);
            }
        }

        void add(long long i){
            a.push_back(i);
            long long last = a.size()-1;
            heap_up(last);
        }

        void print(){
            for(int i : a){
                cout<<i<<" ";
            }
        }

        void dfs(){
            int cnt =0;
            for(int i = 0; i<a.size(); i++){
                if(right(i)< a.size() && left(i)<a.size()){
                    if(a[right(i)] > a[left(i)]){
                        cnt++;
                    }
                    
                }
            }
            cout<<cnt;
        }

       

};

int main(){
    heap * h = new heap();
    int x; cin>>x;

    for(int i = 0; i< x; i++){
        int s; cin>>s;
        h->add(s);
    }
    h->dfs();

}

