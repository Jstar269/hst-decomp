/* HSTMATCH module=EBOOT.BIN start=0x0012b2b0 end=0x0012b360 symbol=FUN_0012b2b0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct {
  char pad00[0x334];
  int f334;
  char pad338[0x354 - 0x338];
  int f354;
  char pad358[0x35c - 0x358];
  void *f35c;
} Obj;

extern int FUN_0012b72c(void *p0, void *p1, int p2);
extern void FUN_0012ad54(void *p1, int p2, int p3, int p4, void *p5, void *p6, float p7);
extern int DAT_0033b4b0;

void FUN_0012b2b0(Obj *p1, void *p2, void *p3, float p4)
{
  int i;
  int idx;

  /* matching idiom: the helper FUN_0012b72c takes the object as its first
     argument (it is left in a0), and the table index has to be computed
     BEFORE the >= 0 test so that the plain bltz branch can carry the
     add in its delay slot. */
  i = FUN_0012b72c(p1, p1->f35c, 0);
  idx = p1->f354 + i * 2;
  if (p1->f334 >= 0) {
    FUN_0012ad54(p1, p1->f334, 1, 0, p2, p3, p4);
  } else {
    FUN_0012ad54(p1, DAT_0033b4b0 + idx, 1, 0, p2, p3, p4);
  }
}
