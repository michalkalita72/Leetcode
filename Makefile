all: Test.cpp
	g++ -g -Wall -o Two_sum Two_sum.cpp

clean: 
	del Two_sum.exe