class Solution {
public:
    string reorganizeString(string s) {
  
      vector<int> charFrequencies(26,0);

    for (char c : s) {
        charFrequencies[c - 'a']++;
    }

     std::vector<std::pair<char, int>> charFreqPairs;
    for (int i = 0; i < 26; ++i) {
        if (charFrequencies[i] > 0) {
            charFreqPairs.push_back(std::make_pair('a' + i, charFrequencies[i]));
        }
    }
    
    // Sort the vector of pairs in descending order of frequencies
    std::sort(charFreqPairs.begin(), charFreqPairs.end(),
              [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
                  return a.second > b.second;
              });


      int i = 0;
      
      int count = s.size();



      if(charFreqPairs[0].second > (s.size()+1)/2){
          return "";
      }

    
    string res(count,' ');
    int m = 0;


      for(int i = 0; i < charFreqPairs.size();i++){
          int k = charFreqPairs[i].second;
          for(int j = 0; j < k;j++){
              if(m >= count){
                  m = 1;
              }
              res[m] = charFreqPairs[i].first;
              m += 2;
          }
      }



// if(s2.size() != count){
//     return "";
// }



        return res;
    }
};