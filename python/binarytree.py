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
    def __init__(self, value):
        if value is None:
            raise AttributeError('The root value must contain a initial value.')
        root = TreeNode(value)
        self.root = root
    

    def insert(self, value):
        currentNode = self.root
        # Problem: This cause imbalance.
        while (True):
            if value > currentNode.value:
                if currentNode.right is None:
                    currentNode.right = TreeNode(value)
                    break
                currentNode = currentNode.right
            elif value < currentNode.value:
                if currentNode.left is None:
                    currentNode.left = TreeNode(value)
                    break
                currentNode = currentNode.left
            # If node value already exists in the tree, do nothing.
            else:
                break
    
    def search(self, value):
        currentNode = self.root
        while currentNode is not None:
            if value > currentNode.value:
                currentNode = currentNode.right
            elif value < currentNode.value:
                currentNode = currentNode.left
            else:
                return currentNode.value
        return None

    def transversalPreOrder(self, reverse=False):
        if reverse:
            return self._transverse(("self", "right","left"))
        return self._transverse(("self", "left","right"))

    def transversalInOrder(self, reverse=False):
        if reverse:
            return self._transverse(("right", "self", "left"))
        return self._transverse(("left", "self","right"))
    
    def transversalPostOrder(self, reverse=False):
        if reverse:
            return self._transverse(("right","left","self"))
        return self._transverse(("left","right","self"))
    
    def _transverse(self, order=("left","right","self")):
        internalList = list() 
        def visit(node, internalList):
            if node is None:
                return
            for step in order:
                if step == "left":
                    visit(node.left, internalList)
                elif step == "right":
                    visit(node.right, internalList)
                elif step == "self":
                    internalList.append(node.value)
        visit(self.root, internalList)
        return internalList
    
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
            if parent.left == currentNode:
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
                return
            
            if parent.left == currentNode:
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