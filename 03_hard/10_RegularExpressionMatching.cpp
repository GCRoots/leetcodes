/**
 * Created by 史进 on 2023/7/1.
 *
 * 10. 正则表达式匹配
 *
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 *
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 *
 * 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
 *
 * 示例 1：
 * 输入：s = "aa", p = "a"
 * 输出：false
 *
 * 示例 2:
 * 输入：s = "aa", p = "a*"
 * 输出：true
 * 解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。
 *      因此，字符串 "aa" 可被视为 'a' 重复了一次。
 *
 */
#include <iostream>
#include <string>

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, pos = 0;
        while (i < s.size()) {
            if (p[pos] == '.' && p[pos+1] == '*'){
                if (pos == p.size()-2) return true;

                char back = p[pos+2];
                if (back != s[i]) ++i;
                ++pos;
                ++pos;
            }

            if (p[pos] == '.'){
                ++pos;
                ++i;
            } else if (p[pos+1] == '*'){
                while (s[i] == p[pos]) ++i;
                ++pos;
                ++pos;
            } else{
                if (p[pos] != s[i])
                    return false;
                ++i;
                ++pos;
            }
        }

        return pos == p.size();


    }

};

