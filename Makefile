src = $(shell find src -type f -name "*.c")
obj = $(src:src/%.c=obj/%.o)

flags = -Og -g -Isrc -Wall

.PHONY: all
all: a.out

a.out: $(obj)
	gcc $(flags) -o $@ $^

$(obj): obj/%.o: src/%.c
	mkdir -p $(dir $@)
	gcc -c $(flags) -o $@ $<

.PHONY: run
run:
	python run.py a.in | ./a.out
