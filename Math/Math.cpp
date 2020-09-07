#include<iostream>
using namespace std;

long long binPow(long long a, long long b){
    long long res = 1;
    while(b > 0){
        if(b & 1){
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}


long long binPow(long long a, long long b, long long m){
    a %= m;
    long long res = 1;
    while(b > 0){
        if(b&1){
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

long long gcd(long long a, long long b){
    while(b){
        a %= b;
        swap(a, b);
    }
    return a;
}

