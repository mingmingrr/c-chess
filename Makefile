src = $(shell find src -type f -name "*.c")
obj = $(src:src/%.c=obj/%.o)

flags = -Og -g -Isrc -Wall

.PHONY: all
all: a.out

a.out: $(obj)
	gcc $(flags) -o $@ $^

$(obj): obj/%.o: src/%.c
	gcc -c $(flags) -o $@ $<


