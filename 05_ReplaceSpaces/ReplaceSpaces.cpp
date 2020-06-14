#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/* 
题目：
请实现一个函数，把字符串中的每个空格替换成“%20”。
例如，输入“We are happy.”，则输出“We%20are%20happy.”。
*/
class Solution
{
public:
    // 不在原来的字符串上修改，再用另外一个字符串来存
    // Time complexity O(n)
    // Space complexity O(n)
    static string replaceSpaces1(string &instring)
    {
        if (instring.size() < 1)
            return "";
        string result;
        for (size_t i = 0; i < instring.size(); i++)
        {
            if (instring[i] == ' ')
            {
                result += "%20";
            }
            else
            {
                result += instring[i];
            }
        }
        return result;
    }
    // 在原来的字符串上修改，遍历字符串，查到空格，字符串后面的字符就全部后移, 遍历字符串后利用字符串的replace函数进行替换
    // Time complexity O(n^2)
    // Space complexity O(1)
    static bool replaceSpaces2(string &instring)
    {
        if (instring.size() < 1)
            return "";

        for (size_t i = 0; i < instring.size(); i++)
        {
            if (instring[i] == ' ')
            {
                instring.replace(i, 1, "%20");
            }
        }

        return true;
    }

    // 在原来的字符串上修改，遍历字符串，查到空格，字符串后面的字符就全部后移，不利用replace函数。
    // Time complexity O(n^2)
    // Space complexity O(1)
    static bool replaceSpaces3(string &instring)
    {
        if (instring.size() < 1)
        {
            return false;
        }
        for (size_t i = 0; i < instring.size(); i++)
        {
            if (instring[i] == ' ')
            {
                // 将原字符串的"倒数第二个字符"添加在新字符串末尾
                instring.push_back(instring[instring.size() - 2]);
                // 将原字符串的"倒数第一个字符"添加在新字符串末尾
                instring.push_back(instring[instring.size() - 2]);
                // 对字符串中需要向后移动两个字符的一一进行移动
                for (size_t j = instring.size() - 3; j > i + 2; j--)
                {
                    instring[j] = instring[j - 2];
                }
                //最后在原空格位置添加"%20"
                instring[i] = '%';
                instring[i + 1] = '2';
                instring[i + 2] = '0';
            }
        }
        return true;
    }

    // 利用双指针，开始指针1指向应该添加字符的位置，另一个指针2指向新字符串末尾。
    // 然后指针1从后往前扫描，如碰到一个空格，指针2处就往前添加0 2 %字符，
    // 最后当指针1到达起始点、或者指针1和指针2指向同一个位置时，结束循环。
    // Time complexity O(n)
    // Space complexity O(1)
    static bool replaceSpaces4(string &instring)
    {
        if (instring.size() < 1)
        {
            return false;
        }
        int indexOfOrigin = instring.size() - 1;
        for (size_t i = 0; i < instring.size(); i++)
        {
            // 如果碰到空格，就向字符串末尾添加两个任意字符串，空格除外。
            if (instring[i] == ' ')
            {
                instring.append("..");
            }
        }
        int indexOfNew = instring.size() - 1;
        // 从原字符串末尾开始遍历，如碰到空格，就在新字符串末尾处添加%20，指针自减。
        // 未碰到就将原字符串复制到新字符串中，然后指针自减。
        while (indexOfOrigin >= 0 && indexOfOrigin < indexOfNew)
        {
            if (instring[indexOfOrigin] == ' ')
            {
                instring[indexOfNew--] = '0';
                instring[indexOfNew--] = '2';
                instring[indexOfNew--] = '%';
            }
            else
            {
                instring[indexOfNew--] = instring[indexOfOrigin];
            }
            indexOfOrigin--;
        }
        return true;
    }
};
int main()
{
    string inputstring = "We are happy.";
    bool result = Solution::replaceSpaces4(inputstring);
    return 0;
}