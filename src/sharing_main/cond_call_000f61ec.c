/* HSTMATCH module=hstp_trans_main.prx start=0x000f61ec end=0x000f622c symbol=FUN_000f61ec lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh128a) corrected by hand: typed the object as a struct (unsigned byte flag at the tested offset), float compare written `f > 0.0f` (variable on the left gives c.ngt.s/bc1t), callee receives the object (a0 passes through); exact match verified; names and types await human review. */
typedef struct Obj {
  char pad_00[0x54];
  unsigned char f54;
  char pad_55[0x2b];
  float f80;
} Obj;

extern void FUN_00108aec(Obj *);

void FUN_000f61ec(Obj *param_1)
{
  if (param_1->f54 == 0 && param_1->f80 > 0.0f) {
    FUN_00108aec(param_1);
  }
}
