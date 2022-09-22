/**
 * Created by 史进 on 2022/9/22.
 *
 * 66. 加一
 *
 * 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 *
 * 示例1：
 *  输入：digits = [1,2,3]
 *  输出：[1,2,4]
 *  解释：输入数组表示数字 123。
 *
 * 示例2：
 *  输入：digits = [4,3,2,1]
 *  输出：[4,3,2,2]
 *  解释：输入数组表示数字 4321。
 *
 * 示例 3：
 *  输入：digits = [0]
 *  输出：[1]
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:

    /**
     * 转换成数字的话，会溢出（leetcode上），所以要另谋他法
     * 我们遇到的情况其实只有两种：该位为9，与该位为其他数
     *
     * 当为9是，加一，继续向前判断
     * 否则，加一，直接返回
     *
     * 当所有位都遍历过且没有返回是，则是各位均为9，创建新数组，长度加一，下标0处置为1，其余为0
     *
     * @param digits
     * @return
     */
    vector<int> plusOne(vector<int>& digits) {
        int len=digits.size();

        for (int i = len-1; i >= 0 ; --i) {
            digits[i]++;
            digits[i]=digits[i]%10;

            //该位不为9
            if (digits[i]!=0) return digits;

        }

        digits = vector<int>(len+1);
        digits[0]=1;

        return digits;

    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> v {9,8,7,6,5,4,3,2,1};
    Solution s;

    s.plusOne(v);

    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<" ";
    }

    return 0;
}