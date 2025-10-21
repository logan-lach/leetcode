class Solution {
public:
    string longestPalindrome(string s) {
        
        if (s.size() == 1)
        {
            return s;
        }
        int currLongest = 0;
        string bestString = "";
        for (int i = 0; i < s.size() - 1; i ++)
        {
            // Count odd from here
            int leftPtr = i;
            int rightPtr = i;
            int currScore = -1;
            while (leftPtr >= 0 && rightPtr < s.size() && s[leftPtr] == s[rightPtr])
            {
                leftPtr --;
                rightPtr ++;
                currScore += 2;
            }
            
            
            if (currScore > currLongest)
            {
                currLongest = currScore;
                bestString = s.substr(leftPtr + 1, currScore);
                cout << "indicies: leftPtr  " << leftPtr << " right ptr " << rightPtr << endl;
                cout << "best string: " << bestString << endl;
            }
            
            // Count even from here
             // Count odd from here
            leftPtr = i;
            rightPtr = i + 1;
            currScore = 0;
            while (leftPtr >= 0 && rightPtr < s.size() && s[leftPtr] == s[rightPtr])
            {
                leftPtr --;
                rightPtr ++;
                currScore += 2;
            }
            
            if (currScore > currLongest)
            {
                currLongest = currScore;
                bestString = s.substr(leftPtr + 1, currScore);
                cout << "indicies: leftPtr  " << leftPtr << " right ptr " << rightPtr << endl;
                cout << "best string: " << bestString << endl;
            }
        }
        return bestString;
    }
};