import sys

line = sys.argv[1]

list = [int(char) for char in line]

print(sum(list))