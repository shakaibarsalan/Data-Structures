#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data = 0)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insert(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        root->left = insert(root->left, data);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        insert(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

Node *minNode(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *deleteNode(Node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == value)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        if (root->left != NULL && root->right != NULL)
        {
            int minimum = minNode(root->right)->data;
            root->data = minimum;
            root->right = deleteNode(root->right, minimum);
            return root;
        }
    }
    else if (root->data > value)
    {
        root->left = deleteNode(root->left, value);
        return root;
    }
    else if (root->data < value)
    {
        root->right = deleteNode(root->right, value);
        return root;
    }
}

Node *maxNode(Node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    map<int, int> topNode;
    queue<pair<Node *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int hd = temp.second;

        // if one value is present for a HD, then do nothing
        if (topNode.find(hd) == topNode.end())
            topNode[hd] = frontNode->data;

        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd - 1));
        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd + 1));
    }

    for (auto i : topNode)
    {
        ans.push_back(i.second);
    }
    return ans;
}

vector<int> bottomView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    map<int, int> topNode;
    queue<pair<Node *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int hd = temp.second;

        topNode[hd] = frontNode->data;

        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd + 1));
        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd - 1));
    }

    for (auto i : topNode)
    {
        ans.push_back(i.second);
    }
    return ans;
}

void leftViewSolve(Node *root, vector<int> &ans, int level)
{
    // base case
    if (root == NULL)
        return;

    // we entered into a new level
    if (level == ans.size())
        ans.push_back(root->data);

    leftViewSolve(root->left, ans, level + 1);
    leftViewSolve(root->right, ans, level + 1);
}
vector<int> leftView(Node *root)
{
    vector<int> ans;
    leftViewSolve(root, ans, 0);
    return ans;
}

void rightViewSolve(Node *root, vector<int> &ans, int level)
{
    // base case
    if (root == NULL)
        return;

    // we entered into a new level
    if (level == ans.size())
        ans.push_back(root->data);

    rightViewSolve(root->right, ans, level + 1);
    rightViewSolve(root->left, ans, level + 1);
}
vector<int> rightView(Node *root)
{
    vector<int> ans;
    rightViewSolve(root, ans, 0);
    return ans;
}

int height(struct Node *node)
{
    // base case
    if (node == NULL)
    {
        return 0;
    }

    int left = height(node->left);
    int right = height(node->right);

    int ans = max(left, right) + 1;
    return ans;
}

pair<int, int> diameterFast(Node *root)
{
    // base case
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}
int diameter(Node *root)
{
    return diameterFast(root).first;
}

Node *search(Node *root, int key) // Search function
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }

    if (root->data > key)
    {
        return search(root->left, key);
    }
    else if (root->data < key)
    {
        return search(root->right, key);
    }
}

int main()
{
    Node *root = NULL;

    // Input for creating the BST
    cout << "Enter For Creating BST: ";
    takeInput(root);
    cout << endl;

    // Level order traversal of the BST
    cout << "Level Order Traversal for BST" << endl;
    levelOrderTraversal(root);
    cout << endl;

    // Deleting a node with a specific value
    int del = 40;
    root = deleteNode(root, del);
    cout << "After delete " << del << ": " << endl;
    levelOrderTraversal(root);
    cout << endl;

    // Searching for a key in the BST
    int key = 33;
    if (search(root, key) != NULL)
    {
        cout << "Key \"" << key << "\" found in the tree.\n";
    }
    else
    {
        cout << "Key \"" << key << "\" not found in the tree.\n";
    }
    cout << endl;

    // Finding the minimum and maximum in the BST
    cout << "Minimum in BST: " << minNode(root)->data << endl;
    cout << "Maximum in BST: " << maxNode(root)->data << endl;
    cout << endl;

    // Calculating the height of the BST
    cout << "Height of BST is: ";
    cout << height(root) << endl;

    // Calculating the diameter of the BST
    cout << "Diameter of BST is: ";
    cout << diameter(root) << endl;
    cout << endl;

    // Tree traversals: Pre-order, In-order, Post-order
    cout << "Pre Order: ";
    preOrder(root);
    cout << endl;
    cout << "In Order: ";
    inOrder(root);
    cout << endl;
    cout << "Post Order: ";
    postOrder(root);
    cout << endl
         << endl;

    // Top, Bottom, Left, and Right views of the BST
    vector<int> topRes = topView(root);
    cout << "Top View of BST: ";
    for (int i : topRes)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<int> bottomRes = bottomView(root);
    cout << "Bottom View of BST: ";
    for (int i : bottomRes)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<int> leftRes = leftView(root);
    cout << "Left View of BST: ";
    for (int i : leftRes)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<int> rightRes = rightView(root);
    cout << "Right View of BST: ";
    for (int i : rightRes)
    {
        cout << i << " ";
    }
    cout << endl
         << endl;

    return 0;
}

// Example inputs:
// 10 40 8 21 7 27 54 3 -1
// 50 20 70 10 40 30 90 110 -1
// 40 23 12 90 11 34 56 35 33 10 -1