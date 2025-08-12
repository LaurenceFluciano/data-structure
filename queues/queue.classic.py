class Node:
    def __init__(self, data):
        self.data = data
        self.reference = None


class Queue:
    def __init__(self):
        self.front = None
        self.tail = None
        self.size = 0

    def enqueue(self, data):
        node = Node(data)
        if(self.tail != None): self.tail.reference = node
        if(self.front == None): self.front = node
        self.tail = node
        self.size+=1
    
    def dequeue(self):
        if (self.front == None): 
            return None
        data = self.front.data
        self.front = self.front.reference
        if self.front is None: 
            self.tail = None
        self.size-=1
        return data
    
queue = Queue()
queue.enqueue("example")
queue.enqueue(12)
queue.enqueue("Easy")

while(queue.size > 0):
    print(queue.front.data)
    queue.dequeue()