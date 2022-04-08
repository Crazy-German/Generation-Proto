#Implicit Rules
CXX = clang++
#CXX = g++
#CXXFLAGS = -glldb -std=c++17
CXXFLAGS = -g -std=c++17
#Explicit rules
SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:.cpp=.o)


# COMPILE_SRC_DEPENDENCIES := $(patsubst src/%.cc,%.d,$(SRC))
# INTERPRETER_SRC_DEPENDENCIES := $(patsubst interpreter_src/%.cc,%.d,$(INTERPRETER_SRC))

# -include $(COMPILE_SRC_DEPENDENCIES)
# -include $(INTERPRETER_SRC_DEPENDENCIES)

GEN_UNMODIFIED_DB := temp.json
_clang 	:=  clang++ -glldb 	
_gpp 	:=  g++ 	-g 	
COMPILER := ${_clang}
#COMPILER := ${_gpp}
src_dir := src/


gen_test: $(OBJ) #Faster, Uses the compiled files
	$(COMPILER) -w -std=c++17 $(OBJ) -ogen_test

#https://clangd.llvm.org/guides/system-headers	
		
gen_cdb_noWarn: $(OBJ) 
	clang++ -MJ $(GEN_UNMODIFIED_DB) -std=c++17 $(SRC) -o_gen_test.o	
	curDir="$$(pwd | sed -e 's/\//\\\//g')";	\
	printf \\"$$curDir\n\\";					\
	sed -e '1s/^/[\n/' 							\
		-e '$$s/,$$/\n]/' 						\
		-e "s#\(\"directory\"\s*:\s*\)\(\"[^\"]*\"\)\(.*\)#\1\"$$curDir\"\3#" \
			$(GEN_UNMODIFIED_DB) > compile_commands.json

gen_cdb_someWarn: $(OBJ) 
	clang++ -MJ $(GEN_UNMODIFIED_DB) -Wall -std=c++17 $(SRC) -o_gen_test.o
	curDir="$$(pwd | sed -e 's/\//\\\//g')";	\
	printf \\"$$curDir\n\\";					\
	sed -e '1s/^/[\n/' 							\
		-e '$$s/,$$/\n]/' 						\
		-e "s#\(\"directory\"\s*:\s*\)\(\"[^\"]*\"\)\(.*\)#\1\"$$curDir\"\3#" \
			$(GEN_UNMODIFIED_DB) > compile_commands.json

gen_cdb_extraWarn: $(OBJ) 
	clang++ -MJ $(GEN_UNMODIFIED_DB) -Wall -Wextra -std=c++17 $(SRC)  -o_gen_test.o
	curDir="$$(pwd | sed -e 's/\//\\\//g')";	\
	printf \\"$$curDir\n\\";					\
	sed -e '1s/^/[\n/' 							\
		-e '$$s/,$$/\n]/' 						\
		-e "s#\(\"directory\"\s*:\s*\)\(\"[^\"]*\"\)\(.*\)#\1\"$$curDir\"\3#" \
			$(GEN_UNMODIFIED_DB) > compile_commands.json	

gen_cdb_pedanticWarn: $(OBJ) 
	clang++ -MJ $(GEN_UNMODIFIED_DB) -Wall -Wextra -Wpedantic -std=c++17 $(SRC) -o_gen_test.o
	curDir="$$(pwd | sed -e 's/\//\\\//g')";	\
	printf \\"$$curDir\n\\";					\
	sed -e '1s/^/[\n/' 							\
		-e '$$s/,$$/\n]/' 						\
		-e "s#\(\"directory\"\s*:\s*\)\(\"[^\"]*\"\)\(.*\)#\1\"$$curDir\"\3#" \
			$(GEN_UNMODIFIED_DB) > compile_commands.json				


gen_cdb_everyWarn: $(OBJ) 
	clang++ -MJ $(GEN_UNMODIFIED_DB) -Weverything -std=c++17 $(SRC) -o_gen_test.o 	
	curDir="$$(pwd | sed -e 's/\//\\\//g')";	\
	printf \\"$$curDir\n\\";					\
	sed -e '1s/^/[\n/' 							\
		-e '$$s/,$$/\n]/' 						\
		-e "s#\(\"directory\"\s*:\s*\)\(\"[^\"]*\"\)\(.*\)#\1\"$$curDir\"\3#" \
			$(GEN_UNMODIFIED_DB) > compile_commands.json
	


clean:		
	del gen_test
	del _gen_test.o
	del *.ilk
	del *.pdb	
	del src\*.o

#del .cache\clangd\index\*.idx	
		
clean_all: clean
	del -f *.dot *.json CFGs.pdf tree.pdf
	
	

# %.o: %.cc Makefile
#         $(CXX) $(WARNING) $(CXXFLAGS) -MMD -MP -c $< -o $@