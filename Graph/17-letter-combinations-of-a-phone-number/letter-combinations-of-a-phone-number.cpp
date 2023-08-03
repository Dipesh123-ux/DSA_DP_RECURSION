class Solution {
public:

 string nums[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void solve(int i,string digits,vector<string>&ans,string str=""){
    if(i == digits.size()){
        ans.push_back(str);
        return;
    }

    int digit = digits[i] - '0';

    for(int j = 0; j < nums[digit].size();j++){
        str += nums[digit][j];
        solve(i+1,digits,ans,str);
        str.pop_back();
    }

}
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0){
            return ans;
        }
        solve(0,digits,ans);
        return ans;
    }
};