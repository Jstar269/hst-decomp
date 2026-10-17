/* HSTMATCH module=EBOOT.BIN start=0x00096c2c end=0x00096d1c symbol=FUN_00096c2c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: restored switch case dispatch and short-circuit checks; exact match verified; names and types await human review. */
typedef struct { char pad[0x148]; int index; } Obj;
extern int DAT_00338b44;
extern unsigned char DAT_00341837[];
extern int DAT_0034a77c;
extern int FUN_000dbc54(int, int);
extern int FUN_0024de88(int, int, int);

int FUN_00096c2c(Obj *self, int mode)
{
  switch (mode) {
  case 1:
  case 3:
  case 8:
  case 11:
  case 14:
    if ((FUN_000dbc54(DAT_00338b44, 17) != 0) ||
        (FUN_000dbc54(DAT_00338b44, 18) != 0) ||
        (FUN_000dbc54(DAT_00338b44, 19) != 0))
      return 1;
    break;
  default:
    break;
  }
  return FUN_0024de88(DAT_0034a77c, mode,
                      DAT_00341837[self->index * 0x120]);
}
