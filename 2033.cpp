#include <vector>

using namespace std;

class Solution
{
    public:
        int minOperations(vector<vector<int>>& grid, int x)
        {
            vector<int> v;
            for (const vector<int>& row : grid)
            {
                v.insert(v.end(), row.begin(), row.end());
            }

            sort(v.begin(), v.end());

            int median = v[v.size() / 2];

            int ans = 0;
            int goodRemainder = v[0] % x;
            for (int i : v)
            {
                if (i % x != goodRemainder)
                {
                    return -1;
                }
                ans += abs(i - median) / x;
            }

            return ans;
        }
};