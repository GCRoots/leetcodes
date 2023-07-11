/**
 * Created by 史进 on 2023/6/30.
 *
 * 7. 整数反转
 *
 * 给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
 * 如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。
 * 假设环境不允许存储 64 位整数（有符号或无符号）。
 *
 * 示例 1：
 * 输入：x = 123
 * 输出：321
 *
 * 示例 2：
 * 输入：x = -123
 * 输出：-321
 *
 * 示例 3：
 * 输入：x = 120
 * 输出：21
 *
 * 示例 4：
 * 输入：x = 0
 * 输出：0
 *
 */
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int new_x = 0;
        while ( x != 0){
            if (new_x > INT_MAX/10 || new_x < INT_MIN/10) return 0;
            new_x = new_x*10 + x%10;
            x /= 10;
        }

        return new_x;

    }
};