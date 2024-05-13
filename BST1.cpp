#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertBST(Node *root, int val) {
    if(root == NULL) {
        return new Node(val);
    }
    
    if(val < root->data) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

void inorder(Node *root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) {
    if(root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while(current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int key) {
    if(root == NULL) {
        return root;
    }
    
    if(key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if(key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int findMax(Node* root) {
    if(root == NULL) {
        cout << "Tree is empty." << endl;
        return INT_MIN; // Return minimum integer value to indicate error
    }
    while(root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

int findMin(Node* root) {
    if(root == NULL) {
        cout << "Tree is empty." << endl;
        return INT_MAX; // Return maximum integer value to indicate error
    }
    while(root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int main() {
    Node *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 2);
    insertBST(root, 4);
    insertBST(root, 3);
    insertBST(root, 7);
    
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;
    
    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;
    
    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;
    
    cout << "Maximum value in the BST: " << findMax(root) << endl;
    cout << "Minimum value in the BST: " << findMin(root) << endl;
    
    int keyToDelete = 7;
    root = deleteNode(root, keyToDelete);
    cout << "Inorder traversal after deleting " << keyToDelete << ": ";
    inorder(root);
    cout << endl;
    
    keyToDelete = 2;
    root = deleteNode(root, keyToDelete);
    cout << "Inorder traversal after deleting " << keyToDelete << ": ";
    inorder(root);
    cout << endl;
    
    return 0;
}
