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

# Main executable
EXEC = susyvbf

# Source files and corresponding object files
SRCPATH = src
SRCS = $(wildcard $(SRCPATH)/*.cxx)
OBJS = $(SRCS:.cxx=.o)

# Main target
$(EXEC): $(OBJS)
	$(LD) $(LDFLAGS) $(GLIBS) $(OBJS) -o $(EXEC)

# To create object files
%.o: %.cxx
	$(CXX) -c $(CXXFLAGS) $< -o $@

# To remove generated files
clean:
	rm -f $(EXEC) $(OBJS)
