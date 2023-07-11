/**
 * Created by 史进 on 2023/7/3.
 *
 * 11. 盛最多水的容器
 *
 *  给定一个长度为 n 的整数数组 height 。
 *  有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
 *  找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 *  返回容器可以储存的最大水量。
 *
 *  说明：你不能倾斜容器。
 *
 * 示例 1：
 * 输入：[1,8,6,2,5,4,8,3,7]
 * 输出：49
 *
 * 示例 2：
 * 输入：height = [1,1]
 * 输出：1
 * */
#include <vector>

using namespace std;

class Solution {
public:
    // 超时
    int maxArea1(vector<int>& height) {
        int len = height.size();
        if (len == 2) return min(height[0], height[1]);

        int max_area = 0;
        for (int i = 0; i < len-1; ++i) {
            for (int j = i+1; j < len; ++j) {
                int tmp_area = (j-i) * min(height[i], height[j]);
                if (tmp_area > max_area)
                    max_area = tmp_area;
            }
        }

        return max_area;
    }

    // 双指针
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int max_area = 0;

        while (i < j){

//            max_area = height[i] > height[j] ?
//                       max(max_area,((j-i) * height[j--])):
//                       max(max_area,((j-i) * height[i++]));

            if (height[i] > height[j]){
                max_area = max(max_area,((j-i) * height[j]));
                --j;
            } else{
                max_area = max(max_area,((j-i) * height[i]));
                ++i;
            }
        }

        return max_area;
    }
};