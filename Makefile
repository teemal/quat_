CC=gcc
CFLAGS= -Wextra  -Wall -Wno-sizeof-array-argument -Waddress \
-Wno-attribute-warning -Wsizeof-pointer-div -Wstack-protector \
-Wsuggest-final-types   -Wsuggest-final-methods \
-Wvector-operation-performance -Wno-unused-variable #turn unused vars back on during debugging
LDFLAGS=-lm

all: quat_test IMU_to_curr_vec3

quat_test:
	$(CC) $(CFLAGS) quat_test.c $(LDFLAGS) -o quat_test

IMU_to_curr_vec3.o: IMU_to_curr_vec3.c
	$(CC) $(CFLAGS) -c IMU_to_curr_vec3.c

# RC_PWM_to_vec3: RC_PWM_to_vec3.c
# 	$(CC) $(CFLAGS) -o  RC_PWM_to_vec3 RC_PWM_to_vec3.c IMU_to_curr_vec3.c $(LDFLAGS)


#test_PWM_in_to_vec3.o:
#	$(CC) $(CFLAGS) test_PWM_in_to_vec3.c $(LDFLAGS) -o test_PWM_in_to_vec3

clean:
	rm -f test_PWM_in_to_vec3 IMU_to_curr_vec3 quat_test *.o *.gch

comment="1"

git:
ifeq ($(comment),"1")
	@echo "Naughty naughty! Add comments with make git comment=\"comment_here\""
else
	git add . && git commit -m "$(comment)"
endif
