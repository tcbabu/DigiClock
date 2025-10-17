KULINA=/usr
#CC	=g++ -pthread
CC	=cc -pthread
digiclock	: digiclock.o digiclockCallbacks.o digiclockmain.o
	 $(CC) -o digiclock digiclock.o digiclockCallbacks.o digiclockmain.o -I$(KULINA)/include $(KULINA)/lib/libkulina.a $(KULINA)/lib/libgm.a -L/usr/X11R6/lib -lX11 -lXext -lm -lpthread -lz -lbz2 
digiclock.o	: digiclock.c Gclrdigiclock.c 
	 $(CC) -c digiclock.c
digiclockCallbacks.o	: digiclockCallbacks.c 
	 $(CC) -c digiclockCallbacks.c
digiclockmain.o	: digiclockmain.c 
	 $(CC) -c digiclockmain.c

install		: digiclock
		  cp digiclock /usr/bin/
clean	:  
	   rm -f *.o digiclock
