#pragma once
#include <iostream>
using namespace std;  

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
};
template <typename T>
class BinarySearchTree {
private:
    TreeNode<T>* root;
    // for destructor
    void destroy(TreeNode<T>* node) {
        if (node) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }
    // for console Display
    void inorder(TreeNode<T>* node) const {
        if (node) {
            inorder(node->left);
            cout << node->data << " \n";
            inorder(node->right);
        }
    }
    // for Writing in File
    void inorderInFile(TreeNode<T>* node,ostream& out) const {
        if (node) {
            inorderInFile(node->left,out);
            out << node->data << " \n";
            inorderInFile(node->right,out);
        }
    }

    TreeNode<T>* findMin(TreeNode<T>* node) const {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    TreeNode<T>* remove(TreeNode<T>* node, const T& value) {
        if (!node) return nullptr;

        if (value < node->data) {
            node->left = remove(node->left, value);
        }
        else if (value > node->data) {
            node->right = remove(node->right, value);
        }
        else {
            // Case 1: Leaf node
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            }
            // Case 2: Node with one child
            if (!node->left) {
                TreeNode<T>* temp = node->right;
                delete node;
                return temp;
            }
            if (!node->right) {
                TreeNode<T>* temp = node->left;
                delete node;
                return temp;
            }
            // Case 3: Node with two children
            TreeNode<T>* minNode = findMin(node->right);
            node->data = minNode->data;
            node->right = remove(node->right, minNode->data);
        }
        return node;
    }

    
    TreeNode<T>* insert(TreeNode<T>* node, const T& value) {
        if (node == nullptr) {
            return new TreeNode<T>(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        }
        else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        destroy(root);
    }

    void insert(const T& value) {
        root = insert(root, value);
    }


    void remove(const T& value) {
        root = remove(root, value);
    }

    bool search(const T& value) const {
        if (search(root,value)) {
            return true;
        }
        else {
            return false;
        }
    }
    //call hoa 
    TreeNode<T>* search(TreeNode<T>* node, const T& value) const {
        if (!node )
        {
            return nullptr;
        }else if (node->data == value) 
        {
            return node;
        }
        else if (value < node->data)
        {
            return search(node->left, value);
        }
        return search(node->right, value);
    }
    
    void inorderTraversal(ostream& out=cout) const {
        if (&out == &cout) {
            inorder(root);
            cout << endl;
        }
        else {
            inorderInFile(root,out);
            out << endl;
        } 
    }

    bool isEmpty() const {
        if (!root) {
            return true;
        }
        else {
            return false;
        }
    }

    TreeNode<T>* getRoot()const {
        return root;
    }
};
