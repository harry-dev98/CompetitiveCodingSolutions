#include<bits/stdc++.h>
using namespace std;


// {   int low = 1, high = n, mid, g;
//     while(low < high){
//         mid = low + (high - low + 1) /2;
//         g = guess(mid);
//         if(g == 0)return mid;
//         else if(g == 1) low = mid+1;
//         else high = mid-1;
//     }
//     return high;
// }

// {   int low = 1, high = n+1, mid, g;
//     while(low < high){
//         mid = (high + low) /2;
//         g = guess(mid);
//         if(g == 0)return mid;
//         else if(g == 1) low = mid+1;
//         else high = mid;
//     }
//     return high;
// }

int main(){
    int n = 9;
    int A[] = {22, 17, 12, 9, 4, 3, -1, -4, -5};
    int low, high, mid;
    low = 0; high = n;
    int ans = 0;
    while(low < high){
        mid = (low + high)/2;
        if(A[mid] > 0){
            if(A[mid+1] < 0){
                ans += (high - mid - 1);
                
            }

        }
    }
}