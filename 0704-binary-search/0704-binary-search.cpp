class Solution {
public:
    int search(vector<int>& n, int t) {

        int l = 0;
        int r = n.size() - 1;

        while(l <= r) {

            int mid = l + (r - l) / 2;

            if(n[mid] == t) {
                return mid;
            }
            else if(n[mid] < t) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return -1;
    }
};