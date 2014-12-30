CPPFLAGS=-std=c++11
OBJECTS=scanner.o

%.hh.gch: %.hh
	$(CXX) -c $(CPPFLAGS) $< -o $@
%.o: %.cc
	$(CXX) -c $(CPPFLAGS) $< -o $@

all: $(OBJECTS)

clean:
	$(RM) $(OBJECTS)
