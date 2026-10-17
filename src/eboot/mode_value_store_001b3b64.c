/* HSTMATCH module=EBOOT.BIN start=0x001b3b64 end=0x001b3bac symbol=FUN_001b3b64 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: pointer arithmetic replaced by a struct view, branch order swapped (`param_2 >= 0` tested first) and the sum written `f7a4 * 2 + 0x98 + param_2`; exact match verified; names and types await human review. */
typedef struct Obj_001b3b64 {
  char pad000[0x7a4];
  int f7a4;
  char pad7a8[0x20];
  int f7c8;
} Obj_001b3b64;

void FUN_001b3b64(Obj_001b3b64 **param_1, int param_2)
{
  Obj_001b3b64 *o = *param_1;
  if (o->f7a4 == 6) {
    o->f7c8 = 0x81;
  } else if (param_2 >= 0) {
    o->f7c8 = o->f7a4 * 2 + 0x98 + param_2;
  } else {
    o->f7c8 = 0x1da;
  }
}
