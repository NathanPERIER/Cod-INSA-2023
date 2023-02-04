
flags = -Wall -Wextra

all: ex1 ex2 ex3 ex4 ex5 ex8 ex9


ex1: ex1.cpp
	g++ ${flags} -o $@ $^

ex2: ex2.cpp
	g++ ${flags} -o $@ $^

ex3: ex3.cpp
	g++ ${flags} -o $@ $^

ex4: ex4.cpp
	g++ ${flags} -o $@ $^

ex5: ex5.cpp
	g++ ${flags} -o $@ $^

ex6: ex6.cpp
	g++ ${flags} -o $@ $^

ex7: ex7.cpp
	g++ ${flags} -o $@ $^

ex8: ex8.cpp
	g++ ${flags} -o $@ $^

ex9: ex9.cpp
	g++ ${flags} -o $@ $^

ex10: ex10.cpp
	g++ ${flags} -o $@ $^