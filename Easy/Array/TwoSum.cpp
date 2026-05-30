#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         unordered_map<int, int> mp;
        for(int i = 0;i < nums.size();i++) {

            int curr = target - nums[i]; 
            if(mp.find(curr) != mp.end()) {
                return {mp[curr], i};
            }


            mp[nums[i]] = i;
        }

        return {};
    
        
    }
};

int main() {

    Solution obj;

    vector<int> nums = {2,7,11,15};
    int target = 9;

    vector<int> ans = obj.twoSum(nums, target);

    cout << ans[0] << " " << ans[1];

    return 0;
}