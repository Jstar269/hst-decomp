/* HSTMATCH module=EBOOT.BIN start=0x0015d46c end=0x0015d4bc symbol=FUN_0015d46c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: the first global is a byte store (undefined1), the FUN_0022cd60 result is typed as a struct pointer with byte members at 0xf0/0x13d; exact match verified; names and types await human review. */
typedef unsigned char undefined1;
typedef unsigned int undefined4;

typedef struct Obj_0022cd60 {
  unsigned char pad0[0xf0];
  unsigned char flags_f0;
  unsigned char pad1[0x4b];
  unsigned char f13c;
  unsigned char f13d;
} Obj_0022cd60;

extern undefined4 DAT_002dcc1c;
extern undefined1 DAT_00340408;
extern char DAT_0034a678[];
extern Obj_0022cd60 *FUN_0022cd60();
extern void FUN_00234158();

void FUN_0015d46c(void)
{
  Obj_0022cd60 *o;

  DAT_00340408 = 0;
  DAT_002dcc1c = 0x1f;
  o = FUN_0022cd60();
  o->flags_f0 |= 4;
  o->f13d = 1;
  FUN_00234158(DAT_0034a678, 0x4b);
}
