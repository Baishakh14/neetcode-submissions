#include<bits/stdc++.h>
using namespace std;
struct node
{
  int count = 0;
  node *next[26];
};
node *create()
{
  node *now = new node();
  now -> count = 0;
  for(int i = 0;i<26;i++) now -> next[i] = nullptr;
  return now;
}
void add(string s,node *root)
{
  node *now = root;
  for(auto it : s)
  {
    int ind = it - 'a';
    if(now -> next[ind] == nullptr)
    {
      now -> next[ind] = create();
    }
    now = now -> next[ind];
  }
  now -> count++;
}
bool find(string s,int ind,node *root)
{
  if(ind == s.size())
  {
    if(root -> count > 0) return true;
    else return false;
  }
  node *now = root;
  bool ans = false;
  int num = s[ind] - 'a';
  if(s[ind] == '.')
  {
    for(int i = 0;i<26;i++)
    {
      if(now -> next[i] != nullptr)
      {
       ans |= find(s,ind + 1,now -> next[i]);
      }
    }
  }
  else 
  {
    if(now -> next[num] == nullptr) return false;
    else ans |= find(s,ind + 1,now -> next[num]);
  }
  return ans;
}
class WordDictionary {
public:
    node *root = create();
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        add(word,root);
    }
    
    bool search(string word) {
        return find(word,0,root);
    }
};
