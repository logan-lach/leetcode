#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        bool checkValidCuts(vector<vector<int>>& grid, int n)
        {
            vector<vector<int>> xIntervals;
            vector<vector<int>> yIntervals;
            for (const vector<int>& items : grid)
            {
                xIntervals.push_back({items[0], items[2]});
                yIntervals.push_back({items[1], items[3]});
            }

            const static auto lambda = [](vector<int>& a1, vector<int>& a2) // Not sure if these take references or not
            {
                if (a1[0] == a2[0])
                {
                    return a1[1] < a2[1];
                }
                return a1[0] < a2[0];
            };

            sort(xIntervals.begin(), xIntervals.end(), lambda);
            sort(yIntervals.begin(), yIntervals.end(), lambda);

            vector<int> currGroup = xIntervals[0];
            int currSize = 1;
            for (int i = 1; i < xIntervals.size(); i ++)
            {
                if (xIntervals[i][0] < currGroup[1])
                {
                    currGroup[0] = min(currGroup[0], xIntervals[i][0]);
                    currGroup[1] = max(currGroup[1], xIntervals[i][1]);
                }
                else
                {
                    ++currSize;
                    currGroup = xIntervals[i];
                    if (currSize >= 3)
                    {
                        break;
                    }
                }
            }

            if (currSize >= 3)
            {
                return true;
            }

            vector<int> currGroup = yIntervals[0];
            int currSize = 1;
            for (int i = 1; i < yIntervals.size(); i ++)
            {
                if (yIntervals[i][0] < currGroup[1])
                {
                    currGroup[0] = min(currGroup[0], yIntervals[i][0]);
                    currGroup[1] = max(currGroup[1], yIntervals[i][1]);
                }
                else
                {
                    ++currSize;
                    currGroup = yIntervals[i];
                    if (currSize >= 3)
                    {
                        break;
                    }
                }
            }

            return currSize >= 3;
        }
};