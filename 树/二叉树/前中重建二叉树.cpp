#include <iostream>
#include <vector>
#include<stdlib.h>
using namespace std;

/*//  Definition for binary tree
class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x) { val = x; }
  }

 class Solution {
    public TreeNode reConstructBinaryTree(int [] pre,int [] in) {
        if(pre==null||in==null){
            return null;
        }

        if(pre.length==0||in.length==0){
            return null;
        }
        TreeNode root=createTree(pre,0,pre.length-1,in,0,in.length-1);
        return root;
    }
    //pb=prebegin pe=preend;ib=inbegin,ie=inend;
     //递归建立树
    TreeNode createTree(int[] pre,int pb,int pe,int[] in, int ib,int ie){
        int i=ib;
        if(pb>pe||ib>ie) return null;
        TreeNode tn=new TreeNode(pre[pb]);
        for( i=ib;i<=ie;i++){
            if(in[i]==pre[pb]){
                break;
            }
        }
        //递归建立左子树
        tn.left=createTree(pre,pb+1,i-ib+pb,in,ib,i-1);
        //递归建立又子树
        tn.right=createTree(pre,i-ib+pb+1,pe,in,i+1,ie);
        return tn;
    }
}*/





















/**
  * Definition for binary tree
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  * };
  */

//  Definition for binary tree
  struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };
class Solution {
 public:
  struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        TreeNode* btree;
        int front=0;
        CreatTree( btree, 0, pre.size()-1,pre, in, front );
        return btree;
  }
     void CreatTree( TreeNode *&btree,int left, int right, vector<int> &preorder,vector<int> &inorder, int &front )
 {
         int pos;
         if( left > right )
         {
             btree = 0;
             return;
         }
         for( int i=left; i<=right; i++ )
         {
             if( preorder[front] == inorder[i] )
             {
                 pos = i;
                 front++;
                 break;
             }
         }
         btree = (TreeNode*)malloc(sizeof(TreeNode));
         btree->val = inorder[pos];
         CreatTree( btree->left, left, pos-1, preorder, inorder, front );
         CreatTree( btree->right, pos+1, right, preorder, inorder, front );
  }




 };

  int main(void)
{
        vector<int> pre={1,2,4,7,3,5,6,8};
        vector<int> in={4,7,2,1,5,3,8,6};
        TreeNode*root;
        Solution*s = new Solution();
        s->reConstructBinaryTree(pre,in);
        //printf("广义表表示的二叉树的输出：\n");
        //printbtree(root);
        //printf("\n");
}




/* public class Solution{
 //通过传进前序遍历，和中序遍历 重建二叉树（可以输出新建的二叉树的后序遍历）
 //递归方法重构树
 public static TreeNode reConstructBinaryTree
 (int[] pre,int[] in ){
 if(pre==null||in==null){
 return null;
 }
 return ConstructCore(pre, in,
 0, pre.length-1, 0, in.length-1);
 }
 //重构二叉树核心代码核心代码
 public static TreeNode ConstructCore
 (int[] pre,int[] in,
 int preStart,int preEnd,int inStart,int inEnd){
 //通过前序遍历序列找到根节点，很显然是序列第一个值
 //创建根节点
 TreeNode root=new TreeNode (pre[preStart]);
 root.left=null;
 root.right=null;
 //当遇到特殊情况
 if(preStart==preEnd&&inStart==inEnd){
 return root;
 }else{
 //throw new Exception();
 System.err.println("输入错误！");
 }
 //通过前序遍历序列所得到的根节点在中序遍历根节点的位置
 int rootInorder=0;
 for(rootInorder=inStart;rootInorder<=inEnd;rootInorder++){
 if(in[rootInorder]==pre[preStart])
 break;
 else if(rootInorder==inEnd){
 System.err.println("输入错误");
 }
 }

 //开始分割左右子树
 //左子树长度
 int leftTreeLength=rootInorder-inStart;
 //右子树长度
 int rightTreelength=inEnd-rootInorder;
 //开始构建左右子树
 //构建左子树
 if(leftTreeLength>0){
 root.left=ConstructCore(pre, in,
 preStart+1, preStart+leftTreeLength,
 inStart,rootInorder-1);
 }
 //构建右子树
 if(rightTreelength>0){
 root.right=ConstructCore(pre, in,
 preStart+leftTreeLength+1, preEnd,
 rootInorder+1,inEnd);
 }
 return root;
 }
 public static void main(String[] args) {

 }*/

