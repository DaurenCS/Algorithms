#include<bits/stdc++.h>

using namespace std;

using ll = long long;

class heap{
    vector<ll> a;

    public:

        int getSize(){
            return a.size();
        }
        
        ll parent(ll i){
            return (i-1)/2;
        }
        ll left(ll i){
            return i*2+1;
        }
        ll right(ll i){
            return i*2 +2;
        }

        void add(ll i){
            a.push_back(i);
            ll last = a.size()-1;
            heap_up(last);
        }

        void heap_up(ll i){
            while(i >= 0 && a[parent(i)] > a[i]){
                swap(a[parent(i)], a[i]);
                i = parent(i);
            }
        }

        void heapify(ll i){
            ll last = a.size()-1;
            if(left(i)> last)return;

            ll j = left(i);
            if(right(i) <= last && a[left(i)] > a[right(i)]){
                j = right(i);
            }
            if(a[i] > a[j]){
                swap(a[i],a[j]);
                heapify(j);
            }
        }
        long long getMin(){
            return a[0];
        }

        int extract(){
            int min = getMin();
            swap(a[0],a[a.size()-1]);
            a.pop_back();
            if(a.size()>0){
                heapify(0);
            }
            return min;
        }
    

};

int main(){
    heap * h = new heap();

    long long  a,b; cin>>a>>b;
    for(long long i =0, x; i<a; i++){
        cin>>x;
        h->add(x);
    }
    long long cnt = 0;
    while(true){
        if(h->getMin() > b)break;
        
        else if(h->getSize()<=1){
            cout<<-1;
            return 0;
            }
        

        long long sum = h->extract();
        sum += 2*h->extract();
        h->add(sum);
        cnt++;
    }
    cout<<cnt;

}