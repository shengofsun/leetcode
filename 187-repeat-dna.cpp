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
  vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<string, int> count;
    for (int i=0; i<s.size() - 10; ++i) {
      string sequence = s.substr(i, 10);
      count[sequence]++;
    }

    vector<string> result;
    for (const auto& kv: count) {
      if (kv.second > 1) {
        result.push_back(kv.first);
      }
    }

    return result;
  }
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
  vector<string> result = solution.findRepeatedDnaSequences("AAAAAAAAAAA");
  cout << result << endl;
}
