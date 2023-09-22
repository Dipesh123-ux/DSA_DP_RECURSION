class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < s.size() && j < t.size()){
            if(t[j] == s[i]){
                i++;
                k++;
            }
            j++;
        }

        return (k == s.size());
    }
};