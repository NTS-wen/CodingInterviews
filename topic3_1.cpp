#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
/* 
题目：找出数组中重复的数字
在一个长度为n的数组里所有数字都在0~n-1的范围内。
数组中某些数字是重复的，但不知道有几个数字重复了，
也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

例子：
如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
那么对应的输出是重复的数字2或3。
*/
class Solution
{
public:
    // 方法一：排序后，按顺序直接查找，当碰到遍历的后一个数和当前的数相等时就返回
    // Time complexity O(nlogn)
    // Space complexity O(1)
    int repeatNum4(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return -1;
        }
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return nums[i];
            }
        }
        return -1;
    }
    // 方法二：需利用一个额外的hash_map存储
    // Time complexity O(n)
    // Space complexity O(n)
    int repeatNum1(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return -1;
        }
        unordered_map<int, int> cache;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (cache.find(nums[i]) != cache.end())
            {
                return nums[i];
            }
            else
            {
                cache.insert(make_pair(nums[i], i));
            }
        }
        return -1;
    }
    // 方法三：进一步，查询的时候两边同时查
    // Time complexity O(n)
    // Space complexity O(n)
    int repeatNum2(vector<int> &nums)
    {
        int result = -1;
        if (nums.size() <= 1)
        {
            return -1;
        }
        unordered_map<int, int> cache;
        int iter_max = nums.size() / 2;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            if (cache.find(nums[right]) != cache.end())
            {
                return nums[right];
            }
            else
            {
                cache.insert(make_pair(nums[right], right));
                right--;
            }

            if (cache.find(nums[left]) != cache.end())
            {
                return nums[left];
            }
            else
            {
                cache.insert(make_pair(nums[left], left++));
                left++;
            }
        }
        return result;
    }

    // 方法四：再利用一个数组作为Hash表
    // Time complexity O(n)
    // Space complexity O(n)
    int repeatNum3(vector<int> &nums)
    {
        vector<int> cache(nums.size(), -1);
        for (size_t i = 0; i < nums.size(); i++)
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
    // 方法五：最优解，思想是遍历这个数组过程中，判断这个数字（用m表示）是不是等于下标，
    //如果是就跳过，如果不是就拿m与第m哥数字进行比较，
    // 如果相等就找到了，如果不等，就将m与第m个数字进行交换。
    // Time complexity O(n)
    // Space complexity O(1)
    int repeatNum5(vector<int> &nums)
    {
        for (size_t i = 0; i < nums.size(); i++)
        {
            while (nums[i] != i)
            {
                if (nums[i] == nums[nums[i]])
                {
                    return nums[i];
                }
                // swap nums[i] and nums[nums[i]]
                int temp = nums[i];
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }
        return -1;
    }
};
int main()
{
    vector<int> nums{2, 3, 1, 0, 2, 5, 3};
    Solution s;
    int result = s.repeatNum5(nums);
    return 0;
}
