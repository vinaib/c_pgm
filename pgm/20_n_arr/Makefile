CC=gcc
CFLAGS=-I.
CPP=g++

DEPS=app.o 
CPP_DEPS=cpp_app.o

default:c_app

%.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS) -g

%.o:%.cpp
	$(CPP) -c $< -o $@ $(CFLAGS) -g

c_app:$(DEPS)
	$(CC) -o $@ $^ $(CFLAGS)

cpp_app:$(CPP_DEPS)
	$(CPP) -o $@ $^ $(CFLAGS) -g

clean:
	rm -rf c_app cpp_app a.out app_exe *.o
