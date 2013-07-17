all: populate_db

populate_db: populate_db.o IOHelper.o
	g++ populate_db.o IOHelper.o -o populate_db.elf

preprocess: preprocess.o IOHelper.o
	g++ preprocess.o IOHelper.o -o preprocess.elf

IOHelper.o: IOHelper.cpp
	g++ -c IOHelper.cpp

populate_db.o: populate_db.cpp
	g++ -c populate_db.cpp

preprocess.o: preprocess.cpp
	g++ -c preprocess.cpp

clean:
	rm -rf *o populate_db
