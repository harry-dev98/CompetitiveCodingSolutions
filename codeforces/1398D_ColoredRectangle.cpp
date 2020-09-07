#include<iostream>
#include<queue>
using namespace std;

bool check(const priority_queue<long long>& a, const priority_queue<long long>& c,const priority_queue<long long>& b){
    return ((a.empty() && (b.empty() || c.empty())) 
    || (b.empty() && (a.empty() || c.empty()))
    || (c.empty() && (b.empty() || a.empty())));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long R, G, B, r, b, g;
    cin>>R>>G>>B;
    priority_queue<long long> rr, bb, gg;
    for(long long i=0; i<R; i++){
        cin>>r;
        rr.push(r);
    }
    for(long long i=0; i<G; i++){
        cin>>g;
        gg.push(g);
    }
    for(long long i=0; i<B; i++){
        cin>>b;
        bb.push(b);
    }
    long long ans = 0;
    while(!check(rr, gg, bb)){
        if(!rr.empty()){
            r = rr.top();
        }
        else{
            r = 0;
        }
        if(!bb.empty()){
            b = bb.top();
        }
        else{
            b = 0;
        }
        if(!gg.empty()){
            g = gg.top();
        }
        else{
            g = 0;
        }
        if(r*b > r*g){
            if(r*b > b*g){
                ans += r*b;
                rr.pop();bb.pop();
            }
            else if(r*b < b*g){
                ans += b*g;
                bb.pop(); gg.pop();
            }
            else{
                queue<int>g__, r__;
                int g_ = g, r_ = r;
                while(g == r){
                    g__.push(g_);
                    r__.push(r_);
                    g_ = gg.top();
                    r_ = rr.top();
                    gg.pop();rr.pop();
                }
                while(!g__.empty()){
                    gg.push(g__.front());
                    g__.pop();
                }
                while(!r__.empty()){
                    rr.push(r__.front());
                    r__.pop();
                }
                if(g_>r_){
                    gg.pop();
                    ans += g * b;
                }
                else{
                    rr.pop();
                    ans += r * b;
                }
            }
        }
        else if(r*b < r*g){
            if(r*g > b*g){
                ans += r*g;
                rr.pop();gg.pop();
            }
            else if(r*g < b*g){
                ans += b*g;
                bb.pop(); gg.pop();
            }
            else{
                queue<int>b__, r__;
                int b_ = b, r_ = r;
                while(b == r){
                    b__.push(b_);
                    r__.push(r_);
                    b_ = bb.top();
                    r_ = rr.top();
                    bb.pop();rr.pop();
                }
                while(!b__.empty()){
                    bb.push(b__.front());
                    b__.pop();
                }
                while(!r__.empty()){
                    rr.push(r__.front());
                    r__.pop();
                }
                if(b_>r_){
                    bb.pop();
                    ans += g * b;
                }
                else{
                    rr.pop();
                    ans += r * g;
                }
            }
        }
        else{
            queue<int>b__, g__;
            int b_ = b, g_ = g;
            while(b == g){
                b__.push(b_);
                g__.push(g_);
                b_ = bb.top();
                g_ = bb.top();
                bb.pop();gg.pop();
            }
            while(!b__.empty()){
                bb.push(b__.front());
                b__.pop();
            }
            while(!g__.empty()){
                gg.push(g__.front());
                g__.pop();
            }
            if(b_>g_){
                bb.pop();
                ans += r * b;
            }
            else{
                gg.pop();
                ans += r * g;
            }
        }
    }
    cout<<ans<<"\n";
}