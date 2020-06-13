#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
/* 
题目：不修改数组找出重复的数字
在一个长度为n+1的数组里的所有数字都在1~n的范围内，
所以数组中至少有一个数字是重复的。
请找出数组中任意一个重复的数字，但不能修改输入的数组。

例子：
如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的输出是重复的数字2或者3。
*/
class Solution
{
public:
    // 方法一：采用类似hash的方法，再创建一个数组，遍历整个数组，放进对应的下标中的数组中。
    // Time complexity O(n)
    // Space complexity O(n)
    int repeatNum1(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return -1;
        }
        vector<int> cache(nums.size(), -1);
        for (size_t i = 0; i < nums.size() - 1; i++)
        {
            if (cache[nums[i]] == -1)
            {
                cache[nums[i]] = nums[i];
            }
            else if (cache[nums[i]] == nums[i])
            {
                return nums[i];
            }
        }
        return -1;
    }

    // 方法二：利用二分法的思想，将数据分为大于中值的一部分和小于中值的一部分，找出大于区间个数的部分。
    // Time complexity O(nlogn)，其中：二分查找的时间复杂度为O(logn)；在整个数组中求出区间中有多少个数的时间复杂度为O(n)
    // Space complexity O(1)
    //统计数组中再这个区间范围内有多少个数组
    int countRange(vector<int> nums, int left, int right)
    {
        int count = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= left && nums[i] <= right)
            {
                count++;
            }
        }

        return 0;
    }
    int repeatNum2(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return -1;
        }
        // 题目中数据范围限制在1~n之间，数组个数为n+1，所以left=1、right=nums.size()-1
        int left = 1;
        int right = nums.size() - 1;
        while (right >= left)
        {
            // 利用位运算代替除法
            int middle = ((right - left) >> 1) + left;
            // 在数组中求出这个范围内有多少个数
            int count = countRange(nums, left, middle);
            // 二分查找结束
            if (left == right)
            {
                if (count > 1)
                {
                    return left;
                }
                else
                {
                    break;
                }
            }
            // 二分查找未结束
            // 如果[left, middle]这部分数据的个数大于这部分的间隔，就将右边界缩小为middle
            if (count > (middle - left + 1))
            {
                right = middle;
            }
            // 如果[left, middle]这部分数据的个数小于这部分的间隔，就将左边界扩大为middle
            else
            {
                left = middle + 1;
            }
        }
        return -1;
    }
};
int main()
{
    vector<int> nums{2, 3, 5, 4, 3, 2, 6, 7};
    Solution s;
    int result = s.repeatNum1(nums);
    return 0;
}
