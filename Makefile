

SHELL:=/bin/bash

SRC:=src/descriptive_statistics.cpp main.cpp
OBJ:=src/descriptive_statistics.o main.o
HEADER:=include/descriptive_statistics.hpp

CXX:=g++
CXXFLAGS:=-O3 -march=native -msse2 -mavx -fPIC
CXXFLAGS+=-I./include -I/usr/include -I/usr/local/include
LDFLAGS:=

MKDIR=mkdir -p
INSTALL=install -s
CP=cp -a
PRINT=head -n 10

default: ds

all: libds.so ds

libds.so: src/descriptive_statistics.o
	$(CXX) $(CXXFLAGS) -o $@ -shared $^

ds: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

install: libds.so ds $(HEADER)
	$(MKDIR) $(DESTDIR)$(PREFIX)/bin
	$(MKDIR) $(DESTDIR)$(PREFIX)/lib
	$(MKDIR) $(DESTDIR)$(PREFIX)/include
	$(INSTALL) ./libds.so $(DESTDIR)$(PREFIX)/lib
	$(INSTALL) ./ds $(DESTDIR)$(PREFIX)/bin
	$(CP) $(HEADER) $(DESTDIR)$(PREFIX)/include

uninstall:	
	$(RM) $(DESTDIR)$(PREFIX)/lib/libds.so
	$(RM) $(DESTDIR)$(PREFIX)/bin/ds
	$(RM) $(DESTDIR)$(PREFIX)/include/descriptive_statistics.hpp

clean:
	$(RM) $(OBJ) ds libds.so test.output

test: 
	$(shell ./ds -wv < share/tests/test.input > test.output)
	$(PRINT) test.output
	
info:
	@echo "Targets available"
	@echo "default: ds -> descriptive stats executable "
	@echo "all: libds.so ds -> ds with libds.so "
	@echo "ds: "
	@echo "install: use with PREFIX=PATH to install files "
	@echo "uninstall: use with PREFIX=PATH to remove files"
	@echo "clean: delete object files, libraries, and executables "
	@echo "test: run tests against a set of integers"