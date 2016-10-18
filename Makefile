all:
	g++ -g -Wall --std=c++11 -c BigNumber.cpp
	g++ -g -Wall --std=c++11 BigNumber.o test.cpp 

clean:
	rm -rf BigNumber.o a.out
