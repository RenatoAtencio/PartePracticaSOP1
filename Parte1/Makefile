CXX=g++
#LIBRARY=-L/usr/local/include/libcppsim
#INCLUDE=-I/usr/local/include/nlohmann -I/usr/local/include/libcppsim
CXXFLAGS=-std=c++14 -O3 -ggdb -Wall -w -lm -g #-lcppsim $(INCLUDE) $(LIBRARY)


OBJS1=obj/main.o 
#OBJS2=obj/platformhardware.o 

TARGET=app

$(TARGET): $(OBJS1) #$(OBJS2) $(OBJS3) $(OBJS4) $(OBJS5) $(OBJS6) $(OBJS7)
	        $(CXX) -o $@ $^ $(CXXFLAGS)

obj/main.o:src/main.cpp
#obj/platformsim.o:src/platformsim.cpp include/platformsim.h

obj/%.o:
	$(CXX) -o $@ -c $< $(CXXFLAGS)
clean:
	${RM} $(TARGET)
	${RM} obj/*.o
	${RM} *~

all:
	make clean
	make