class Solution {
public:
    long long solve(vector<int>& a, vector<int>& b,
                    vector<int>& c, vector<int>& d) {

        int m = c.size();
        vector<pair<int,int>> v;

        for(int i = 0; i < m; i++)
            v.push_back({c[i], d[i]});

        sort(v.begin(), v.end());

        vector<int> pref(m);
        vector<long long> suff(m);

        pref[0] = v[0].second;
        for(int i = 1; i < m; i++)
            pref[i] = min(pref[i - 1], v[i].second);

        suff[m - 1] = 1LL * v[m - 1].first + v[m - 1].second;
        for(int i = m - 2; i >= 0; i--)
            suff[i] = min(suff[i + 1],
                          1LL * v[i].first + v[i].second);

        long long res = LLONG_MAX;

        for(int i = 0; i < a.size(); i++) {
            long long x = 1LL * a[i] + b[i];

            int pos = upper_bound(
                v.begin(), v.end(),
                make_pair((int)x, INT_MAX)
            ) - v.begin();

            if(pos) res = min(res, x + pref[pos - 1]);
            if(pos < m) res = min(res, suff[pos]);
        }

        return res;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        return min(
            solve(landStartTime, landDuration,
                  waterStartTime, waterDuration),

            solve(waterStartTime, waterDuration,
                  landStartTime, landDuration)
        );
    }
};