/* HSTMATCH module=EBOOT.BIN start=0x001cd2a8 end=0x001cd30c symbol=FUN_001cd2a8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char *DAT_0033b574;
extern int FUN_00287418(char *);

struct Obj { char pad[0x114]; char flag; };

int FUN_001cd2a8(struct Obj *o)
{
  int r = 0;
  if (DAT_0033b574 != 0) {
    int ok = FUN_00287418(DAT_0033b574 + 0x1320) != 0;
    if (!ok) {
      ok = o->flag != 0;
    }
    if (ok) {
      r = 1;
    }
  }
  return r;
}
