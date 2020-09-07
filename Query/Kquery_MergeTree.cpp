#include<bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

vector<int> st[1000001];

// void p(vector<int> c){
//     for(auto itr=c.begin(); itr!=c.end(); itr++)cout<<*itr<<" itr ";
//     cout<<"\n";
// }

// void merge(vector<int> a, vector<int> b, int ind){
//     auto a_ = a.begin(), b_ = b.begin();
//     while(a_!=a.end() && b_ != b.end()){
//         if(*a_ < *b_){
//             st[ind].emplace_back(*a_); a_++;
//         }
//         else if(*a_ == *b_){
//             st[ind].emplace_back(*a_); a_++;
//             st[ind].emplace_back(*b_); b_++;
//         }
//         else{
//             st[ind].emplace_back(*b_); b_++;
//         }
//     }
//     while(a_ != a.end()){
//         st[ind].emplace_back(*a_); a_++;
//     }
//     while(b_ != b.end()){
//         st[ind].emplace_back(*b_); b_++;
//     }
//     // p(a);p(b);p(st[ind]);
//     return;
// }

void build(int arr[], int s, int e, int ind=0){
    if(s==e){
        st[ind].emplace_back(arr[s]);
        return;
    }
    int mid = (s+e)/2;
    build(arr, s, mid, 2*ind+1);
    build(arr, mid+1, e, 2*ind+2);
    merge(st[2*ind+1].begin(), st[2*ind+1].end(), st[2*ind+2].begin(), st[2*ind+2].end(), back_inserter(st[ind]));
}
// #define vitr vector<int>::iterator 
// vitr lower_bound(vitr b, vitr e, int k){
//     while( b!= e){
//         if(*b>k) return b;
//         b++;
//     }
//     return b;
// }

int query(int s, int e, int l, int r, int k, int ind=0){
    if(r<s || e<l){
        return 0;
    }
    if(l<=s && e<=r){
        // printf(" %d %d %d ans\n",s,e, (int)(st[ind].end()-lower_bound(st[ind].begin(), st[ind].end(), k)));
        return st[ind].size()-(upper_bound(st[ind].begin(), st[ind].end(), k)-st[ind].begin());
    }
    int mid = (s+e)/2;
    return query(s, mid, l, r, k, 2*ind+1) + query(mid+1, e, l, r, k, 2*ind+2);
}

int main(){
    int t;
    SPEED;
    cin>>t;
    int arr[t];
    for(int i=0; i<t; i++){
        cin>>arr[i];
    }
    int q, k, last_ans=0;
    build(arr, 0, t-1);
    cin>>q;
    int I, J, K;
    for(int i=0; i<q; i++){
        cin>>I>>J>>K;
        I = (I^last_ans<1)?1:I^last_ans;
        J = (J^last_ans>t)?t:J^last_ans;
        K = K^last_ans;
        last_ans=(I>J)?0:query(0, t-1, I-1, J-1,  K);
        cout<<last_ans<<"\n";
    }
    return 0;
}