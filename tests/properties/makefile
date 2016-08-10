CXX      := clang++
CFLAGS   := -std=c++11 -g
INCLUDES := -I../../include

SRC      := $(wildcard *.cpp)
PROGS    := $(SRC:%.cpp=%)

all: $(PROGS)

%: %.cpp
	$(CXX) $(CFLAGS) $(INCLUDES) -o $@ $<
