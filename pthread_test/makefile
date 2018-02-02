CC = g++
OBJS = *.cpp
NAME = CollisionTest
COMMON_FLAGS = -pthread
LIB_FLAGS = -lfcl -lboost_system

CPP_FLAGS = $(COMMON_FLAGS) -I/usr/local/include
LDFLAGS = -L/usr/local/lib -L/usr/lib/x86_64-linux-gnu $(LIB_FLAGS)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(OBJS) -o $(NAME) $(CPP_FLAGS) $(LDFLAGS)

debug: $(OBJS) $(HEADERS)
	$(CC) $(OBJS) -o $(NAME) $(CPP_FLAGS) $(LDFLAGS) -g

run: $(NAME)
	./$(NAME) 
drd: $(NAME)
	valgrind --tool=drd ./$(NAME)

helgrind: $(NAME)
	valgrind --tool=helgrind ./$(NAME)
clean:
	rm -rf $(NAME)*
