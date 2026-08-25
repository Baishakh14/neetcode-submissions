#include<bits/stdc++.h>
using namespace std;
struct node
{
    int count;
    node *next[26];
};
node *create()
{
    node *now = new node();
    now -> count = 0;
    for(int i = 0;i<26;i++)
    {
        now -> next[i] = nullptr;
    }
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
bool find(string s,node *root)
{
    node *now = root;
    for(auto it : s)
    {
        int ind = it - 'a';
        if(now -> next[ind] == nullptr) return false;
        now = now -> next[ind];
    }
    if(now -> count > 0) return true;
    return false;
}
bool find2(string s,node *root)
{
    node *now = root;
    for(auto it : s)
    {
        int ind = it - 'a';
        if(now -> next[ind] == nullptr) return false;
        now = now -> next[ind];
    }
   return true;
}
class PrefixTree {
public:
    node *root = create();
    PrefixTree() {
    }
    
    void insert(string word) {
        add(word,root);
    }
    
    bool search(string word) {
        return find(word,root);
    }
    
    bool startsWith(string prefix) {
        return find2(prefix,root);
        
    }
};
