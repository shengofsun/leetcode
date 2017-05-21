#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
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
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int rows = dungeon.size();
    int cols = dungeon[0].size();
    std::vector<std::vector<int>> healthy(rows, std::vector<int>(cols, 0));
    healthy[rows-1][cols-1] = 1;
    if (dungeon[rows-1][cols-1] < 0)
      healthy[rows-1][cols-1] -= dungeon[rows-1][cols-1];

    for (int i=rows-2; i>=0; --i) {
      if (dungeon[i][cols-1] >= healthy[i+1][cols-1])
        healthy[i][cols-1] = 1;
      else {
        healthy[i][cols-1] = healthy[i+1][cols-1] - dungeon[i][cols-1];
      }
    }

    for (int i=cols-2; i>=0; --i) {
      if (dungeon[rows-1][i] >= healthy[rows-1][i+1]) {
        healthy[rows-1][i]  = 1;
      }
      else {
        healthy[rows-1][i] = healthy[rows-1][i+1] - dungeon[rows-1][i];
      }
    }

    for (int i=rows-2; i>=0; --i) {
      for (int j=cols-2; j>=0; --j) {
        int min_healthy = std::min(healthy[i+1][j], healthy[i][j+1]);
        if (dungeon[i][j] >= min_healthy)
          healthy[i][j] = 1;
        else {
          healthy[i][j] = min_healthy - dungeon[i][j];
        }
      }
    }

    return healthy[0][0];
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
  std::vector<std::vector<int>> d = {
    {-2, -3, 3},
    {-5, -10, 1},
    {10, 30, -5}
  };

  std::cout << solution.calculateMinimumHP(d) << std::endl;
}
