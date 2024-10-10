driver: driver.o
	g++ driver.o -o driver

driver.o: driver.cpp linkedlist.h node.h arraylist.h
	g++ -c driver.cpp

clean:
	rm *.o driver
