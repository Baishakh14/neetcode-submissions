class Solution {
public:
    vector<int> partitionLabels(string s) {
          vector<int>ans;
          string now;
          vector<int>fre(26,0);
          for(auto it : s)
          {
            fre[it-'a']++;
          }
          for(auto it : s)
          {
            now.push_back(it);
            fre[it - 'a']--;
            bool ok = true;
            for(int i = 0;i<now.size();i++)
            {
                if(fre[now[i] - 'a'] > 0) ok = false;
            }
            if(ok)
            {
                ans.push_back(now.size());
                now.clear();
            }
          }
          return ans;
    }
};
