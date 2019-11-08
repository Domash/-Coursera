import sys

size = int(sys.argv[1])

curr_size = size

while curr_size > 0:
    print(("#" * (size - curr_size + 1) + " " * (curr_size - 1))[::-1])
    curr_size -= 1
