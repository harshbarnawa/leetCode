class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;

        for (int x = num1; x <= num2; x++) {
            string s = to_string(x);
            for (int i = 1; i + 1 < s.size(); i++)
                ans += (s[i] > s[i - 1] && s[i] > s[i + 1]) || (s[i] < s[i - 1] && s[i] < s[i + 1]);
        }





        return ans;
    }
};
