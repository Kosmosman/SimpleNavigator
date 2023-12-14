# CMake executable
CMAKE = cmake

# Directory to build the project
BUILDDIR = build

# Source files
GRAPH_SRC = src/Graph/s21_graph.cc
GRAPH_ALGORITHMS_SRC = src/GraphAlgorithms/s21_graph_algorithms.cc

# Object files
GRAPH_OBJ = $(GRAPH_SRC:.cc=.o)
GRAPH_ALGORITHMS_OBJ = $(GRAPH_ALGORITHMS_SRC:.cc=.o)

# Static libraries
LIBSDIR = libs
LIBS21_GRAPH = s21_graph.a
LIBS21_GRAPH_ALGORITHMS = s21_graph_algorithms.a

# Default target
all: $(BUILDDIR)/Makefile $(LIBS21_GRAPH) $(LIBS21_GRAPH_ALGORITHMS)
	$(MAKE) -C $(BUILDDIR)

# Rule to generate Makefile using CMake
$(BUILDDIR)/Makefile:
	mkdir -p $(BUILDDIR)
	cd $(BUILDDIR) && $(CMAKE) ..

# Rule to compile source files into object files
%.o: %.cc
	$(CXX) $(CXXFLAGS) -I$(dir $<) -c $< -o $@

# Rule to create the static libraries
$(LIBS21_GRAPH): $(GRAPH_OBJ)
	mkdir -p $(LIBSDIR)
	$(AR) rcs $(LIBSDIR)/$@ $^

$(LIBS21_GRAPH_ALGORITHMS): $(GRAPH_ALGORITHMS_OBJ)
	$(AR) rcs $(LIBSDIR)/$@ $^

# Clean target
clean:
	rm -rf $(BUILDDIR) $(LIBSDIR)
	rm -f $(GRAPH_OBJ) $(GRAPH_ALGORITHMS_OBJ) $(LIBSDIR)/$(LIBS21_GRAPH) $(LIBSDIR)/$(LIBS21_GRAPH_ALGORITHMS)

# Test target
test: all
	cd $(BUILDDIR) && GTEST_COLOR=1 ctest --verbose
