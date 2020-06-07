#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool findMatrix(vector<vector<int>> &nums, int number)
    {
        if (nums.size() < 1 || nums[0].size() < 1)
        {
            return false;
        }
        int columns = nums[0].size(), rows = nums.size();
        int row = 0;
        int column = columns - 1;
        while (row < rows && column >= 0)
        {
            if (nums[row][column] == number)
            {
                return true;
            }
            else if (nums[row][column] < number)
            {
                row++;
            }
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
