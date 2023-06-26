/**
 * Created by 史进 on 2022/9/21.
 *
 * 26. 删除有序数组中的重复项
 *
 * 给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，
 * 使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。
 *
 * 不要使用额外的空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
 *
 * 示例 1：
 *  输入：nums = [1,1,2]
 *  输出：2, nums = [1,2,_]
 *  解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。
 *  不需要考虑数组中超出新长度后面的元素。
 *
 * 示例 2：
 *  输入：nums = [0,0,1,1,1,2,2,3,3,4]
 *  输出：5, nums = [0,1,2,3,4]
 *  解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。
 *  不需要考虑数组中超出新长度后面的元素。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 暴力拆解
     * leetcode报错，数组下标越界
     *
     * while (nums[i]==nums[j] && j<len)
     * 改为
     * while (j<len && nums[i]==nums[j])
     * @param nums
     * @return
     */
    int removeDuplicates(vector<int>& nums) {
        int len=nums.size();

        if (len == 0) return 0;

        for (int i = 0 ; i < len-1 ; ++i) {
            int j=i+1;
            int balance=0;

            //重复元素
            while ( j<len && nums[i]==nums[j]){
                j++;
                balance++;
            }

            //前移
            if (balance!=0){
                while (j<len){
                    nums[j-balance]=nums[j];
                    j++;
                }
                len-=balance;
            }

        }
        return len;
    }

    /**
     * 快慢双指针
     *
     * @param nums
     * @return
     */
    int removeDuplicates1(vector<int>& nums){
        int len=nums.size();

        if (len == 0) return 0;

        int slow=1,fast=1;

        while (fast<len){
            if (nums[fast]!=nums[fast-1]){
                nums[slow]=nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};

int main(){
    Solution solution{};

    vector<int> vector(2);
    vector[0]=1;
    vector[1]=1;
    cout<<solution.removeDuplicates(vector);
    return 0;
}