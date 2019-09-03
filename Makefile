CC=gcc
CFLAGS= -Wextra  -Wall -Waddress \
-Wno-attribute-warning -Wsizeof-pointer-div -Wstack-protector \
-Wsuggest-final-types   -Wsuggest-final-methods \
-Wvector-operation-performance

all: quat #tests

quat.o: quat.c
	$(CC) $(CFLAGS) -c quat.c

# tests: tests.o
# 	$(CC) -o tests tests.o

# tests.o: quat.h
# 	$(CC) -c quat_test.c quat.h

clean:
	rm -f quat *.o *.gch

comment="1"

git:
ifeq ($(comment),"1")
	@echo "Naughty naughty! Add comments with make git comment=\"comment_here\""
else
	git add . && git commit -m "$(comment)"
endif
