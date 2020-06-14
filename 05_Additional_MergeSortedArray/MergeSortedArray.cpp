#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/* 
题目：
有两个排序的数组A1和A2，内存在A1的末尾有足够多的空余空间容纳A2。
请实现一个函数，把A2中的所有数字插入A2中，并且所有的数组是排序的。
*/
class Solution
{
public:
    // 利用双指针，开始指针1指向数组A1的尾部，另一个指针2指向数组A2的尾部。
    // 然后指针1从后往前扫描，如碰到一个空格，指针2处就往前添加0 2 %字符，
    // 最后当指针1到达起始点、或者指针1和指针2指向同一个位置时，结束循环。
    // Time complexity O(n)
    // Space complexity O(1)
    static bool mergeSortedArray(vector<int> &array1, const vector<int> array2)
    {
        int indexOfArray1 = array1.size() - 1;
        int indexOfArray2 = array2.size() - 1;
        int indexOfArrayNew = array1.size() + array2.size() - 1;
        array1.resize(indexOfArrayNew + 1, 0);
        while (indexOfArray2 >= 0)
        {
            if (indexOfArray1 < 0)
            {
                array1[indexOfArrayNew] = array2[indexOfArray2--];
            }
            else
            {
                if (array2[indexOfArray2] >= array1[indexOfArray1])
                {
                    array1[indexOfArrayNew] = array2[indexOfArray2--];
                }
                else
                {
                    array1[indexOfArrayNew] = array1[indexOfArray1--];
                }
            }
            indexOfArrayNew--;
        }
        return true;
    }
};
int main()
{
    vector<int> array1{1};
    vector<int> array2{};
    bool result = Solution::mergeSortedArray(array1, array2);
    return 0;
}