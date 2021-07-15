cmake_minimum_required(VERSION 3.2)

project(test CXX)

# --------------------------------------
# Executable files
# --------------------------------------

add_executable(${PROJECT_NAME} main.cpp)


# --------------------------------------
# Libraries list
# --------------------------------------

add_library(Parser
	source/Parser/Parser.h
	source/Parser/Parser.cpp
)
add_library(virtualExpr
	source/SimpleExpr/virtualExpr.h
)
add_library(Constant
	source/SimpleExpr/Constant.h
	source/SimpleExpr/Constant.cpp
)
add_library(Operation
	source/SimpleExpr/Operation.h
	source/SimpleExpr/Operation.cpp
)
add_library(Function
	source/SimpleExpr/Function.h
	source/SimpleExpr/Function.cpp
)
add_library(Factory
	source/Factory/Factory.h
	source/Factory/Factory.cpp
)
add_library(OperationList
	source/Data/OperationList.h
	source/Data/OperationList.cpp
)
add_library(FunctionList
	source/Data/FunctionList.h
	source/Data/FunctionList.cpp
)
add_library(Expression
	source/Expression/Expression.h
	source/Expression/Expression.cpp
)
set_target_properties(virtualExpr PROPERTIES LINKER_LANGUAGE CXX)
#target_compile_features(OperationList PUBLIC cxx_std_20)

# --------------------------------------
# Linking
# --------------------------------------

#target_link_libraries(target_name
#	public | private | interface
#		lib
#)

target_link_libraries(Constant
	INTERFACE
		virtualExpr
)
target_link_libraries(Operation
	INTERFACE
		virtualExpr
	PRIVATE
		Factory
		Parser
		OperationList
)
target_link_libraries(Function
	INTERFACE
		virtualExpr
	PRIVATE
		Factory
		Parser
		FunctionList
)
target_link_libraries(Factory
	INTERFACE
		virtualExpr
	PRIVATE
		Constant
		Operation
		Function
)
target_link_libraries(Parser
	PRIVATE
		OperationList
		FunctionList
)
target_link_libraries(Expression
	INTERFACE
		virtualExpr
	PRIVATE
		Factory
)
target_link_libraries(${PROJECT_NAME} 
	PUBLIC
		Expression
)
