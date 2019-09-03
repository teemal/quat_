CC=gcc
CFLAGS=-fsyntax-only  -fmax-errors=n -Wpedantic -pedantic-errors \
-w  -Wextra  -Wall  -Waddress  -Waddress-of-packed-member \
-Waggregate-return  -Waligned-new \
-Wno-cpp  -Wdangling-else  -Wdate-time -Wdelete-incomplete \
-Wno-attribute-warning \
-Wempty-body  -Wenum-compare  -Wno-endif-labels  -Wexpansion-to-defined \
-Werror -Wextra-semi  -Wfatal-errors \
-Wfloat-equal  -Wformat -Wformat-security  -Wformat-signedness \
-Wformat-y2k  -Wframe-address -Wincompatible-pointer-types -Wnull-dereference \
-Woverride-init-side-effects  -Woverlength-strings -Wredundant-decls \
-Wrestrict  -Wno-return-local-addr -Wreturn-type -Wshadow \
-Wfloat-conversion -Wsizeof-pointer-div -Wsizeof-pointer-memaccess \
-Wstack-protector  -Wstack-usage=byte-size  -Wstrict-aliasing \
-Wsuggest-final-types   -Wsuggest-final-methods  -Wsuggest-override \
-Wswitch -Wswitch-unreachable -Wtrampolines \
-Wvector-operation-performance

all: quat #tests

quat: quat.o
	$(CC) -o quat quat.o

quat.o: quat.h
	$(CC) -c quat.c quat.h

# tests: tests.o
# 	$(CC) -o tests tests.o

# tests.o: quat.h
# 	$(CC) -c quat_test.c quat.h

clean:
	rm -f quat quat.o

git:
	git add . && git commit -m "commiting so you don't cry later"
