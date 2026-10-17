/* HSTMATCH module=EBOOT.BIN start=0x0012b868 end=0x0012b8e8 symbol=FUN_0012b868 lang=c99 */
/* Clone of src/sharing_main/sub_negative_check_00136cd4.c (hstclone.py tag c034920): addresses substituted; exact match verified; names and types await human review. */
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

extern int FUN_00093b00(Obj *, int);

int FUN_0012b868(Obj *self)
{
  Sub *p = self->sub;
  int idx = p ? p->f124 : -1;
  if (idx >= 0) {
    if (FUN_00093b00(self, 1) != 0 && p != 0) {
      return p->f144 < 0;
    }
  } else {
    if (FUN_00093b00(self, 0) != 0 && p != 0) {
      return p->f110 < 0;
    }
  }
  return 0;
}
