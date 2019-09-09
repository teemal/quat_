CC=gcc
CFLAGS= -Wextra  -Wall -Waddress \
-Wno-attribute-warning -Wsizeof-pointer-div -Wstack-protector \
-Wsuggest-final-types   -Wsuggest-final-methods \
-Wvector-operation-performance -Wno-unused-variable #turn unused vars back on during debugging

all: quat quat_test

quat.o: quat.c
	$(CC) $(CFLAGS) -c quat.c

quat_test.o: quat_test.c
	$(CC) $(CFLAGS) -c quat_test.c

clean:
	rm -f quat *.o *.gch

comment="1"

git:
ifeq ($(comment),"1")
	@echo "Naughty naughty! Add comments with make git comment=\"comment_here\""
else
	git add . && git commit -m "$(comment)"
endif
