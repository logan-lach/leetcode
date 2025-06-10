class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        
        int currBest = 0;
        vector<long long> holder(questions.size());
        for (int i = questions.size() - 1; i >= 0; i --)
        {
            int pointValue = questions[i][0];
            int skips = questions[i][1];
            int reach = i + skips;
            int questionCombo = 0;
            if (i + skips + 1 < questions.size())
            {
                questionCombo = holder[i + skips + 1];
            }

            long long withReachScore = pointValue + questionCombo;
            int tracker = questions.size() - 1;
            if (reach < questions.size())
            {
                tracker = reach;
            }

            long long bestSkipScore = 0;
            while (tracker > i)
            {
                bestSkipScore = max(holder[tracker], bestSkipScore);
                tracker --;
            }

            holder[i] = max(bestSkipScore, withReachScore);
        }
        return holder[0];
    }
};