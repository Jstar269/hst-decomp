/* HSTMATCH module=hstp_trans_main.prx start=0x00136cd4 end=0x00136d54 symbol=FUN_00136cd4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct {
  char pad0[0x110];
  int f110;
  char pad1[0x10];
  int f124;
  char pad2[0x1c];
  int f144;
} Sub;
typedef struct {
  char pad0[0x58];
  Sub *sub;
} Obj;

extern int FUN_00095a24(Obj *, int);

int FUN_00136cd4(Obj *self)
{
  Sub *p = self->sub;
  int idx = p ? p->f124 : -1;
  if (idx >= 0) {
    if (FUN_00095a24(self, 1) != 0 && p != 0) {
      return p->f144 < 0;
    }
  } else {
    if (FUN_00095a24(self, 0) != 0 && p != 0) {
      return p->f110 < 0;
    }
  }
  return 0;
}
