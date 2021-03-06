#///////////////////////////////////////////////////////////////////////////////
#//
#//
#///////////////////////////////////////////////////////////////////////////////

# primary dependencies

NAME       = VOClient
VERSION    = 1.0
PLATFORM  := $(shell uname -s)
#PLATFORM  = LINUX
#PLATFORM  = MACOSX
#PLATFORM  = CYGWIN
HERE      := $(shell /bin/pwd)


# secondary dependencies

LIBBASE    = lib$(NAME)
STATICLIB  = $(HERE)/$(LIBBASE).a
SHAREDLIB  = $(HERE)/$(LIBBASE).so.$(VERSION)


# stuff that's precious to keep

.PRECIOUS:	$(STATICLIB) $(SHAREDLIB)
.KEEP_STATE:


# includes, flags and libraries
CC 	  = gcc
CINCS  	  = -I$(HERE) -I../
#CFLAGS 	  = -g -Wall -D$(PLATFORM) $(CINCS)
CFLAGS 	  = -g -Wall -D$(PLATFORM) $(CINCS) -DVOC_DIRECT

F77 	  = g77
FFLAGS 	  = -g -Wall

XC 	  = xc
XFLAGS 	  =


# list of source and include files

SRCS = 	cone1.c cone2.c cone3.c \
	siap1.c siap2.c siap3.c siap4.c siap5.c \
	ssap1.c ssap2.c ssap3.c ssap4.c ssap5.c \
	simple.c resolver.c skybot.c \
	spptext.x \
	registry1.c registry2.c registry3.c \
	f77cone.f f77siap.f f77sesame.f f77registry.f
OBJS = 	cone1.o cone2.o cone3.o \
	siap1.o siap2.o siap3.o siap4.o siap4.o \
	ssap1.o ssap2.o ssap3.o ssap4.o ssap4.o \
	simple.o resolver.o skybot.o \
	spptest.o \
	registry1.o registry2.o registry3.o \
	f77cone.o f77siap.o f77sesame.o f77registry.o
INCS =  ../VOClient.h


# targets

all: 	demo

clean:
	/bin/rm -rf .make.state .nse_depinfo
	/bin/rm -rf simple cone1 cone2 cone3
	/bin/rm -rf siap1 siap2 siap3 siap4 siap5
	/bin/rm -rf ssap1 ssap2 ssap3 ssap4 ssap5
	/bin/rm -rf f77cone f77siap f77sesame f77registry spptest.e
	/bin/rm -rf resolver registry1 registry2 registry3 skybot
	/bin/rm -rf dataset*.fits *.o *.dSYM

everything:
	make clean
	make all
	make install

help: HELP

install: all 



###############################################################################
# Unit test programs to be built.
###############################################################################

demo:	simple resolver skybot spptest \
	cone1 cone2 cone3 \
	siap1 siap2 siap3 siap4 siap5 \
	ssap1 ssap2 ssap3 ssap4 ssap5 \
	f77cone f77siap f77sesame f77registry f77skybot \
	registry1 registry2 registry3 


###########################
#  C Test programs.
###########################

LIBS =  -L../ -lVOClient -L../../lib -lVOTable -lcfitsio -lcurl

simple: simple.c
	$(CC) $(CFLAGS) -o simple simple.c $(LIBS)

cone1:  cone1.c
	$(CC) $(CFLAGS) -o cone1  cone1.c  $(LIBS)

cone2:  cone2.c
	$(CC) $(CFLAGS) -o cone2  cone2.c  $(LIBS)

cone3:  cone3.c
	$(CC) $(CFLAGS) -o cone3  cone3.c  $(LIBS)

siap1:  siap1.c
	$(CC) $(CFLAGS) -o siap1  siap1.c  $(LIBS)

siap2:  siap2.c
	$(CC) $(CFLAGS) -o siap2  siap2.c  $(LIBS)

siap3:  siap3.c
	$(CC) $(CFLAGS) -o siap3  siap3.c  $(LIBS)

siap4:  siap4.c
	$(CC) $(CFLAGS) -o siap4  siap4.c  $(LIBS)

siap5:  siap5.c
	$(CC) $(CFLAGS) -o siap5  siap5.c  $(LIBS)

ssap1:  ssap1.c
	$(CC) $(CFLAGS) -o ssap1  ssap1.c  $(LIBS)

ssap2:  ssap2.c
	$(CC) $(CFLAGS) -o ssap2  ssap2.c  $(LIBS)

ssap3:  ssap3.c
	$(CC) $(CFLAGS) -o ssap3  ssap3.c  $(LIBS)

ssap4:  ssap4.c
	$(CC) $(CFLAGS) -o ssap4  ssap4.c  $(LIBS)

ssap5:  ssap5.c
	$(CC) $(CFLAGS) -o ssap5  ssap5.c  $(LIBS)


registry1:  registry1.c
	$(CC) $(CFLAGS) -o registry1 registry1.c $(LIBS)

registry2:  registry2.c
	$(CC) $(CFLAGS) -o registry2 registry2.c $(LIBS)

registry3:  registry3.c
	$(CC) $(CFLAGS) -o registry3 registry3.c $(LIBS)


resolver:  resolver.c
	$(CC) $(CFLAGS) -o resolver resolver.c $(LIBS)

skybot:  skybot.c
	$(CC) $(CFLAGS) -o skybot skybot.c $(LIBS)



###########################
#  Fortran Test programs.
###########################

f77cone:  f77cone.f
	$(F77) $(FFLAGS) -o f77cone f77cone.f $(LIBS)

f77siap:  f77siap.f
	$(F77) $(FFLAGS) -o f77siap f77siap.f $(LIBS)

f77sesame:  f77sesame.f
	$(F77) $(FFLAGS) -o f77sesame f77sesame.f $(LIBS)

f77skybot:  f77skybot.f
	$(F77) $(FFLAGS) -o f77skybot f77skybot.f $(LIBS)

f77registry:  f77registry.f
	$(F77) $(FFLAGS) -o f77registry f77registry.f $(LIBS)



###########################
#  IRAF Test programs.
###########################

spptest: spptest.x
	$(XC) $(XFLAGS) -o spptest.e spptest.x $(LIBS)






###############################################################################
# Leave this stuff alone.
###############################################################################

$(STATICLIB): $(SRCS:%.c=Static/%.o)
	/usr/bin/ar rv $@ $?
Static/%.o: %.c $(INCS)
	/usr/bin/gcc $(CINCS) $(CFLAGS) -c $< -o $@
Static:
	/bin/mkdir $@
	chmod 777 $@

$(SHAREDLIB): $(SRCS:%.c=Shared/%.o)
	/usr/bin/ld -shared -o $@ $? -lc -ldl
Shared/%.o: %.c $(INCS)
	/usr/bin/gcc $(CINCS) $(CFLAGS) -fpic -shared -c $< -o $@
Shared:
	/bin/mkdir $@
	chmod 777 $@
