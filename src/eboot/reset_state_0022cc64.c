/* HSTMATCH module=EBOOT.BIN start=0x0022cc64 end=0x0022cd38 symbol=FUN_0022cc64 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Obj {
  unsigned char f0;
  char pad1[3];
  int f4;
  unsigned char f8;
  char pad9[3];
  int fc;
  unsigned char a10[256];
  unsigned char a110[32];
  unsigned char f130;
  char pad131[3];
  int f134;
  int f138;
  unsigned char f13c;
  unsigned char f13d;
  char pad13e[2];
  int f140;
  int c144[12];
} Obj;

Obj *FUN_0022cc64(Obj *o)
{
  o->f0 = 1;
  o->f4 = 1;
  o->f8 = 1;
  o->fc = 0;
  o->f130 = 0;
  o->f134 = 1;
  o->f138 = 1;
  o->f140 = 0;
  o->f13c = 0;
  o->f13d = 0;
  for (int i = 0; i < 256; i++) {
    o->a10[i] = 0;
  }
  for (int i = 0; i < 32; i++) {
    o->a110[i] = 0;
  }
  for (int i = 0; i < 12; i++) {
    o->c144[i] = 0;
  }
  return o;
}
