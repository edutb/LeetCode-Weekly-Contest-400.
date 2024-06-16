class Solution
{
public:
    vector<int> ft;
    vector<int> nums;
    int n;
#define LSOne(b) b & (-b)

    int isPeak(int i)
    {
        if (i == 0 || i == n - 1)
            return 0;
        return (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]);
    }

    int rsq(int b)
    {
        int ans = 0;
        for (; b; b -= LSOne(b))
            ans += ft[b];
        return ans;
    }

    void update(int b, int val)
    {
        for (; b < ft.size(); b += LSOne(b))
            ft[b] += val;
    }

    int rsq(int x, int y)
    {
        return rsq(y) - rsq(x - 1);
    }

    void adjust(int x)
    {
        if (x <= 0 || x >= n - 1)
            return;
        int cur_value = rsq(x + 1, x + 1);
        int next_value = isPeak(x);
        update(x + 1, next_value - cur_value);
    }

    vector<int> countOfPeaks(vector<int> &nums, vector<vector<int>> &queries)
    {
        n = nums.size();
        this->nums = nums;
        ft.assign(n + 1, 0);

        for (int i = 1; i < n - 1; i++)
        {
            if (isPeak(i))
                update(i + 1, 1);
        }

        vector<int> ans;
        for (auto &q : queries)
        {
            if (q[0] == 1)
            {
                int border = (q[1] == q[2] ? isPeak(q[1]) : isPeak(q[1]) + isPeak(q[2]));
                ans.push_back(rsq(q[1] + 1, q[2] + 1) - border);
            }
            else
            {
                this->nums[q[1]] = q[2];
                adjust(q[1] - 1);
                adjust(q[1]);
                adjust(q[1] + 1);
            }
        }

        return ans;
    }
};