"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""
class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        # 中序遍历
        def dfs(cur):
            if not cur:
                return None
            dfs(cur.left)  # 递归左子树
            if self.pre:   # 修改节点引用
                self.pre.right, cur.left = cur, self.pre
            else:          # 记录头节点
                self.head = cur
            self.pre = cur # 保存cur
            dfs(cur.right)

        if not root:
            return None
        
        self.pre = None
        dfs(root)
        self.head.left, self.pre.right = self.pre, self.head

        return self.head
        