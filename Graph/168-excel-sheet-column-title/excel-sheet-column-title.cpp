class Solution {
public:
    string convertToTitle(int c) {
        string s = "";
        double n = c;

        while(c > 0){
            int rem = (c-1) % 26;
            s += (rem + 64+1);
            c = (c-1) / 26;
        }
         
    

        reverse(s.begin(),s.end());

        return s;

        
    }
};