# makefile for multi-folder projects

CXX = g++
OBJDIR = obj
VPATH = src
HEAD = header
DATABASE = database
CXXFLAGS = -g -Wall -I $(HEAD)/


src = $(wildcard $(VPATH)/*.cpp) # gets all files in the *.cpp format

obj = $(subst $(VPATH), $(OBJDIR), $(src:.cpp=.o)) # replaces .cpp extention to .o extention


# the .o rules are automatically generated by the interpreter.
main: $(obj) 
	@echo "LINKING OBJECTS"
	$(CXX)  -o $@ $^

# overide of the compiler generated rules
$(OBJDIR)/%.o: %.cpp
	@echo "COMPILING SOURCE $< INTO OBJECT $@"
	@mkdir -p '$(@D)'
	@$(CXX) -c $(CXXFLAGS) $< -o $@

debug:
	@echo $(obj)

.PHONY: #clean removes all .o files
clean:
	rm -f $(obj) main


#Makefile for same folder

# CXX = g++

# # works for the implicit rules created by the interpreter
# CXXFLAGS = -g -Wall -I headers/

# OBJDIR = obj

# VPATH = src

# # src = $(wildcard $(VPATH)/*.cpp) # gets all files in the *.cpp format
# src = $(wildcard *.cpp)
# obj = $(notdir $(src:.cpp=.o))
# # obj = $(subst $(VPATH), $(OBJDIR), $(src:.cpp=.o)) # replaces .cpp extention to .o extention


# # the .o rules are automatically generated by the interpreter.
# main: $(obj) 
# 	$(CXX) -o $@ $^

# debug:
# 	@echo $(src) 

# .PHONY: #clear removes all .o files
# clean:
# 	rm -f $(obj) main
