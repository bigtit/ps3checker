ps3checker: tmain.o checker.o
	g++ -o ps3checker tmain.o checker.o
tmain.o: tmain.cc checker.h
	cc -c tmain.cc -std=c++11
checker.o: checker.cc checker.h
	cc -c checker.cc -std=c++11
clean:
	rm *.o
