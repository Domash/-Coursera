import sys

a, b, c = int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3])

d = b ** 2 - 4 * a * c

print(int((-b + d ** 0.5) / (2 * a)))
print(int((-b - d ** 0.5) / (2 * a)))



