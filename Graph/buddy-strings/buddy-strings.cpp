class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s == goal){
            set<char> temp(s.begin(),s.end());
            return temp.size() < goal.size();
        }
        int prev = -1;
        for(int i = 0; i < s.size();i++){
           if(s[i] != goal[i]){
               if(prev == -1){
                   prev = i;
               }
               else{
                   swap(s[i],s[prev]);
                   break;
               }
           }
        }

        return s == goal;
    }
};