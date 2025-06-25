#
# 'make'        build executable file 'main'
# 'make clean'  removes all .o and executable files
#

CXX = g++

CXXFLAGS	:= -std=c++17 -Wall -Wextra -g

OUTPUT	:= output

SRC		:= src

INCLUDE	:= include

ifeq ($(OS),Windows_NT)
MAIN	:= main.exe
SOURCEDIRS	:= $(SRC)
INCLUDEDIRS	:= $(INCLUDE)
FIXPATH = $(subst /,\,$1)
RM			:= del /q /f
MD	:= mkdir
MKDIR_P = if not exist "$(subst /,\,$(dir $@))" mkdir "$(subst /,\,$(dir $@))"
else
MAIN	:= main
SOURCEDIRS	:= $(shell find $(SRC) -type d)
INCLUDEDIRS	:= $(shell find $(INCLUDE) -type d)
FIXPATH = $1
RM = rm -f
MD	:= mkdir -p
MKDIR_P = mkdir -p $(dir $@)
endif

# ===================================================================

# define the C source files
SOURCES	:= $(wildcard $(patsubst %,%/*.cpp, $(SOURCEDIRS)))

# create object file names under the output directory
OBJECTS := $(patsubst $(SRC)/%.cpp,$(OUTPUT)/%.o,$(SOURCES))

# include flags
INCLUDES := $(patsubst %,-I%,$(INCLUDEDIRS))

# Output binary path
OUTPUTMAIN := $(call FIXPATH,$(OUTPUT)/$(MAIN))



all: $(OUTPUT) $(MAIN)
	@echo Executing 'all' complete!

$(OUTPUT):
	$(MD) $(OUTPUT)

# Pattern rule to compile .cpp to .o into output folder
$(OUTPUT)/%.o: $(SRC)/%.cpp
	$(MKDIR_P)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(MAIN): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(OUTPUTMAIN) $(OBJECTS)


# this is a suffix replacement rule for building .o's and .d's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file)
# -MMD generates dependency output files same name as the .o file
# (see the gnu make manual section about automatic variables)
.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(OUTPUTMAIN)
	$(RM) $(call FIXPATH,$(OBJECTS))
	@echo Cleanup complete!

run: all
	./$(OUTPUTMAIN)
	@echo Executing 'run: all' complete!
