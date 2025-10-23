from binarytree import BinaryTree

btree = BinaryTree(10)

btree.insert(5)
btree.insert(8)
btree.insert(10)
btree.insert(9)
btree.insert(7)
btree.insert(3)
btree.insert(2)
btree.insert(4)
btree.insert(1)

"""
        5 
     /     \ 
     3       8
    / \     / \ 
   2 4    6   9 
  /        \   \ 
  1         7   10
"""

print("Tranversal in Order: ")
btree.transversalInOrder()

print("\n\nTranversal pre Order: ")
btree.transversalPreOrder()

print("\n\nTranversal post Order: ")
btree.transversalPostOrder()

print("\n\nRemove number 2")
btree.remove(2)

print("\n\nVerify if the number has been removed.")
btree.transversalPreOrder()

print("\n\nSearch number 9")

print(btree.search(9))


