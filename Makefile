CC=gcc
CFLAGS= -Wextra  -Wall -Wno-sizeof-array-argument -Waddress \
-Wno-attribute-warning -Wsizeof-pointer-div -Wstack-protector \
-Wsuggest-final-types   -Wsuggest-final-methods \
-Wvector-operation-performance -Wno-unused-variable #turn unused vars back on during debugging
LDFLAGS=-lm

all: lin_math_test quat_test

lin_math_test:
	$(CC) lin_math_test.c /home/osboxes/Desktop/Unity/src/unity.c -o lin_math_test

quat_test.o: quat_test.c
	$(CC) $(CFLAGS) -c quat_test.c $(LDFLAGS)

clean:
	rm -f quat lin_math_test *.o *.gch

comment="1"

git:
ifeq ($(comment),"1")
	@echo "Naughty naughty! Add comments with make git comment=\"comment_here\""
else
	git add . && git commit -m "$(comment)"
endif
