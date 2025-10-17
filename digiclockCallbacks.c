#include <kulina.h>
int  digiclocksplbutton1callback(int butno,int i,void *Tmp) {
  /*********************************** 
    butno : selected item (1 to max_item) 
    i :  Index of Widget  (0 to max_widgets-1) 
    Tmp :  Pointer to DIALOG  
   ***********************************/ 
  DIALOG *D;DIL *B; 
  int n,ret=1; 
  D = (DIALOG *)Tmp;
  B = (DIL *) kgGetWidget(Tmp,i);
  n = B->nx;
  switch(butno) {
    case 1: 
      break;
  }
  return ret;
}
void  digiclocksplbutton1init(DIL *B,void *pt) {
}
int digiclockinit(void *Tmp) {
  /*********************************** 
    Tmp :  Pointer to DIALOG  
   ***********************************/ 
  /* you add any initialisation here */
  int ret = 1;
  DIALOG *D;void *pt;
  D = (DIALOG *)Tmp;
  pt = D->pt;
  return ret;
}
int digiclockcleanup(void *Tmp) {
  /* you add any cleanup/mem free here */
  /*********************************** 
    Tmp :  Pointer to DIALOG  
   ***********************************/ 
  int ret = 1;
  DIALOG *D;void *pt;
  D = (DIALOG *)Tmp;
  pt = D->pt;
  return ret;
}
int Modifydigiclock(void *Tmp,int GrpId) {
  DIALOG *D;
  D = (DIALOG *)Tmp;
  DIA *d;
  int i,n;
  d = D->d;
  i=0;while(d[i].t!= NULL) {;
     i++;
  };
  n=1;
  return GrpId;
}

int digiclockCallBack(void *Tmp,void *tmp) {
  /*********************************** 
    Tmp :  Pointer to DIALOG  
    tmp :  Pointer to KBEVENT  
   ***********************************/ 
  int ret = 0;
  DIALOG *D;
  KBEVENT *kbe;
  D = (DIALOG *)Tmp;
  kbe = (KBEVENT *)tmp;
  if(kbe->event ==1) {
    if(kbe->button ==1) {
    }
  }
  return ret;
}
int digiclockResizeCallBack(void *Tmp) {
  /*********************************** 
    Tmp :  Pointer to DIALOG  
   ***********************************/ 
  int ret = 0;
  int xres,yres,dx,dy;
  DIALOG *D;
  D = (DIALOG *)Tmp;
  kgGetWindowSize(D,&xres,&yres);
  dx = xres - D->xl;
  dy = yres - D->yl;
  /* extra code */
  D->xl= xres;
  D->yl= yres;
  kgRedrawDialog(D);
  return ret;
}
int digiclockWaitCallBack(void *Tmp) {
  /*********************************** 
    Tmp :  Pointer to DIALOG  
    Called while waiting for event  
    return value 1 will close the the UI  
   ***********************************/ 
  int ret = 0;
      static int entry = 0;
      static DIM *sp = NULL;
      static DIM *msg = NULL;
      static DIM *msgb = NULL;
      static int Minute = -1;
      char buff [ 100 ] ;
      char buff1 [ 100 ] ;


      static char *days [ 7 ] = {"Sun" , "Mon" , "Tue" , "Wed" , "Thu" , "Fri" , "Sat"};

      static char *months [ 12 ] = {"Jan" , "Feb" , "Mar" , "Apr" , "May" , "Jun" , "Jul" , "Aug" , "Sep" , "Oct" , "Nov" , "Dec"};

      time_t tp , t;
      struct tm *dt;
      int odate = -1 , ndate;
      usleep ( 10000 ) ;
      t = time ( & tp ) ;
      dt = localtime ( & t ) ;
      entry = ( ++entry ) %100;
      if ( ( entry != 0 ) && ( entry != 50 ) ) return ret;
#if 0
      if ( dt-> tm_min != Minute ) {
      }
#endif
 if ( entry ) {
          if ( sp == NULL ) {
              sp = kgGetNamedWidget ( Tmp , "TimeBox" ) ;
              msg = kgGetNamedWidget ( Tmp , "DateBox" ) ;
          }
          ndate = dt-> tm_year*10000+dt-> tm_mon*100+dt-> tm_mday;
          if ( ndate != odate ) {
              odate = ndate;
              sprintf ( buff , "!h43!w52%d   %-s" , dt-> tm_year+1900 , months [ dt-> tm_mon ] ) ;
              sprintf ( buff1 , "%d %-s" , dt-> tm_mday , days [ dt-> tm_wday ] ) ;
	      strcat(buff,buff1);
              kgWrite ( msg , buff ) ;
          }
          Minute = dt-> tm_min;
          sprintf ( buff , "!f11!h51!w61    %2.2d" , dt-> tm_hour ) ;
          strcat ( buff , ":" ) ;
          sprintf ( buff+strlen ( buff ) , "%2.2d     " , dt-> tm_min ) ;
          kgWrite ( sp , buff ) ;
      }
      else {
          if ( sp == NULL ) sp = kgGetNamedWidget ( Tmp , "Timebox" ) ;
          Minute = dt-> tm_min;
          sprintf ( buff , "!f11!h51!w61    %2.2d" , dt-> tm_hour ) ;
//          strcat ( buff , "!c00!h51!w61:!c26!h51!w61" ) ;
          strcat ( buff , " " ) ;
          sprintf ( buff+strlen ( buff ) , "%2.2d     " , dt-> tm_min ) ;
          kgWrite ( sp , buff ) ;
      }

  return ret;
}
