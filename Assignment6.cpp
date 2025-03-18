// Harsh Kumar Yadav

// 1. Implement Queue using Stack
#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <queue>
using namespace std;
class QueueUsingStack 
{
    stack<int> s1, s2;
public:
    void enqueue(int x) 
{
        s1.push(x);
    }
    int dequeue() {
        if (s1.empty() && s2.empty()) return -1;
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }
};

// 2. Implement Deque using Stack
#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <queue>
class DequeUsingStack {
    stack<int> s1, s2;
public:
    void pushFront(int x) { s1.push(x); }
    void pushBack(int x) { s2.push(x); }
    int popFront() {
        if (!s1.empty()) {
            int val = s1.top();
            s1.pop();
            return val;
        }
        return -1;
    }
    int popBack() {
        if (!s2.empty()) {
            int val = s2.top();
            s2.pop();
            return val;
        }
        return -1;
    }
};

// 3. Implement Min Stack using Two Stacks
#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <queue>
class MinStack {
    stack<int> s, minS;
public:
    void push(int x) {
        s.push(x);
        if (minS.empty() || x <= minS.top())
            minS.push(x);
    }
    void pop() {
        if (s.top() == minS.top()) minS.pop();
        s.pop();
    }
    int top() { return s.top(); }
    int getMin() { return minS.top(); }
};

// 4. Implement Max Stack using Two Stacks
#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <queue>
class MaxStack {
    stack<int> s, maxS;
public:
    void push(int x) {
        s.push(x);
        if (maxS.empty() || x >= maxS.top())
            maxS.push(x);
    }
    void pop() {
        if (s.top() == maxS.top()) maxS.pop();
        s.pop();
    }
    int top() { return s.top(); }
    int getMax() { return maxS.top(); }
};

// 5. Implement Priority Queue using Stack
#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <queue>
class PriorityQueueUsingStack {
    stack<int> s;
public:
    void push(int x) {
        stack<int> temp;
        while (!s.empty() && s.top() > x) {
            temp.push(s.top());
            s.pop();
        }
        s.push(x);
        while (!temp.empty()) {
            s.push(temp.top());
            temp.pop();
        }
    }
    int pop() {
        if (s.empty()) return -1;
        int val = s.top();
        s.pop();
        return val;
    }
};

// 6. Implement BST (Inorder Traversal) using Stack (Iterative DFS)
#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <queue>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* curr = root;
    while (curr || !s.empty()) {
        while (curr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top(); s.pop();
        cout << curr->val << " ";
        curr = curr->right;
    }
}

// 7. Implement Graph DFS using Stack (Iterative DFS)
#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <queue>
void DFS(vector<vector<int>>& graph, int start) {
    stack<int> s;
    vector<bool> visited(graph.size(), false);
    s.push(start);
    while (!s.empty()) {
        int node = s.top(); s.pop();
        if (!visited[node]) {
            cout << node << " ";
            visited[node] = true;
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) s.push(neighbor);
            }
        }
    }
}

int main() {
    QueueUsingStack q;
    q.enqueue(1);
    q.enqueue(2);
    cout << "Queue Dequeue: " << q.dequeue() << endl;

    MinStack ms;
    ms.push(5);
    ms.push(3);
    cout << "Min Stack Min: " << ms.getMin() << endl;

    MaxStack mx;
    mx.push(2);
    mx.push(8);
    cout << "Max Stack Max: " << mx.getMax() << endl;

    PriorityQueueUsingStack pq;
    pq.push(4);
    pq.push(1);
    pq.push(3);
    cout << "Priority Queue Pop: " << pq.pop() << endl;

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    vector<vector<int>> graph = {{1, 2}, {0, 3, 4}, {0, 4}, {1, 5}, {1, 2}, {3}};
    cout << "Graph DFS: ";
    DFS(graph, 0);
    cout << endl;
    return 0;
}

// 8. Implement Stack using Queue
#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <queue>
class StackUsingQueue {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    int pop() {
        if (q.empty()) return -1;
        int val = q.front();
        q.pop();
        return val;
    }
};

// 13. Implement Stack using an Array
#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <queue>
class StackUsingArray {
    int arr[1000], topIdx;
public:
    StackUsingArray() : topIdx(-1) {}
    void push(int x) { arr[++topIdx] = x; }
    int pop() { return (topIdx >= 0) ? arr[topIdx--] : -1; }
};

// 14. Implement Queue using an Array
#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <queue>
class QueueUsingArray {
    int arr[1000], front, rear;
public:
    QueueUsingArray() : front(-1), rear(-1) {}
    void enqueue(int x) { arr[++rear] = x; }
    int dequeue() { return (front < rear) ? arr[++front] : -1; }
};

// 25. Implement Stack using Linked List
#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <queue>
struct Node {
    int data;
    Node* next;
};
class StackUsingLinkedList {
    Node* top;
public:
    StackUsingLinkedList() : top(nullptr) {}
    void push(int x) { Node* n = new Node{x, top}; top = n; }
    int pop() { if (!top) return -1; int val = top->data; top = top->next; return val; }
};

// 26. Implement Queue using Linked List
#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <queue>
class QueueUsingLinkedList {
    Node *front, *rear;
public:
    QueueUsingLinkedList() : front(nullptr), rear(nullptr) {}
    void enqueue(int x) { Node* n = new Node{x, nullptr}; if (!rear) front = rear = n; else rear->next = n, rear = n; }
    int dequeue() { if (!front) return -1; int val = front->data; front = front->next; return val; }
};

int main() {
    return 0;
}
