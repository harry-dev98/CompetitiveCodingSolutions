#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    vector<long long> A(n);
    for(long long& a: A)cin>>a;
    map<long long, long long> CountA;
    for(long long a: A){
        CountA[a]++;
    }
    vector<pair<long long, long long>> CountAVec;
    for(auto itr: CountA){
        CountAVec.push_back(itr);
    }
    long long spreadA = CountAVec.size();
    vector<long long> MaxSum(spreadA+1, 0);
    MaxSum[1] = CountAVec[0].first*CountAVec[0].second;
    for(long long i=1; i<spreadA; i++){
        if(CountAVec[i-1].first+1 == CountAVec[i].first){
            MaxSum[i+1] = max(MaxSum[i], MaxSum[i-1] + CountAVec[i].first*CountAVec[i].second);
        }
        else{
            MaxSum[i+1] = MaxSum[i] + CountAVec[i].first*CountAVec[i].second;
        }
    }
    cout<<MaxSum[spreadA]<<"\n";
    return 0;
}