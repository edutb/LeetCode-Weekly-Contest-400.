class Solution
{
public:
    long long countCompleteDayPairs(vector<int> &hours)
    {

        vector<long long> time(24, 0);
        for (auto &h : hours)
            time[h % 24]++;

        long long ans = 0;
        for (int i = 0; i <= 12; i++)
        {
            int left = (24 - i) % 24;
            if (i == left)
                ans += (time[i] * (time[i] - 1)) / 2;
            else
                ans += time[i] * time[left];
        }

        return ans;
    }
};