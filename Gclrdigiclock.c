void ModifydigiclockGc(void *Tmp) { 
  DIALOG *D;
  Gclr *gc;
  D = (DIALOG *)Tmp;
  gc = &(D->gc);
#if 0
  kgColorTheme(D,220,220,200);
  kgColorTheme1(D,220,220,200);
  kgColorTheme2(D,220,220,200);
#endif
  kgDefineColor(49,50,255,210);
  gc->menu_char = 49;
}
