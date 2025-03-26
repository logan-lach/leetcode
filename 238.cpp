#include <vector>

using namespace std;

class Solution
{
    public:
        vector<int> productExceptSelf(vector<int>& nums)
        {
            vector<int> list1(nums.size(), 1);
            vector<int> list2(nums.size(), 1);

            // Calculate prefix products
            for (int i = 1; i < nums.size(); i++)
            {
                list1[i] = list1[i-1] * nums[i-1];
            }
            
            // Calculate suffix products
            for (int i = nums.size() - 2; i >= 0; i--)
            {
                list2[i] = list2[i+1] * nums[i+1];
            }

            // Combine prefix and suffix products
            vector<int> result(nums.size());
            for (int i = 0; i < nums.size(); i++)
            {
                result[i] = list1[i] * list2[i];
            }

            return result;
        }
};