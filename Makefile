SRCS=$(shell find src/) $(shell find tex/)

build/main.pdf: $(SRCS) Makefile scl.yaml
	mkdir -p build/
	python3.11 gen.py > build/code.tex
	cp tex/* build/
	cd build && xelatex main.tex
	cd build && xelatex main.tex

.PHONY: clean check
check:
	true # code valid check

clean:
	rm -rf build/
