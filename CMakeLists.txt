cmake_minimum_required(VERSION 3.2)

project(test CXX)

# --------------------------------------
# Executable files
# --------------------------------------
set(SRC
	source/Parser/Parser.h
	source/Parser/Parser.cpp
	source/SimpleExpr/virtualExpr.h
	source/SimpleExpr/Constant.h
	source/SimpleExpr/Constant.cpp
	source/SimpleExpr/Operation.h
	source/SimpleExpr/Operation.cpp
	source/SimpleExpr/Function.h
	source/SimpleExpr/Function.cpp
	source/Factory/Factory.h
	source/Factory/Factory.cpp
	source/Data/OperationList.h
	source/Data/OperationList.cpp
	source/Data/FunctionList.h
	source/Data/FunctionList.cpp
	source/Expression/Expression.h
	source/Expression/Expression.cpp
)

add_executable(${PROJECT_NAME} main.cpp ${SRC})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
