src = $(shell find src -type f -name "*.c")
obj = $(src:src/%.c=obj/%.o)

cc = gcc # x86_64-w64-mingw32-gcc

flags = -Og -g -Isrc -Wall -DTermColor

.PHONY: all
all: a.out

.PHONY: clean
clean:
	rm -rf obj

.PHONY: run
run: a.out
	python run.py a.in | ./a.out

a.out: $(obj)
	$(cc) $(flags) -o $@ $^

$(obj): obj/%.o: src/%.c
	mkdir -p $(dir $@)
	$(cc) -c $(flags) -o $@ $<

.PHONY: windows
windows: cc = x86_64-w64-mingw32-gcc
windows: flags := $(filter-out -DTermColor, $(flags))
windows: all

