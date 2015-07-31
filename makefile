CXX = clang++
CXXFLAGS = -std=gnu++11 -stdlib=libc++ -Weverything
EXEC = report
OBJECTS = report.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
