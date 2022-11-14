CXX=clang++
INCLUDES=-Iincludes/
CXXFLAGS=-std=c++20 -g -fstandalone-debug -Wall -Wextra -Werror -pedantic $(INCLUDES)

exec: bin/exec

bin/exec: ./entry/main.cpp ./src/bfs.cpp ./src/BiliGraph.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

.DEFAULT_GOAL := tests
.PHONY: clean exec tests

clean:
	rm -fr bin/*