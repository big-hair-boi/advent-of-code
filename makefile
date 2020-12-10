# Constants
CXX       := g++
CXX_FLAGS := -std=c++14


# Targets
csv_reader:
	$(CXX) $(CXX_FLAGS) -c ./helper-classes/csv_reader.cc
