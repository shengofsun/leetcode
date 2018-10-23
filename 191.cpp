#include <iostream>

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int ans = 0;
    while (n) {
      ans += (n&1);
      n >>= 1;
    }
    return ans;
  }
};

int main()
{
  Solution s;
  std::cout << s.hammingWeight(11) << std::endl;
}
