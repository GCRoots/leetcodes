/**
 * Created by 史进 on 2023/6/30.
 *
 * 请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 atoi 函数）。
 *
 * 函数 myAtoi(string s) 的算法如下：
 * 1. 读入字符串并丢弃无用的前导空格.
 * 2. 检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。
 *    确定最终结果是负数还是正数。
 *    如果两者都不存在，则假定结果为正。
 * 3. 读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
 * 4. 将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。
 *    如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
 *
 * 如果整数数超过 32 位有符号整数范围，需要截断这个整数，使其保持在这个范围内。
 * 返回整数作为最终结果。
 *
 * 注意：
 * 本题中的空白字符只包括空格字符 ' ' 。
 * 除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。
 *
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long num = 0;
        int pos = 0;
        int symbol = 1;

        while (s[pos] == ' ') ++pos;

        if (s[pos] == '-' || s[pos] == '+') {
            symbol = s[pos] == '+'? 1 : -1;
            ++pos;
        }

        while (pos < s.size()){
            int tmp = (int)s[pos++];
            if (tmp >= 48 && tmp <= 57){
                num = num * 10 + (tmp - 48);
                if (num > INT_MAX)
                    return symbol == 1 ? INT_MAX : INT_MIN;
            } else
                break;
        }

        return symbol*num;

    }
};