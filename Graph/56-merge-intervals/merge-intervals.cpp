class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int i = 0;
        int j = 1;
        int a = intervals[i][0];
        int b = intervals[i][1];

        while(j < intervals.size()){
            if(b >= intervals[j][0]){
                b = max(b,intervals[j][1]);
            }
            else{
                vector<int> v;
                v.push_back(a);
                v.push_back(b);
                ans.push_back(v);
                i = j;
                a = intervals[i][0];
                b = intervals[j][1];
            }
            j++;
        }

        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        ans.push_back(v);

        return ans;
    }
};