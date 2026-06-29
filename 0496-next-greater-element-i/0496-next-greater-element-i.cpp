class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {

        unordered_map<int,int> mp;
        stack<int> st;

        for(int x : n2) {

            while(!st.empty() && x > st.top()) {
                mp[st.top()] = x;
                st.pop();
            }

            st.push(x);
        }

        while(!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }

        vector<int> ans;

        for(int x : n1) {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};