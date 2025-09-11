class UnorderedVector:
    def __init__(self,capacity):
        # According to the data structure definition, a vector is uniform:
        # all elements must have the same type.
        self.__type = None
        self.__lastPosition: int = -1
        self.__capacity: int = capacity
        self.__values = [None] * capacity
    
    def __defineType(self, defType):
        self.__type = defType

    def getLastPosition(self):
        return self.__lastPosition

    def isFull(self):
        return self.__lastPosition == self.__capacity - 1 

    def insert(self, value):
        if self.isFull(): return None
        if (self.__type == None): self.__defineType(type(value))
        if (not isinstance(value, self.__type)): return None

        self.__lastPosition += 1
        self.__values[self.__lastPosition] = value

    def search(self, value):
        if self.__lastPosition == -1: return -1
        for [i, internalValue] in enumerate(self.__values):
            if internalValue == value:
                return i
        return -1


    def getValueByIndex(self, index):
        if index > self.__lastPosition or index < 0: return None
        return self.__values[index]
    
    def remove(self, value):
        index = self.search(value)
        if (index == -1): return None
        for i in range(index, self.__lastPosition):
            self.__values[i] = self.__values[i+1]
        self.__values[self.__lastPosition] = None
        self.__lastPosition -= 1
            

    def removeByIndex(self, index):
        if index > self.__lastPosition or index < 0: return None
        for i in range(index, self.__lastPosition):
            self.__values[i] = self.__values[i+1]
    
        