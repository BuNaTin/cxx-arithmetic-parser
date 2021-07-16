
# Simple arithmetic parser #

### Table of contents: ###

#### 1. Motivation ####
#### 2. Principle of operation ####
#### 3. Small info ####
#### 4. Syntactic conventions ####
#### 5. Users methods ####

1. ##### Motivation: #####
This tiny and minor project is a training model.
Writing this project I wanted to practice modern cxx, nothing more.
I think this realization is very simple and easy to understand.
2. ##### Principle of operation: #####
I try to do Expression look like the built-in type,
so it works quite safe (but not fast yet).
Basic functionality was realized in microsystems.
In the head of architecture is pattern composite, which uses Factory to correctly create "leaves".
The expression class is only a safe wrapper over other classes.
A factory class is a nice dot to recognize how an arithmetical tree is building:
Parser tries to find the lower operation and Factory make from it new Operation leaf:
from:

    2+3/5
firstly, it finds +:

	 +
	 2 3/5
secondly, it finds /:

      +
    2  /
      3 5
and then get an answer by recursive method Calc().

3. ##### Small info: #####
The expression can calculate simple operations like +,-,multiply,/,^ (like pow), and some simple functions: 
sin, cos, tan, sqrt. that really small list of operations, but adding them is quite simple 
(you only need to modify OperationList.cpp or FunctionList.cpp files)
All classes are non-copy before I see how the fate of the project will develop.

4. ##### Syntactic conventions: #####
unique_ptr type has mark: name_up;
iterator_ type has mark: name_iter;

5. ##### Users methods: #####
class Expression had only 1 constructor from a string (yet), 
and 1 method - Calc() returning double.