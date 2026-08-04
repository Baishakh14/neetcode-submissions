class Solution {
public:
    int getSum(int a, int b) {
  int sum = (a ^ b);
  int carry = (a & b);
  while(carry != 0)
  {
    carry <<= 1;
    int x = (sum ^ carry);
    carry = (sum & carry);
    sum = x;
  }
  return sum;
    }
};
