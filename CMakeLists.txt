cmake_minimum_required(VERSION 3.2)

project(test CXX)

# prepare for QT
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)

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

	# GUI 
	gui/mainwindow.cpp
	gui/mainwindow.h
	gui/mainwindow.ui
)

add_executable(${PROJECT_NAME} main.cpp ${SRC})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core)