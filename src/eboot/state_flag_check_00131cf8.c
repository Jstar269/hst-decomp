/* HSTMATCH module=EBOOT.BIN start=0x00131cf8 end=0x00131d58 symbol=FUN_00131cf8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: restructured as typed struct accesses (unsigned char flag, lbu) with 'if (mode == 7 && flag == 0) r = 1; else if (flag != 0) r = F();'; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef struct Sub { char pad[0x78]; unsigned char flag; } Sub;
typedef struct Obj { char pad[0x80]; Sub *p; } Obj;

extern undefined * DAT_003386b0;
extern byte FUN_00131d58();

byte FUN_00131cf8(Obj *o)
{
  byte r = 0;
  if (*(int *)(DAT_003386b0 + 0x3c) == 7 && o->p->flag == 0) {
    r = 1;
  } else if (o->p->flag != 0) {
    r = FUN_00131d58();
  }
  return r;
}
