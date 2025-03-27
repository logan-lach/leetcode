#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        /*
            We need to find the dominant element

            We can do that in one pass

            And then, on the second pass
                increment right until dom num is dominant on both sides


        */

        map<int, int> dominantNum;
        int currDom = nums[0];
        for (int num : nums)
        {
            dominantNum[num] += 1;
            currDom = dominantNum[num] > dominantNum[currDom] ? num : currDom;
        }

        int totalDoms = dominantNum[currDom];
        int countLeft = 0;
        for (int i = 0; i < nums.size(); i ++)
        {
            if (nums[i] == currDom)
            {
                ++countLeft;
            }

            bool leftSideValid = countLeft > ((i + 1) / 2);
            bool rightSideValid = (dominantNum[currDom] - countLeft) > ((nums.size() - 1 - i) / 2);
            if (leftSideValid && rightSideValid)
            {
                return i;
            }
        }
        return -1;
    }
};