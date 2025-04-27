CXX = g++ -std=c++11

CXXFLAGS = -Wall
TARGETS = testbst intbst

all: $(TARGETS)
	./testbst
	./intbst

testbst: testbst.o intbst.o
	$(CXX) $(CXXFLAGS)  $^ -o $@

intbst: intbst.o
	$(CXX) $(CXXFLAGS)  $^ -o $@

clean:
	rm -f *.o $(TARGETS)
