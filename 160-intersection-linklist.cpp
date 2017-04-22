#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution
{
public:
    int getLength(ListNode* l) {
        int length = 0;
        while (l) {
            length++;
            l = l->next;
        }
        return length;
    }

    ListNode* stepForward(ListNode* l, int steps) {
        while (steps > 0) {
            l = l->next;
            --steps;
        }
        return l;
    }

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int length1 = getLength(headA);
        int length2 = getLength(headB);

        if (length1 > length2) {
            headA = stepForward(headA, length1 - length2);
        }
        else if (length2 > length1) {
            headB = stepForward(headB, length2 - length1);
        }

        while (headA != nullptr && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};

template<class T>
void printVec(const vector<T>& vec) 
{
    for (int i=0; i<vec.size(); ++i)
    {
        std::cout << vec[i] << std::endl;
    }
}

int main()
{
    Solution solution;
}
