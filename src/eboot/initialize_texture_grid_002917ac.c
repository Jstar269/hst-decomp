/* HSTMATCH module=EBOOT.BIN start=0x002917ac end=0x00291868 symbol=FUN_002917ac lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: typed the mixed float arguments, stack depth float, and final color argument; readability pass; exact match verified; names and types await human review. */
extern void FUN_00051490(void *tex,int x,int y,int width,int height,int src_x,int src_y);
extern void FUN_0005185c(void *tex);
extern void FUN_00051894(void *tex,float u0,float v0,float x0,float y0,float u1,float v1,float x1,float y1,float z,unsigned int color);

/* Draws a 480x272 texture as four 120-pixel-wide vertical strips. */
void FUN_002917ac(void *tex)
{
  float x;
  int strip;
  
  FUN_00051490(tex,0,0,0x1e0,0x110,0,0);
  x = 0.0f;
  strip = 0;
  do {
    FUN_00051894(tex,x,0.0f,x,0.0f,x + 120.0f,272.0f,x + 120.0f,272.0f,65535.0f,0x80808080);
    strip = strip + 1;
    x = x + 120.0f;
  } while (strip < 4);
  FUN_0005185c(tex);
  return;
}
