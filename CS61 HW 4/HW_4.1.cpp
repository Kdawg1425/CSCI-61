#include <iostream>
#include <queue>
using namespace std;


struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void print(Node *root) {
    if (root == NULL) {
      return;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        int nodeCount = q.size();
        while (nodeCount > 0) {
            Node *node = q.front();
            cout << node->data << " ";
            q.pop();
            if (node->left){
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
            nodeCount--;
        }
        cout << endl;
    }
}

void BSTToSortedLink(Node* root, Node** head_ref) {
    if(root == NULL) {
        return;
    }
    BSTToSortedLink(root->right, head_ref);
    root->right = *head_ref;
    if (*head_ref != NULL) {
        (*head_ref)->left = NULL;
    }
    *head_ref = root;
    BSTToSortedLink(root->left, head_ref);
}

void SortedLinkToMinHeap(Node* &root, Node* head) {
    if (head == NULL) {
        return;
    }
    queue<Node *> q;
    root = head;
    head = head->right;
    root->right = NULL;
    q.push(root);

    while (head) {
        Node* parent = q.front();
        q.pop();
        Node *leftChild = head;
        head = head->right;
        leftChild->right = NULL;
        q.push(leftChild);
        parent->left = leftChild;

        if (head) {
            Node *rightChild = head;
            head = head->right;
            rightChild->right = NULL;
            q.push(rightChild);
            parent->right = rightChild;
        }
    }
}


void BSTToMinHeap(Node* &root) {
    Node *head = NULL;
    BSTToSortedLink(root, &head);
    root = NULL;
    SortedLinkToMinHeap(root, head);
}

int main()
{
    /* Constructing below tree
                8
              /   \
             4     12
           /  \   /  \
          2    6 10   14
     */

    Node* root = newNode(8);
    root->left = newNode(4);
    root->right = newNode(12);
    root->right->left = newNode(10);
    root->right->right = newNode(14);
    root->left->left = newNode(2);
    root->left->right = newNode(6);

    cout << "Before" << endl;
    cout << endl;
    print(root);
    cout << endl;

    BSTToMinHeap(root);

    /* Output - Min Heap
                2
              /   \
             4     6
           /  \   /  \
          8   10 12   14
     */
    cout << "After" << endl;
    cout << endl; 
    print(root);

    return 0;
}
