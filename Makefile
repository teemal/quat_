CC=gcc
CFLAGS= -Wextra  -Wall -Waddress \
-Wno-attribute-warning -Wsizeof-pointer-div -Wstack-protector \
-Wsuggest-final-types   -Wsuggest-final-methods \
-Wvector-operation-performance -Wno-unused-variable #turn unused vars back on during debugging

all: quat lin_math_test

quat.o: quat.c
	$(CC) $(CFLAGS) -c quat.c

lin_math_test:
	$(CC) lin_math_test.c /home/osboxes/Desktop/Unity/src/unity.c -o lin_math_test

clean:
	rm -f quat lin_math_test *.o *.gch

comment="1"

git:
ifeq ($(comment),"1")
	@echo "Naughty naughty! Add comments with make git comment=\"comment_here\""
else
	git add . && git commit -m "$(comment)"
endif
