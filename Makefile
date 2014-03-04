CXX=g++ -Wall -O3
CXX_LIB=-fpic -shared
LIB_LIBS=-lX11
TEST_LIBS=-L./ -lgarf
TEST_MAIN=test
TEST_OBJECTS=test.o
LIB_OBJECTS=GApplication.o GDisplay.o GWidget.o GButton.o GObject.o
SHARED_LIB=libgarf.so
PREFIX=/usr/lib

all:	${SHARED_LIB} ${TEST_MAIN}

install: ${SHARED_LIB}
	cp ${SHARED_LIB} ${PREFIX}/${SHARED_LIB}

uninstall:
	rm -f ${PREFIX}/${SHARED_LIB}

libgarf.so: ${LIB_OBJECTS}
	${CXX} ${CXX_LIB} -o libgarf.so ${LIB_OBJECTS} ${LIB_LIBS}

test:	${TEST_OBJECTS} ${SHARED_LIB}
	${CXX} -o test ${TEST_OBJECTS} ${TEST_LIBS}

main.o:	main.cpp
	${CXX} -c main.cpp
	
GWidget.o:	GWidget.cpp
	${CXX} ${CXX_LIB} -c GWidget.cpp
	
GButton.o:	GButton.cpp
	${CXX} ${CXX_LIB} -c GButton.cpp
	
GApplication.o:	GApplication.cpp
	${CXX} ${CXX_LIB} -c GApplication.cpp
	
GDisplay.o:	GDisplay.cpp
	${CXX} ${CXX_LIB} -c GDisplay.cpp
	
GObject.o:	GObject.cpp
	${CXX} ${CXX_LIB} -c GObject.cpp

GDisplay.cpp:	GDisplay.h GException.h
GObject.cpp:	GObject.h
QWidget.cpp:	QWidget.h
GButton.cpp:	GButton.h
QApplication.cpp:	QApplication.h

again:	clean all

clean:
	rm -f ${TEST_OBJECTS} ${LIB_OBJECTS} *~ ${TEST_MAIN} ${SHARED_LIB}

