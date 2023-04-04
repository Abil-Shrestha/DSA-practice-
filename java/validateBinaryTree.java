class Solution {
    public boolean isValidBST(TreeNode root) {
     return dfs(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
    boolean dfs(TreeNode root, long min, long max){
        //base case
        if(root==null) return true;

        //if the root.val is less than or greater than the min or max value,
        //than obiously we cannot find the solution
        if(root.val>=max || root.val<=min) return false;

        //call recursion for left and right subtree
        return dfs(root.left, min, root.val) && dfs(root.right, root.val, max);
    }
}