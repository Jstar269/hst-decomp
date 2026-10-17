/* HSTMATCH module=hstp_trans_main.prx start=0x0013d2b0 end=0x0013d310 symbol=FUN_0013d2b0 lang=c99 */
/* Clone of src/eboot/state_flag_check_00131cf8.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: restructured as typed struct accesses (unsigned char flag, lbu) with 'if (mode == 7 && flag == 0) r = 1; else if (flag != 0) r = F();'; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef struct Sub { char pad[0x78]; unsigned char flag; } Sub;
typedef struct Obj { char pad[0x80]; Sub *p; } Obj;

extern undefined * DAT_003e19f0;
extern byte FUN_0013d310();

byte FUN_0013d2b0(Obj *o)
{
  byte r = 0;
  if (*(int *)(DAT_003e19f0 + 0x3c) == 7 && o->p->flag == 0) {
    r = 1;
  } else if (o->p->flag != 0) {
    r = FUN_0013d310();
  }
  return r;
}
