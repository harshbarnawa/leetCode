class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& n) {

        int m = n.size();
        vector<int> ans(m, -1);

        stack<int> st;

        for(int i = 0; i < 2 * m;i++){

            while(!st.empty() && n[i % m] > n[st.top()]){

                ans[st.top()] = n[i % m];
                st.pop();
            }

            if(i < m){
                st.push(i);
            }
        }

        return ans;
    }
};