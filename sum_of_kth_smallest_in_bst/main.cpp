#include <iostream>
#include <vector>

using namespace std;

/*
 * Given Binary Search Tree. The task is to find sum of all elements smaller than and equal to Kth smallest element.
 *
*/

template<typename T>
struct Node{
    T data;
    Node* left;
    Node* right;
    Node(T data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

template<typename T>
struct BST{
public:
    BST() : root(nullptr){

    }
    ~BST(){
        destroy(root);
    }

    void insert(T data){
        root = insert_internal(root, data);
    }

    int kthSmallestSum(int k){
        int index = 0;
        return kthSmallestSum_internal(root, k, index);
    }

    void inOrder(){
        inOrder_internal(root);
        cout << endl;
    }

private:

    int kthSmallestSum_internal(Node<T>* root, int k, int& index){
        if(!root)
            return 0;
        int val = kthSmallestSum_internal(root->left, k, index);
        if(index >= k)
            return val;

        val += root->data;

        if(++index >= k)
            return val;

        return val + kthSmallestSum_internal(root->right, k, index);
    }

    void inOrder_internal(Node<T>* root){
        if(!root) return;
        inOrder_internal(root->left);
        cout << root->data << " ";
        inOrder_internal(root->right);
    }

    Node<T>* insert_internal(Node<T>* root, T data){
        if(!root)
            return new Node<T>(data);

        if(data < root->data)
            root->left = insert_internal(root->left, data);
        else if(data > root->data)
            root->right = insert_internal(root->right, data);

        return root;
    }

    void destroy(Node<T>* root){
        if(!root) return;
        destroy(root->left);
        destroy(root->right);
        delete root;
        root = nullptr;
    }

private:
    Node<T>* root;
};

int main(int argc, char *argv[])
{
    BST<int> bst;

    bst.insert(20);
    bst.insert(8);
    bst.insert(4);
    bst.insert(12);
    bst.insert(10);
    bst.insert(14);
    bst.insert(22);

    bst.inOrder();

    cout << bst.kthSmallestSum(3) << endl;

    return 0;
}
