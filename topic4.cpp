#include <iostream>
#include <vector>
using namespace std;
/* 
题目：
在一个二维数组中，每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个函数，
输入这样的一个二维数组和一个证书，判断数组中是否含有该整数

例子：
1 2 8 9
2 4 9 12
4 7 10 13
6 8 11 15
*/
class Solution
{
public:
    // Time complexity O(max(input_matrix.rows, input_matrix.columns))
    // Space complexity O(1)
    bool findMatrix(vector<vector<int>> &nums, int number)
    {
        if (nums.size() < 1 || nums[0].size() < 1)
        {
            return false;
        }
        // 求出矩阵中行数和列数
        int columns = nums[0].size(), rows = nums.size();
        // 从矩阵右上角寻找
        int row = 0;
        int column = columns - 1;
        while (row < rows && column >= 0)
        {
            // 情况1：当前遍历的值与查询值相等，返回true
            if (nums[row][column] == number)
            {
                return true;
            }
            // 情况2：当前遍历的值小于查询值，表示那一行中最大的数比查询值小（肯定不在这一行中），表示那一列中最小的数比查询值小（此信息无作用），就去掉那一行（缩小查找范围）
            else if (nums[row][column] < number)
            {
                row++;
            }
            // 情况3：当前遍历的值大于查询值，表示那一列中最小的数比查询值大（肯定不在这一列中），表示那一行中最大的数比查询值大（此信息无作用），就去掉那一列
            else
            {
                column--;
            }
        }
        return false;
    }
};
int main()
{
    vector<vector<int>> nums{{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Solution s;
    bool result = s.findMatrix(nums, 2);
    return 0;
}