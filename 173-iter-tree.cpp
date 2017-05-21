#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        if (root == nullptr)
            return;
        nodeStack.push(root);
        visitStack.push(false);
        iterNext();
    }

    void iterNext() {
        if (visitStack.empty())
            return;
        if (visitStack.top() == true)
            return;

        while (!visitStack.empty() && visitStack.top()==false) {
            TreeNode* current = nodeStack.top();
            visitStack.pop();
            nodeStack.pop();
            if (current->right) {
                nodeStack.push(current->right);
                visitStack.push(false);
            }
            nodeStack.push(current);
            visitStack.push(true);
            if (current->left) {
                nodeStack.push(current->left);
                visitStack.push(false);
            }
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nodeStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        int value = nodeStack.top()->val;
        nodeStack.pop();
        visitStack.pop();
        iterNext();
        return value;
    }
private:
    std::stack<TreeNode*> nodeStack;
    std::stack<bool> visitStack;
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
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);

    c.left = &b;
    b.left = &a;
    
    BSTIterator iterator(nullptr);
    while (iterator.hasNext()) {
        std::cout << iterator.next() << std::endl;
    }
}
