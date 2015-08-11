CXX = clang++
CXXFLAGS = -std=gnu++11 -stdlib=libc++ -Weverything -D DEBUG
EXEC = report
OBJECTS = report.o debugging.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
