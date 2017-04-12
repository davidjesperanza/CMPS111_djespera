#----------------------------------------------------------------------
# Makefile for CMPS111 Asgn 0 : mycat
# Author : David Esperanza
# CruzID : djespera
# Description :
#    MakeFile for mycat
# April 11th,2017
#
# make                 makes mycat
# make clean           removes binaries
# ---------------------------------------------------------------------

mycat: mycat.o
        cc -o mycat mycat.o

mycat.o: mycat.c mycat.h
        cc -c mycat.c

clean :
        rm -f mycat mycat.o
