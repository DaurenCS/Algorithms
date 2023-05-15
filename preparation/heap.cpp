#include<bits/stdc++.h>

using namespace std;

class heap{
    vector<long long> a;
    public:
        int getSize(){
            return a.size();
        }

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
            while(i>= 0 && a[parent(i)] > a[i]){
                swap(a[i],a[parent(i)]);
                i = parent(i);
            }
        }
        void add(long long i){
            a.push_back(i);
            long long last = a.size()-1;
            heap_up(last);   
        }

        void heapify(long long i){
            long long last = a.size() -1;
            if(left(i) > last)return;
            long long j = left(i);
            if(right(i) <= last && a[left(i)] > a[right(i)])
                j = right(i);
            if(a[i] > a[j]){
                swap(a[i],a[j]);
                heapify(j);
            }
        }
        long long getMin(){
            return a[0];
        }
        long long extractm(){
            long long max = getMin();
            swap(a[0], a[a.size()-1]);
            a.pop_back();
            if(a.size()> 0){
                heapify(0);
            }
            return max;
            
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
        

        long long sum = h->extractm();
        sum += 2*h->extractm();
        h->add(sum);
        cnt++;
    }
    cout<<cnt;
         
}