import sys, time
with open(sys.argv[1]) as file:
	for line in file:
		time.sleep(0.5)
		print(line.rstrip('\n'), flush=True)

