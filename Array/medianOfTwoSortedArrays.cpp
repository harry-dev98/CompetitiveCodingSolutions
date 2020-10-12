// in O(log(n+m))

#include<bits/stdc++.h>
using namespace std;

double  findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    int n = nums1.size();
    int m = nums2.size();
    int reqEle = (n + m + 1)/2;
    if(n < m)return findMedianSortedArrays(nums2, nums1);
    int mid1, mid2, l = 0, h = (n + m) / 2; // range of elements nums1 could contribute provided nums1.size > nums2.size
    while(l <= h){
        mid1 = l + (h-l+1)/2;
        mid2 = reqEle - mid1;
        if(nums1[mid1] > nums2[mid2+1]){
            h = mid1 - 1;
        }
        else if(nums1[mid1+1] < nums2[mid2]){
            l = mid1 + 1;
        }
        else{
            if(nums1[mid1] > nums2[mid2]){
                ans = nums1[mid1];
            }
        } 
    }

}

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> N(n), M(m);
    for(int& _: N)cin>>_;
    for(int& _: M)cin>>_;
    cout<<findMedianSortedArrays(N, M)<<"\n";
    return 0;
}