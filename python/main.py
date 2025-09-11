
from vectors import UnorderedVector
import time

N = 1_000_000

# Array puro
start = time.time()
pure_array = [None] * N
for i in range(N):
    pure_array[i] = i
end = time.time()
print(f"Array puro: {end - start:.6f} s")

# Vetor não ordenado
start = time.time()
vec = UnorderedVector(N)
for i in range(N):
    vec.insert(i)
end = time.time()
print(f"UnorderedVector: {end - start:.6f} s")