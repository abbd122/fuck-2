//
// Created by GZH51 on 2021/7/29.
//

#ifndef TEST_UTILS_HPP
#define TEST_UTILS_HPP

#include <iostream>
#include <functional>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <cassert>
#include <sstream>
#include <memory>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    explicit ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createListNode(vector<int> arr) {
    auto size = (int) arr.size();
    auto *head = new ListNode(arr[0]);
    ListNode *cur = head;
    int n = 1;
    while (n < size) {
        auto *next = new ListNode(arr[n]);
        cur->next = next;
        cur = next;
        ++n;
    }
    return head;
}

void freeListNode(ListNode *head) {
    ListNode *delNode = head;
    while (delNode != nullptr) {
        ListNode *tmp = delNode->next;
        delete delNode;
        delNode = tmp;
    }
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *newTreeNode(int item) {
    if (item == INT_MAX) {
        return nullptr;
    } else {
        auto *node = new TreeNode(item);
        return node;
    }
}

TreeNode *createTreeNode(vector<int> vec) {
    int length = (int) vec.size();
    if (length == 0 || vec[0] == INT_MAX) {
        return nullptr;
    }
    auto *head = new TreeNode(vec[0]);
    queue<TreeNode *> q;
    q.push(head);
    int i = 1;
    while (i < length) {
        TreeNode *node = q.front();
        q.pop();
        if (node == nullptr) {
            continue;
        }
        TreeNode *left = newTreeNode(vec[i]);
        node->left = left;
        q.push(left);
        ++i;
        if (i >= length) {
            break;
        }
        TreeNode *right = newTreeNode(vec[i]);
        node->right = right;
        q.push(right);
        ++i;
    }
    return head;
}

void freeTreeNode(TreeNode *head) {
    queue<TreeNode *> q;
    q.push(head);
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();
        if (node != nullptr) {
            TreeNode *left = node->left;
            TreeNode *right = node->right;
            q.push(left);
            q.push(right);
            delete node;
        }
    }
}

class NestedInteger {
public:
    bool isInteger() const;

    int getInteger() const;

    const vector<NestedInteger> &getList() const;
};

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    explicit Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

Node *newNode(int item) {
    if (item == INT_MAX) {
        return nullptr;
    } else {
        auto *node = new Node(item);
        return node;
    }
}

Node *createNode(vector<int> vec) {
    int length = (int) vec.size();
    if (length == 0 || vec[0] == INT_MAX) {
        return nullptr;
    }
    auto *head = new Node(vec[0]);
    queue<Node *> q;
    q.push(head);
    int i = 1;
    while (i < length) {
        Node *node = q.front();
        q.pop();
        if (node == nullptr) {
            continue;
        }
        Node *left = newNode(vec[i]);
        node->left = left;
        q.push(left);
        ++i;
        if (i >= length) {
            break;
        }
        Node *right = newNode(vec[i]);
        node->right = right;
        q.push(right);
        ++i;
        node->next = nullptr;
    }
    return head;
}

void show_bytes(unsigned int num, const string &cmp_bytes = "") {
    vector<int> res;
    while (num != 0) {
        res.push_back((int) (num % 2));
        num /= 2;
    }
    reverse(res.begin(), res.end());
    for (auto &iter: res) {
        cout << iter;
    }
    cout << endl;
    vector<int> cmp;
    if (!cmp_bytes.empty()) {
        cout << cmp_bytes << endl;
        for (auto &ch: cmp_bytes) {
            cmp.push_back(ch - '0');
        }
        for (int i = 0; i < cmp.size(); ++i) {
            if (res[i] == cmp[i]) {
                cout << " ";
            } else {
                cout << "f";
                return;
            }
        }
    }
}

#endif //TEST_UTILS_HPP
