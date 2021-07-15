
	Simple arithmetic parser

	#Table of contents:
(1): Motivation
(2): Principle of operation
(3): Small info
(4): Syntactic conventions
(5): Users methods


(1):
Motivation:
This tiny and minor project is a training model.
Writing this project i wanted to practice modern cxx, nothing more.
I think this realisation is very simplr and easy to understand.

(2):
Principle of operation:
i try to do Expression look like an built-in type,
so it works quite safe (but not fast yet).
Basic functionality was realised by microsystems.
In head of architecture is pattern composite, that uses Factory to correctly create "leaves".
Expression class is only a safe wrapper over other classes.
Factory class is nice dot to recognize how arithmetical tree is building:
Parser tries to find the lower operation and Factory make from it new Operation leaf:
from:

	2+3/5

first find +:

	 +
	2 3/5

second find /:

	 +
	2  /
	  3 5

and then get answer by recursive method Calc().

(3):
Small info:
Expression can calculate simple operations like +,-,multiplu,/,^ (like pow), and some simple functions: 
sin,cos,tan,sqrt. that really small list of operations, but adding them is quite simple 
(you only need to modify OperationList.cpp or FunctionList.cpp files)

All classes are non-copy before i see how the fate of the project will develop.

(4):
Syntactic conventions:

unique_ptr type has mark: name_up;
iterator_ type has mark: name_iter;

(5):
Users methods:

class Expression had only 1 constructor from string (yet), 
and 1 method - Calc() returning double.