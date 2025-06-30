#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    char data;
    Node *left;
    Node *right;

    Node(char data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%')
        return true;
    return false;
}

Node *buildTree(string postfix)
{
    stack<Node *> st;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (isOperator(postfix[i]))
        {
            Node *right = st.top();
            st.pop();
            Node *left = st.top();
            st.pop();
            Node *node = new Node(postfix[i]);
            node->left = left;
            node->right = right;
            st.push(node);
        }
        else
        {
            st.push(new Node(postfix[i]));
        }
    }
    return st.top();
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    string postfix = "ab+ef*g*%";

    root = buildTree(postfix);

    cout << "Inorder traversal of expression tree:" << endl;
    inorder(root);

    return 0;
}

// #include <iostream>
// #include <stack>
// using namespace std;

// class Node
// {
// public:
//     char data;
//     Node *left;
//     Node *right;

//     Node(char data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };

// bool isOperator(char c)
// {
//     if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%')
//         return true;
//     return false;
// }

// Node *buildTree(string prefix)
// {
//     stack<Node *> st;

//     for (int i = prefix.length() - 1; i >= 0; i--)
//     {
//         if (isOperator(prefix[i]))
//         {
//             Node *left = st.top();
//             st.pop();
//             Node *right = st.top();
//             st.pop();
//             Node *node = new Node(prefix[i]);
//             node->left = left;
//             node->right = right;
//             st.push(node);
//         }
//         else
//         {
//             st.push(new Node(prefix[i]));
//         }
//     }

//     return st.top();
// }

// void inorder(Node *root)
// {
//     if (root)
//     {
//         inorder(root->left);
//         cout << root->data << " ";
//         inorder(root->right);
//     }
// }

// int main()
// {
//     Node *root = NULL;
//     string prefix = "%*+abefg";

//     root = buildTree(prefix);

//     cout << "Inorder traversal of expression tree:" << endl;
//     inorder(root);

//     return 0;
// }
