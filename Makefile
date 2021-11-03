CC=gcc
FLAGS=-Wall -g
AR=ar -rc
BCo=basicClassification.o
ACLo=advancedClassificationLoop.o
ACRo=advancedClassificationRecursion.o
BCc=basicClassification.c
ACLc=advancedClassificationLoop.c
ACRc=advancedClassificationRecursion.c

# all: main1.c advancedClassificationLoop.c basicClassification.c
# 	$(CC) $(FLAGS) -o all main1.c NumClass.h advancedClassificationLoop.c basicClassification.c  -lm -I.

all: loops recursives recursived loopd mains maindloop maindrec

#Makefile's 1st requirement.
loops: stage1
	$(AR) libclassloops.a $(BCo) $(ACLo)
stage1: $(BCc) $(ACLc)
	$(CC) $(FLAGS) -c $(BCc) -c $(ACLc)

#Makefile's second requirement.
recursives: stage2
	$(AR) libclassrec.a $(BCo) $(ACRo)
stage2: $(BCc) $(ACRc)
	$(CC) $(FLAGS) -c $(BCc) -c $(ACRc)

#Makefile's third requirement.
recursived: stage3
	$(CC) $(BCo) $(ACRo) -shared -o libclassrec.so
stage3: $(BCc) $(ACRc)
	$(CC) $(FLAGS) -c $(BCc) -c $(ACRc)

#Makefile's fourth requirement.
loopd: stage4
	$(CC) $(BCo) $(ACLo) -shared -o libclassloops.so
stage4: $(BCc) $(ACLc)
	$(CC) $(FLAGS) -c $(BCc) -c $(ACLc)

#Makefile's fifth requirement.
mains:
	$(CC) main.c -L. libclassrec.a -o mains -lm -I.

#Makefile's sixth requirement.
maindloop:
	$(CC) main.c -L. libclassrec.a libclassloops.so -o maindloop -lm -I.

#Makefile's seventh requirement.
maindrec:
	$(CC) main.c -L. libclassrec.a libclassloops.so libclassrec.so -o maindrec -lm -I.

.PHONY: clean
clean:
	rm -f all *.o