#pragma once

// LeetCode injects the standard library and common node types on its servers.
// clangd force-includes this file locally so solution snippets get accurate
// completion and diagnostics without changing the submitted code.
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Used by problem 138 (copy list with random pointer).
class Node {
public:
    int val;
    Node* next;
    Node* random;

    explicit Node(int value) : val(value), next(nullptr), random(nullptr) {}
};
