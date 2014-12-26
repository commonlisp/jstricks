CPPFLAGS=-std=c++11
OBJECTS=scanner.hh.gch

%.hh.gch: %.hh
	$(CXX) -c $(CPPFLAGS) $< -o $@

all: $(OBJECTS)

clean:
	$(RM) $(OBJECTS)
