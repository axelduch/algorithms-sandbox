all: populate_db

populate_db: populate_db.o IOHelper.o
	g++ populate_db.o IOHelper.o -o populate_db.elf

IOHelper.o: IOHelper.cpp
	g++ -c IOHelper.cpp

populate_db.o: populate_db.cpp
	g++ -c populate_db.cpp

clean:
	rm -rf *o populate_db