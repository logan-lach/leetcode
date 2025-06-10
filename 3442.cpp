#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        vector<int> characters (26, 0);

        for (char c : s)
        {
            characters[c - 'a'] ++;
        }

        int smallestEven = INT_MAX;
        int largestOdd = -1;

        for (int i = 0; i < characters.size(); i ++)
        {
            if (characters[i] == 0)
            {
                continue;
            }

            if (characters[i] % 2 == 0)
            {
                smallestEven = min(smallestEven, characters[i]);
            }
            else
            {
                largestOdd = max(largestOdd, characters[i]);
            }

        }
        return largestOdd - smallestEven;
    }
};
