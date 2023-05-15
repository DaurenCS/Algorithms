#include<bits/stdc++.h>

using namespace std;

class heap{
    vector<long long > a;
    public:
        int getSize(){
            return a.size();
        }

        long long parent(long long i){
            return (i-1)/2;
        }

        long long right(long long i){
            return (i*2)+2;
        }

        long long left(long long i){
            return (i*2)+1;
        }

        void heap_up(long long i){
            while(i >= 0 && a[parent(i)] > a[i]){
                swap(a[i],a[parent(i)]);
                i = parent(i);
            }
        }

        void add(long long x){
            a.push_back(x);
            long long last_i = a.size()-1;
            heap_up(last_i);
        }

        long long get_min(){
            return a[0];
        }

        void heapify(long long i){
            long long last_i = a.size()-1;
            if(left(i)> last_i){
                return;
            }
            long long j = left(i);
            if(right(i) <= last_i && a[left(i)] >a[right(i)]){
                j = right(i);
            }

            if(a[i] > a[j]){
                swap(a[i],a[j]);
                heapify(j);
            }
        }

        long long extract_min(){
            long long max = get_min();
            swap(a[0], a[a.size()-1]);
            a.pop_back();
            if(a.size() > 0){
                heapify(0);
            }
            return max;
        }

};

int main(){
  long long n; cin>>n;
            
    heap * h = new heap();
    for(long long i = 0; i < n; i++){
        long long a; cin>>a;
        h->add(a);
    }
    long long s = 0;
    while(true){
        long long sum = h->extract_min();
        sum += h->extract_min();
        s+= sum;
        h->add(sum);
        if(h->getSize() < 2)break;
    }    
    cout<<s;

}