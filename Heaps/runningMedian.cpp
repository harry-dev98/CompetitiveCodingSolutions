#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x, median=0;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>x;
        if(x < median){
            maxHeap.push(x);
            if(maxHeap.size() > minHeap.size()+1){
                // cout<<"pushing in min\n";
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
        else{
            minHeap.push(x);
            if(maxHeap.size() + 1 < minHeap.size()){
                // cout<<"pushing in max\n";
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        if(minHeap.size()==maxHeap.size()){
            median = (minHeap.top()+maxHeap.top())/2;
        }
        else if(minHeap.size()>maxHeap.size()){
            median = minHeap.top();
        }
        else{
            median = maxHeap.top();
        }
        cout<<median<<"\n";
    }
}