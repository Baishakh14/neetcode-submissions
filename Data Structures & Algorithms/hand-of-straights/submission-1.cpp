class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
    int k = groupSize;
    map<int,int>fre;
    for(auto it : hand) fre[it]++;
    bool ok = true;
    while(!fre.empty())
    {
        auto it = *fre.begin();
        int first = it.first;
        for(int i = first;i < (first + k);i++)
        {
            if(fre.count(i))
            {
                fre[i]--;
                if(fre[i] == 0) fre.erase(i);
            }
            else 
            {
                ok = false;
                break;
            }
        }
        if(!ok) break;
    }
        return ok;
    }
};
