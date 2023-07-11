/**
 * Created by 史进 on 2023/6/28.
 *
 * 5. 最长回文子串
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。
 *
 * 示例 1：
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 *
 * 示例 2：
 * 输入：s = "cbbd"
 * 输出："bb"
 *
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        if (length == 1) return s;
        string sub = s.substr(0, 1);
        int max_sub = 1;

        for (int i = 0; i < length; ++i) {
            int right = i, left = length-1;
            while (left > i){
                int end = left;
                while (s[right] == s[left] && right < left){
                    ++right;
                    --left;
                }
                if (right >= left && end-i+1 > max_sub){
                    sub = s.substr(i, end-i+1);
                    max_sub = end-i+1;
                } else{
                    left = end - 1;
                    right = i;
                }
            }

        }
        return sub;


    }
};




