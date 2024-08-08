#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.empty() || inorder.empty()) return nullptr;

    auto mid = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

    TreeNode* root = new TreeNode(preorder[0]);

    vector<int> leftpre(preorder.begin() + 1, preorder.begin() + mid + 1);
    vector<int> rightpre(preorder.begin() + mid + 1, preorder.end());

    vector<int> leftin(inorder.begin(), inorder.begin()+mid);
    vector<int> rightin(inorder.begin() + mid + 1, inorder.end());

    root->left = buildTree(leftpre, leftin);
    root->right = buildTree(rightpre, rightin);

    return root;
}

void inorder(TreeNode* root) {
    if(root == nullptr) return;

    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}


int main(int argc, char** argv) {

    cout<<"hello world"<<endl;
    
    vector<int> preorderArr = {3, 9, 20, 15, 7};
    vector<int> inorderArr = {9, 3, 15, 20, 7};
    TreeNode* root = buildTree(preorderArr, inorderArr);
    inorder(root);

    return 0;
}