
from vectors import Vector


my_vec = Vector(8,True)

my_vec.insert(8)
my_vec.insert(6)
my_vec.insert(4)
my_vec.insert(2)
my_vec.insert(9)
my_vec.insert(5)
my_vec.insert(3)

for index in range(my_vec.getLastPosition()):
    print(my_vec.getValueByIndex(index))

print(my_vec.binarySearch(9))