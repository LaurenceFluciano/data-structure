class Stack:
    def __init__(self, initialCapacity):
        self.lastPosition = -1
        result = self.verifyCapacity(initialCapacity)
        if (not result["isValid"]):
            self.handlerError(result["errors"])

        self.capacity = initialCapacity
        self.values = [None] * initialCapacity
    
    def verifyCapacity(self, capacity):
        errors = []

        if (not isinstance(capacity, int)):
            errors.append("Capacity must be a number.\n")

        if (capacity-1 <= -1):
            errors.append("Capacity must be at less 1.\n")
        
        if (self.lastPosition >= capacity):
            errors.append("Capacity must major than lastPosition.\n")

        return {"isValid": len(errors) == 0, "errors": errors}

    def handlerError(self, errors):
        raise AttributeError(*errors)

    def resizeCapacity(self, newCapacity):
        result = self.verifyCapacity(newCapacity)
        if (not result["isValid"]):
            self.handlerError(result["errors"])

        extraSpace = newCapacity - len(self.values)
        if extraSpace > 0:
            self.values.extend([None] * extraSpace)
        self.capacity = newCapacity
    

    def push(self,value):
        if (self.lastPosition == self.capacity - 1):
            self.resizeCapacity(self.capacity * 2)
        
        self.lastPosition += 1
        self.values[self.lastPosition] = value
    
    def pop(self):
        if (self.lastPosition == -1):
            return
        
        temp = self.values[self.lastPosition]
        self.values[self.lastPosition] = None
        self.lastPosition -= 1
        return temp

    def peek(self):
        if self.lastPosition == -1:
            return None
        return self.values[self.lastPosition]