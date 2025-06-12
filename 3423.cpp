class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = 0;
        for (int i = 1; i < nums.size(); i ++)
        {
            maxDiff = max(maxDiff, abs(nums[i] - nums[i-1]));
        }
        return max(maxDiff, std::abs(nums[0] - nums[nums.size() - 1]));
    }
};
