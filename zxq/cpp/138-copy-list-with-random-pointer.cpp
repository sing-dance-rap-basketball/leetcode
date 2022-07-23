/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 * 
 *   √ 9/9 cases passed (28 ms)
 *   √ Your runtime beats 96.36 % of cpp submissions
 *   √ Your memory usage beats 14.9 % of cpp submissions (22.4 MB)
 *   √ 9/9 cases passed (32 ms)
 *   √ Your runtime beats 85.02 % of cpp submissions
 *   √ Your memory usage beats 47.94 % of cpp submissions (22.2 MB)
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) { return nullptr; }

        std::unordered_map<Node*, Node*> old2new { {nullptr, nullptr} };    // correspondence
        Node *oldNode = head;
        Node *dummyHead = new Node(0, nullptr, nullptr);
        Node *newNode = dummyHead;
        while (oldNode != nullptr) {
            newNode->next = new Node(oldNode->val, nullptr, nullptr);
            newNode = newNode->next;
            old2new[oldNode] = newNode;
            oldNode = oldNode->next;
        }

        oldNode = head;
        while(oldNode != nullptr) {
            old2new[oldNode]->random = old2new[oldNode->random];
            oldNode = oldNode->next;
        }

        return dummyHead->next;
    }
};

