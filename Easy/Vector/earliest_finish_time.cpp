#include<bits/stdc++.h>
using namespace std;

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        int res = INT_MAX;

        for(int i = 0; i < landStartTime.size();i++){
            for(int j = 0; j < waterStartTime.size();j++){
               res = min(res, max(landStartTime[i] + landDuration[i], waterStartTime[j]) + waterDuration[j]);

               res = min(res, max(waterStartTime[j] + waterDuration[j], landStartTime[i]) + landDuration[i]);


            }
        }




        return res;
    }
int main() {
    int n, m;
    cin >> n >> m;

    vector<int> landStartTime(n), landDuration(n);
    vector<int> waterStartTime(m), waterDuration(m);

    for (int i = 0; i < n; i++) cin >> landStartTime[i];
    for (int i = 0; i < n; i++) cin >> landDuration[i];
    for (int i = 0; i < m; i++) cin >> waterStartTime[i];
    for (int i = 0; i < m; i++) cin >> waterDuration[i];

    cout << earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration);

    return 0;
}