import matplotlib.pyplot
import sys

sheet = matplotlib.pyplot.imread(sys.argv[1])
for row in sheet:
	for r,g,b,alpha in row:
		color, alpha = r == 1, alpha == 1
		print(f'{color + alpha*2:0>2b}', end='')
	print()
