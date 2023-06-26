/**
 * Created by 史进 on 2023/1/28.
 *
 * 给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
 * 回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * 例如，121 是回文，而 123 不是。
 *
 */
#include <string>
using namespace std;

class Solution {
public:
    // 普通解法：转成字符串
    bool isPalindrome(int x) {
        if(x<0  || (x%10==0 && x!=0)){
            return false;
        }
        string str = to_string(x);
        int len = str.size();
        for (int i = 0; i < len/2; ++i) {
            if (str[i] != str[len-1-i]){
                return false;
            }
        }
        return true;
    }

    // 数字反转（一半）
    bool isPalindrome1(int x){
        if (x<0 || (x%10==0 && x!=0))
            return false;

        int ret = 0;
        while(ret<x){
            ret = ret*10 + x%10;
            x /= 10;
        }

        return x==ret || x==ret/10;
    }
};