train_bus_executable: driver.o cargo.o person.o train.o bus.o
	g++ -o train_bus_executable driver.o cargo.o person.o train.o bus.o -std=c++11

driver.o: driver.cpp cargo.h person.h train.h bus.h transportee.h transporter.h
	g++ -c driver.cpp 

cargo.o: cargo.cpp cargo.h
	g++ -c cargo.cpp

person.o: person.cpp person.h
	g++ -c person.cpp

train.o: train.cpp train.h
	g++ -c train.cpp

bus.o: bus.cpp bus.h
	g++ -c bus.cpp

clear: 
	rm *.o