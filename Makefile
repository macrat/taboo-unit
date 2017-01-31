CPPFLAGS = --std=c++11
LDFLAGS =

.PHONY: example
example: example.cpp
	${CXX} ${CPPFLAGS} ${LDFLAGS} $^ -o $@
