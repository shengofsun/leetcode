#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x): val(x), next(NULL) {}
};

class Solution
{
public:
};

template<class T>
std::ostream& operator << (std::ostream& output, const std::vector<T>& val) {
  output << "[";
  if (!val.empty()) {
    output << val.front();
    for (int i=1; i<val.size(); ++i) {
      output << "," << val[i];
    }
  }
  output << "]";
  return output;
}

int main()
{
  Solution solution;
    
}
