
CXX=clang++
CXX_FLAGS=-std=c++20 -Iincludes -g -fstandalone-debug -O0 -Wall -Wextra -Werror

exec: bin/exec
test: bin/test

bin/exec: ./entry/main.cpp ./src/buildGraph.cpp ./src/buildHelper.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@

bin/test: ./tests/test.cpp ./src/buildGraph.cpp ./src/buildHelper.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@

.DEFAULT_GOAL := exec
.PHONY: exec test clean

clean:
	rm -f bin/*