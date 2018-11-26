import sys, time
with open(sys.argv[1]) as file:
	for line in file:
		print(line.rstrip("\n"), flush=True)
		time.sleep(0.5)

