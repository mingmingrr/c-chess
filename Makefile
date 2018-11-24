src = $(shell find src -type f -name "*.c")
obj = $(src:src/%.c=obj/%.o)

flags = -Og -g -Isrc

.PHONY: all
all: $(obj)
	gcc -o a.out $(flags) $^

$(obj): obj/%.o: src/%.c
	gcc -c $(flags) -o $@ $<
