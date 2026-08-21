// #include<bits/stdc++.h>
// using namespace std;
class MedianFinder {
public:
       priority_queue<double>choto;
       priority_queue<double,vector<double>,greater<double>>boro;
    MedianFinder() 
    {
    }
    
    void addNum(int num) {
      choto.push(num);
      if(!boro.empty() && boro.top() <= choto.top())
      {
        boro.push(choto.top());
        choto.pop();
      }
      if(abs((int)boro.size() - (int)choto.size()) > 1)
      {
        if(boro.size() > choto.size()) 
        {
          choto.push(boro.top());
          boro.pop();
        }
        else 
        {
          boro.push(choto.top());
          choto.pop();
        }
      }
    }
    
    double findMedian() {
        if(choto.size() == boro.size())
      {
        double val = (choto.top() + boro.top()) / 2;
       return val;
      }
      else
      {
        if(boro.size() > choto.size())
          return boro.top();
        else 
          return choto.top();;
      }
    }
};
