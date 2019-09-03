CC=gcc
CFLAGS=-fsyntax-only -Wpedantic -pedantic-errors \
-w  -Wextra  -Wall  -Waddress  -Waddress-of-packed-member \
-Waggregate-return -Wno-cpp  -Wdangling-else  -Wdate-time \
-Wno-attribute-warning \
-Wempty-body  -Wenum-compare  -Wno-endif-labels  -Wexpansion-to-defined \
-Werror -Wfatal-errors \
-Wfloat-equal  -Wformat -Wformat-security  -Wformat-signedness \
-Wformat-y2k  -Wframe-address -Wincompatible-pointer-types -Wnull-dereference \
-Woverride-init-side-effects  -Woverlength-strings -Wredundant-decls \
-Wrestrict  -Wno-return-local-addr -Wreturn-type -Wshadow \
-Wfloat-conversion -Wsizeof-pointer-div -Wsizeof-pointer-memaccess \
-Wstack-protector -Wstrict-aliasing \
-Wsuggest-final-types   -Wsuggest-final-methods \
-Wswitch -Wswitch-unreachable -Wtrampolines \
-Wvector-operation-performance

all: quat #tests

quat.o: quat.c
	$(CC) -c quat.c

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
