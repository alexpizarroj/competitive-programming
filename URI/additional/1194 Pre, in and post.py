class node:
    def __init__(self, value, left = None, right = None):
        self.value = value
        self.left = left
        self.right = right
    
    def __repr__(self, level = 0):
        ret = "\t"*level + str(self.value) + "\n"
        if not self.left is None:
            ret += self.left.__repr__(level+1)
        if not self.right is None:
            ret += self.right.__repr__(level+1)
        return ret

def getTree(preorder, inorder):
    if len(preorder) == 0:
        return None
    
    tree = node(preorder[0])
    nLeft = inorder.index(tree.value)
    tree.left = getTree(preorder[1:nLeft+1], inorder[:nLeft])
    tree.right = getTree(preorder[nLeft+1:], inorder[nLeft+1:])
    return tree

def getPostorder(tree, separator = " "):
    ret = ""
    if not tree.left is None:
        ret += getPostorder(tree.left, separator)
    if not tree.right is None:
        ret += getPostorder(tree.right, separator)
    ret += tree.value + separator
    
    return ret

if __name__ == "__main__":
    nCases = int(raw_input())
    for i in xrange(nCases):
        data = raw_input().split()
        tree = getTree(data[1], data[2])
        print getPostorder(tree, "")
        print tree
    