//translated using AI
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> ct(n + 1, 0);

        for(int x : arr){
            ct[min(x, n)]++;
        }

        int val = 0;
        for(int i = 1; i <= n; i++){
            val = min(i, val + ct[i]);
        }

        return val;
    }
};