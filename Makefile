CXX = g++
CXXFLAGS = -std=c++11 -Iinclude

SRCDIR = src
INCDIR = include
MAIN = $(SRCDIR)/main/main.cpp
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,%.o,$(SRCS))

TARGET = solver
OBJS = $(SRCS:.cpp=.o)
.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS) $(MAIN)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)