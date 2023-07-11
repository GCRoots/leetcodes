/**
 * Created by 史进 on 2023/6/26.
 *
 * 4. 寻找两个正序数组的中位数
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
 * 请你找出并返回这两个正序数组的 中位数 。
 * 算法的时间复杂度应该为 O(log (m+n)) 。
 *
 * 示例 1：
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 *
 * 示例 2：
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 */

#include <vector>

using namespace std;

class Solution {
public:
    // 1. 暴力求解：合并后返回中位数
    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
        // m+n是奇数： num[(m+n)/2]
        // m+n是偶数： (num[(m+n)/2] + num[(m+n)/2-1]) /2
        int m = nums1.size();
        int n = nums2.size();

        if (m == 0)
            return n % 2 == 1 ? nums2[n/2] : (nums2[n/2-1] + nums2[n/2]) / 2.0;
        if (n == 0)
            return m % 2 == 1 ? nums1[m/2] : (nums1[m/2-1] + nums1[m/2]) / 2.0;

        vector<int> nums;

        int i, j;
        for (i=0, j=0; i<m && j<n; ){
            if (nums1[i] < nums2[j]){
                nums.push_back(nums1[i++]);
            } else{
                nums.push_back(nums2[j++]);
            }
        }

        while (i < m) nums.push_back(nums1[i++]);
        while (j < n) nums.push_back(nums2[j++]);

        return (n+m)%2 == 1 ? nums[(n+m)/2] : (nums[(n+m)/2-1] + nums[(n+m)/2]) / 2.0;

    }

    // 2. 暴力求解：循环找出中位数，无需合并数组
    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int len = m + n;
        int left =-1, right = -1;
        int pos1 = 0, pos2 = 0;
        for (int i = 0; i <= len/2; ++i){
            left = right;
            if (pos1 < m && (pos2 >= n || nums1[pos1] < nums2[pos2]))
                right = nums1[pos1++];
            else
                right = nums2[pos2++];
        }
        return len % 2 == 1 ? right : (left + right) / 2.0;
    }

    // 3. 二分法：找第K小的元素
    int findKthElement(vector<int>& nums1, vector<int>& nums2, int k){
        int m = nums1.size();
        int n = nums2.size();
        int pos1 = 0, pos2 = 0;

        while (true) {
            // 边界情况
            if (pos1 == m)
                return nums2[pos2+k-1];
            if (pos2 == n)
                return nums1[pos1+k-1];
            if (k == 1)
                return min(nums1[pos1], nums2[pos2]);

            // 正常情况
            int new_pos1 = min(pos1+k/2-1, m-1);
            int new_pos2 = min(pos2+k/2-1, n-1);

            if (nums1[new_pos1] < nums2[new_pos2]){
                k -= new_pos1 - pos1 + 1;
                pos1 = new_pos1+1;
            }else{
                k -= new_pos2 - pos2 + 1;
                pos2 = new_pos2+1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        return len % 2 == 1 ? findKthElement(nums1, nums2, (len+1)/2) :
            (findKthElement(nums1, nums2, len/2)+findKthElement(nums1, nums2, len/2+1))/2.0;
    }
};
