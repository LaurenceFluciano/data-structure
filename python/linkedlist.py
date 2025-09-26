class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
        self.prev = None
    
class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
    
    def isEmpty(self):
        return self.head is None

    def insertStart(self, value):
        node = Node(value)
        if self.isEmpty():
            self.tail = node
        else:
            self.head.prev = node
            node.next = self.head
        self.head = node

    def insertEnd(self, value):
        node = Node(value)
        if self.isEmpty():
            self.head = node
        else:
            self.head.next = node
            node.prev= self.tail
        self.tail = node

    def deleteStart(self):
        if self.isEmpty():
            return None
        temp = self.head
        if self.head.next is None:
            self.tail = None
        else:
            self.head.next.prev = None
        self.head = self.head.next
        return temp
        
    def deleteEnd(self):
        if self.isEmpty():
            return None
        temp = self.tail
        if self.tail.prev is None:
            self.head = None
        else:
            self.tail.prev.next = None
        self.tail = self.tail.prev
        return temp

    def delete(self, value):
        currentNode = self.search(value)
        if currentNode is None: 
            return None
        if currentNode is self.head:
            self.head = currentNode.next
        else:
            currentNode.prev.next = currentNode.next
            currentNode.next = None
        if currentNode is self.tail:
            self.tail = currentNode.prev
        else:
            currentNode.next.prev = currentNode.prev
            currentNode.prev = None
        return currentNode            

    def search(self,value):
        if self.isEmpty():
            return None
        currentNode = self.head
        while (currentNode is not None) and (currentNode.value != value):
            currentNode = currentNode.next
        return currentNode