class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> prev(5,1), curr(5,1);
        for(int i = 2; i <= n; i++){
            for(int j = 3; j >= 0; j--){
                curr[j] = curr[j+1] + prev[j];
            }
            prev = curr;
        }
        int s = 0;
        for(auto i : prev){
            s += i;
        }

        return s;
    }
};