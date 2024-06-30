.PHONY: all s21_graph.a s21_graph_algorithms.a clean test coverage clang

CMAKE = cmake

BUILDDIR = build

LIBSDIR = libs
LIBS21_GRAPH = s21_graph
LIBS21_GRAPH_ALGORITHMS = s21_graph_algorithms

OS := $(shell uname -s)
USERNAME=$(shell whoami)

ifeq ($(OS),Linux)
  OPEN_CMD = xdg-open
endif
ifeq ($(OS),Darwin)
	OPEN_CMD = open
endif

all: $(LIBS21_GRAPH).a $(LIBS21_GRAPH_ALGORITHMS).a SimpleNavigator test coverage clang
	$(MAKE) -C $(BUILDDIR)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)
	cd $(BUILDDIR) && $(CMAKE) ..

$(BUILDDIR)/tests: $(LIBS21_GRAPH).a $(LIBS21_GRAPH_ALGORITHMS).a $(BUILDDIR)
	$(MAKE) -C $(BUILDDIR) tests

$(BUILDDIR)/coverage:
	mkdir -p $(BUILDDIR)
	cd $(BUILDDIR) && $(CMAKE) -DENABLE_COVERAGE=ON ..

$(BUILDDIR)/SimpleNavigator: $(LIBS21_GRAPH).a $(LIBS21_GRAPH_ALGORITHMS).a $(BUILDDIR)
	cd $(BUILDDIR) && $(MAKE) SimpleNavigator

$(LIBS21_GRAPH).a: $(BUILDDIR)
	cd $(BUILDDIR) && $(MAKE) $(LIBS21_GRAPH)

$(LIBS21_GRAPH_ALGORITHMS).a: $(BUILDDIR)
	cd $(BUILDDIR) && $(MAKE) $(LIBS21_GRAPH_ALGORITHMS)

clean:
	rm -rf $(BUILDDIR) coverage coverage.info

test: $(BUILDDIR)/tests
	cd $(BUILDDIR) && GTEST_COLOR=1 ctest --verbose --output-on-failure

SimpleNavigator: $(BUILDDIR)/SimpleNavigator

coverage: $(BUILDDIR)/coverage
	$(MAKE) -C $(BUILDDIR)
	cd $(BUILDDIR) && GTEST_COLOR=1 ctest --coverage --verbose --output-on-failure
	lcov -c -d $(BUILDDIR) --output-file coverage.info --ignore-errors inconsistent
	genhtml coverage.info -o coverage
	$(OPEN_CMD) ./coverage/index.html

clang:
	clang-format -style=Google -n ./**/*.cc ./**/*.h