#include "BinaryTree.h"
#include <stack>
#include <queue>

/**
 * Implement balanceFactors() correctly
 */
unordered_map<int,int> BinaryTree::balanceFactors() {
    /* YOUR CODE HERE */
 stack < Node * > s;
 queue < Node * > q;
 unordered_map < int, int > height;
 unordered_map < int, int > x;
 q.push(root);
 
 while (!q.empty()) {
   s.push(q.front());
   if (q.front() -> leftChild != nullptr) {
     q.push(q.front() -> leftChild);
   }
   if (q.front() -> rightChild != nullptr) {
     q.push(q.front() -> rightChild);
   }
   q.pop();
 }
 
 while (!s.empty()) {
   if (s.top() -> leftChild == nullptr && s.top() -> rightChild == nullptr) {
     height[s.top() -> label] = 0;
     x[s.top() -> label] = 0;
   } 
   else if (s.top() -> leftChild == nullptr) {
     height[s.top() -> label] = height[s.top() -> rightChild -> label] + 1;
     x[s.top() -> label] = height[s.top() -> rightChild -> label];
   } 
   else if (s.top() -> rightChild == nullptr) {
     height[s.top() -> label] = height[s.top() -> leftChild -> label] + 1;
     x[s.top() -> label] = -height[s.top() -> leftChild -> label];
   } 
   else {
     height[s.top() -> label] = max(height[s.top() -> leftChild -> label], height[s.top() -> rightChild -> label]) + 1;
     x[s.top() -> label] = height[s.top() -> rightChild -> label] - height[s.top() -> leftChild -> label];
   }
   s.pop();
 }
 return x;
}

