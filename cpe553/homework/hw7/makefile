#	Author: James Lawrence
#	Cite: Brittany DiFede


CXX := g++
DEBUG := -g
OPTIMIZE := -O2

COMPILE := $(CXX) $(DEBUG) $(OPTIMIZE) -c

HWOBJ := main.o shape.o cube.o cylinder.o sphere.o drawing.o
homework7: $(HWOBJ)
	$(CXX) $(DEBUG) $(HWOBJ) -o homework7

main.o: main.cc shape.hh cube.hh cylinder.hh sphere.hh drawing.hh
	$(COMPILE) $<

shape.o: shape.cc shape.hh
	$(COMPILE) $<

cube.o: cube.cc cube.hh
	$(COMPILE) $<

cylinder.o: cylinder.cc cylinder.hh
	$(COMPILE) $<

sphere.o: sphere.cc sphere.hh
	$(COMPILE) $<

drawing.o: drawing.cc drawing.hh
	$(COMPILE) $<