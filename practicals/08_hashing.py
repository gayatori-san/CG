keys = [22, 1, 13, 11, 24, 33]
SIZE = 11

# Chaining
chain = [[] for _ in range(SIZE)]
for key in keys:
    chain[key % SIZE].append(key)
print("CHAINING")
for i in range(SIZE):
    print(i, ":", chain[i])

# Linear probing
linear = [None] * SIZE
for key in keys:
    i = key % SIZE
    while linear[i] is not None:
        i = (i + 1) % SIZE
    linear[i] = key
print("LINEAR:", linear)

# Quadratic probing
quad = [None] * SIZE
for key in keys:
    start = key % SIZE
    for j in range(SIZE):
        i = (start + j*j) % SIZE
        if quad[i] is None:
            quad[i] = key
            break
print("QUADRATIC:", quad)