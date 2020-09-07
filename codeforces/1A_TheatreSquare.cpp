#include<iostream>
#include<math.h>

using namespace std;

int main(){
    long long n, m, a;
    cin>>n>>m>>a;
    long long x =  (n/a+(n%a==0?0:1))*(m/a+(m%a==0?0:1));
    cout<< x<<"\n";
}