#include<bits/stdc++.h>

using namespace std;

class heap{
    vector<long long> a;
    public:
        
        long long parent(long long i){
            return (i - 1)/2;
        }
        long long left(long long i){
            return 2 * i + 1;
        }

        long long right(long long i){
            return 2 * i + 2;
        }

        void heap_up(long long i){
            while(i>= 0 && a[parent(i)] < a[i]){
                swap(a[i],a[parent(i)]);
                i = parent(i);
            }
        }
        void add(long long i){
            a.push_back(i);
            long long last_i = a.size()-1;
            heap_up(last_i);
        } 

        void heapify(long long i){
            long long last_i = a.size()-1;
            if(left(i) > last_i)return;
            long long j = left(i);
            if(right(i)<= last_i && a[left(i)] < a[right(i)]){
                j = right(i);
            }
            if(a[i] < a[j]){
                swap(a[i],a[j]);
                heapify(j);
            }
        }
        long long getMax(){
            return a[0];
        }

        long long extract_max(){
            long long max = a[0];
            swap(a[0], a[a.size()-1]);
            a.pop_back();
            if(a.size()>0){
                heapify(0);
            }
            return max;
        }
};

int main(){
    heap * h = new heap();

    long long a,x; cin>>a>>x;
    

    for(long long i = 0; i < a; i++){
        long long x; cin>>x;
        h->add(x); 
    } 
    long long sum = 0;
    while(x > 0){
        long long s = h->extract_max();
        sum+=s;
        h->add(s-1);
        x--;
    }
    cout<<sum;


}