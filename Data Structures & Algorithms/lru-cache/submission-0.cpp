class LRUCache {
public:
unordered_map<int,pair<int,int>>point; /// point that e kare follow kore and ere k follow kore . frist kare kore,second k ore kore;
unordered_map<int,int>val; /// value print and update korar jonno;
int last = -1;
int n;
    LRUCache(int capacity) {
        point[last] = {-1 , -1};
        n = capacity;
    }
    
    int get(int key) {
        if(key == last) return val[key];
        if(val.find(key) == val.end()) return -1;
        else
        {
            auto it = point[key];
            int f = it.first;
            int s = it.second;
            point[s].first = f;
            point[f].second = s;
            point[last].first = key;
            point[key].second = last;
            last = key;
            return val[key];
        }
    }
    
    void put(int key, int value) {
        val[key] = value;
        if(key == last) return;
        if(point.find(key) != point.end())
        {
            auto it = point[key];
            int f = it.first;
            int s = it.second;
            point[s].first = f;
            point[f].second = s;
            point[last].first = key;
            point[key].second = last;
            last = key;
            return;
        }
        if(point.size() != n + 1)
        {
            point[last].first = key;
            point[key].second = last;
            last = key;
            return;
        }
        else /// erase the first element;
        {
            point[last].first = key;
            point[key].second = last;
            int now = point[-1].first;
            val.erase(now);
            int next = point[now].first;
            point[-1].first = next;
            point[next].second = -1;
            point.erase(now);
            last = key;
            return;
        }
    }
};
