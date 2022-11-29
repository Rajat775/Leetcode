class Solution {
public:
    bool containsDuplicate(vector<int>& vec) {
        sort(vec.begin(), vec.end());
        for(int i=0;i<vec.size()-1;i++) {
            if(vec[i] == vec[i + 1]) return true;
        }
        return false;
    }
};