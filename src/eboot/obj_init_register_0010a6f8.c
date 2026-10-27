/* HSTMATCH module=EBOOT.BIN start=0x0010a6f8 end=0x0010a7cc symbol=FUN_0010a6f8 lang=c99 data=0x002d8ee4 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d8ee4-0x002d8f1a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern void *FUN_00011090(void *, void *, int);
extern void *FUN_000114c0(void *, int, int);
extern int FUN_0010a4a8(char *, int);
extern void FUN_00199280(void *);
extern int FUN_002b7c48(void *);

struct Obj;
struct Cfg { int size, a, b, c0, c1, c2, c3; int pad[5]; int user; struct Obj *self; int pad2[3]; };
struct Obj { char src[12]; struct Cfg cfg; };

int FUN_0010a6f8(struct Obj *o, int user, void *src)
{
  int r;

  FUN_000114c0(&o->cfg, 0, 0x44);
  o->cfg.size = 0x44;
  o->cfg.a = 0;
  o->cfg.b = 0;
  o->cfg.c0 = 0x11;
  o->cfg.c1 = 0x13;
  o->cfg.c2 = 0x12;
  o->cfg.c3 = 0x10;
  FUN_00199280(&o->cfg);
  o->cfg.user = user;
  if (src == 0) {
    FUN_000114c0(o, 0, 0xc);
  } else {
    FUN_00011090(o, src, 0xc);
  }
  o->cfg.self = o;
  r = FUN_002b7c48(&o->cfg);
  if (r != 0) {
    r = FUN_0010a4a8("ERROR: sceUtilityNetconfInitStart failed. ret = 0x%x\n", r);
  }
  return r;
}
