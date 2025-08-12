class Queue:
    def __init__(self):
        self.__queue = []
    
    def enqueue(self, data):
        self.__queue.append(data)
            
    def dequeue(self):
        try:
            temp = self.getFront()
            self.__queue.remove(temp) 
            return temp
        except IndexError:
            return None
        except ValueError:
            return None

    def getFront(self):
        return self.__queue[0]

    def getTail(self):
        return self.__queue[-1]

    def getSize(self):
        return len(self.__queue)
    

queue = Queue()
queue.enqueue(2)
queue.enqueue(0)
queue.enqueue(8)
queue.enqueue(3)

while(queue.getSize() > 0):
    print(queue.getFront())
    queue.dequeue()