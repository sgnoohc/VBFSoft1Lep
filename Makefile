# ROOTSYS should be defined in the shell
ROOTCONFIG:= $(ROOTSYS)/bin/root-config
ROOTCFLAGS:= $(shell $(ROOTCONFIG) --cflags)
ROOTLDFLAGS:= $(shell $(ROOTCONFIG) --ldflags)
ROOTLIBS:= $(shell $(ROOTCONFIG) --libs)
ROOTGLIBS:= $(shell $(ROOTCONFIG) --glibs)

# Compiler
CXX             = g++
LD              = g++

# Flags -g turns on debugging capability for gdb
CXXFLAGS        = -g -O -Wall -fPIC $(ROOTCFLAGS)
LDFLAGS         = -O $(ROOTLDFLAGS)

# Note: -lTreePlayer
GLIBS           = $(ROOTGLIBS) -lTMVA

# Executable
OBJS            = src/Mva.o

# Targets
all:    clean \
                $(OBJS)
                @echo "Linking $@"
                $(LD) $(LDFLAGS) $(GLIBS) $(OBJS) -o bin/Mva.exe

clean:
		@rm -fv core $(OBJS) $(EXES) src/*.o bin/Mva.exe

.SUFFIXES: .C .cxx .o

.cxx.o:
		$(CXX) $(CXXFLAGS) -c $<
		@echo "Compiling $< with $(ROOTSYS)"
		mv -v *.o src/

#eof
