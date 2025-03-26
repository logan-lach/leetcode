#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> holder;
        for (const int& item : nums)
        {
            ++ holder[item];
        }

        sort(nums.begin(), nums.end(), [&holder](int a, int b) {
            if (holder[a] == holder[b])
            {
                return a > b;
            }
            return holder[a] < holder[b];
        });

        return nums;
    }
};