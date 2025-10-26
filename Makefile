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
		  install -m 755  digiclock /usr/bin/
		  mkdir -p /usr/share/digiclock
		  install -m 644  TARBALL/clock.png /usr/share/digiclock/clock.png
		  install -m 644  TARBALL/digiclock.desktop /usr/share/applications
tarball		: digiclock
		  cp digiclock TARBALL/
		  mv TARBALL DigiClock
		  tar czvf digiclockbin.tgz DigiClock
		  mv DigiClock TARBALL
		  rm TARBALL/digiclock
clean	:  
	   rm -f *.o digiclock
