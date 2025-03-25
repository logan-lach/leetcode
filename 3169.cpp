#include <vector>
#include <algorithm>  // for sort
#include <utility>   // for min/max

using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        /*
            Need to find overlapping meeting times

            We should sort the meetings first
        */

        static const auto lambda = [](const vector<int>& a1, const vector<int>& a2) {
            return a1[0] != a2[0] ? a1[0] < a2[0] : a1[1] < a2[1];
        };

        sort(meetings.begin(), meetings.end(), lambda);

        vector<int> currGrouping = meetings[0];
        int count = meetings[0][0] - 1;
        for (int i = 1; i < meetings.size(); i++)
        {
            if (meetings[i][0] <= currGrouping[1])
            {
                currGrouping[0] = min(currGrouping[0], meetings[i][0]);
                currGrouping[1] = max(currGrouping[1], meetings[i][1]);
            }
            else
            {
                count += meetings[i][0] - currGrouping[1] - 1;
                currGrouping = meetings[i];
            }
        }
        return count + (days - currGrouping[1]);
    }
};