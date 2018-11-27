import matplotlib.pyplot
import sys

def bitsToInt(arr, start=0):
	for i in arr:
		start = (start << 1) | bool(i)
	return start

size = 30

sheet = matplotlib.pyplot.imread(sys.argv[1])
for n, row in enumerate(sheet):
	color, alpha = zip(*((int(r + g + b == 3), int(alpha != 0)) for r,g,b,alpha in row))
	if n % 30 == 0: print('{', end='')
	print(f'{{0b{bitsToInt(reversed(color)):0>32b}ul, ' +
		f'0b{bitsToInt(reversed(alpha)):0>32b}ul}},', end='')
	if n % size == size-1: print('},', end='')
	print()
