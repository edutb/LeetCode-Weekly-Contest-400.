class Solution
{
public:
    unordered_map<int, long long> memo;
    map<int, long long> spell;

    long long f(map<int, long long>::iterator cur)
    {
        if (cur == spell.end())
            return 0;
        if (memo.find(cur->first) != memo.end())
            return memo[cur->first];

        long long ans = f(next(cur));
        long long damage = cur->first * cur->second;
        int block = cur->first + 2;
        auto next_spell = next(cur);
        while (next_spell != spell.end() && next_spell->first <= block)
            next_spell++;
        ans = max(ans, damage + f(next_spell));
        return memo[cur->first] = ans;
    }

    long long maximumTotalDamage(vector<int> &power)
    {

        for (auto &v : power)
            spell[v]++;
        return f(spell.begin());
    }
};