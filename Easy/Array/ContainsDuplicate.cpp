#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;

        for(int num : nums){
            if(st.count(num)){
                return true;
            }
            st.insert(num);
        }

        return false;
    }


int main()
{
    vector<int> nums = {1, 2, 3, 1};

    cout << (containsDuplicate(nums) ? "true" : "false") << endl;

    return 0;
}