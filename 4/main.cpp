#include <iostream>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int prev = (m + n + 1)/2; // the prev'th smallest
        int cur = (m + n + 2)/2;
        //将偶数和奇数的情况合并，如果是奇数，会求两次同样的 k
        int res1 = merge(nums1, 0, m-1, nums2, 0, n-1, prev);
        int res2 = merge(nums1, 0, m-1, nums2, 0, n-1, cur);
        cout << res1 << " " << res2;
        return (res1 + res2) * 0.5;
    }
private:
    int merge(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k){
        // find the kth smallest item in nums1 & nums2
        // start1, end1, start2, end2: indexes of vector
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;
        // make nums1 the shorter one
        if(len2 < len1) return merge(nums2, start2, end2, nums1, start1, end1, k);
        if(len1 == 0) return nums2[start2 + k - 1];

        if(k == 1) return min(nums1[start1], nums2[start2]);
        int mid1 = start1 + min(len1, k/2) - 1;
        int mid2 = start2 + min(len2, k/2) - 1;
        if(nums1[mid1] > nums2[mid2]){
            // remove the items [start2....mid2]
            return merge(nums1, start1, end1, nums2, mid2+1, end2, k - (mid2-start2+1));
        }else{
            return merge(nums1, mid1+1, end1, nums2, start2, end2, k-(mid1-start1+1));
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
