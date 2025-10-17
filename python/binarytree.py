class TreeNode:
    def __init__(self, value=None):
        self.value = value
        self._left = None
        self._right = None
    
    @property
    def left(self):
        return self._left
    
    @left.setter
    def left(self, node):
        if node is not None and not isinstance(node, TreeNode):
            raise TypeError("left must to be a TreeNode or None")
        self._left = node

    @property
    def right(self):
        return self._right
    
    @right.setter
    def right(self, node):
        if node is not None and not isinstance(node, TreeNode):
            raise TypeError("right must to be a TreeNode or None")
        self._right = node

class BinaryTree:
    def __init__(self, node):
        if node.left is not None or node.right is not None:
            raise ValueError("TreeNode cannot have childrens.")
        if node == None:
            raise AttributeError('The root must contain a initial node.')
        self.root = node
    
    def insertNode(self, node):
        if node.left is not None or node.right is not None:
            raise ValueError("TreeNode cannot have childrens.")
        currentNode = self.root
        # Problem: This cause imbalance.
        while (True):
            if node.value > currentNode.value:
                if currentNode.right == None:
                    currentNode.right = node
                    break
                currentNode = currentNode.right
            elif node.value < currentNode.value:
                if currentNode.left == None:
                    currentNode.left = node
                    break
                currentNode = currentNode.left
            else:
                break
    
    def transversalPreOrder(self):
        def visit(node):
            if node is None:
                return
            print(node.value)
            visit(node.left)
            visit(node.right)
        visit(self.root)
    

    def transversalInOrder(self):
        def visit(node):
            if node is None:
                return
            visit(node.left)
            print(node.value)
            visit(node.right)
        visit(self.root)
    
    def transversalPostOrder(self):
        def visit(node):
            if node is None:
                return
            visit(node.left)
            visit(node.right)
            print(node.value)
        visit(self.root)

    def remove(self, value):
        currentNode = self.root
        parent = None

        while currentNode and currentNode.value != value:
            parent = currentNode
            if value < currentNode.value:
                currentNode = currentNode.left
            else:
                currentNode = currentNode.right
        
        if currentNode is None:
            return

        if currentNode.left == None and currentNode.right == None:
            if parent is None:
                self.root = None
            elif parent.left == currentNode:
                parent.left = None
            else:
                parent.right = None
        
        elif currentNode.left is None or currentNode.right is None:
            if currentNode.left: 
                child = currentNode.left
            else:
                child = currentNode.right
    
            if parent is None:
                self.root = child
            
            elif parent.left == currentNode:
                parent.left = child
            else:
                parent.right = child

        else:
            successorParent = currentNode
            successor = currentNode.right
            while successor.left:
                successorParent = successor
                successor = successor.left

            currentNode.value = successor.value
            if successorParent.left == successor:
                successorParent.left = successor.right
            else:
                successorParent.right = successor.right