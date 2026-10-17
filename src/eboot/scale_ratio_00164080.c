/* HSTMATCH module=EBOOT.BIN start=0x00164080 end=0x001640d0 symbol=FUN_00164080 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: object typed as a struct with two floats, and the doubled difference kept in a local before the add (matching idiom: the named local fixes the add.s operand order); exact match verified; names and types await human review. */
extern float FUN_00163aac();

typedef struct Obj_00164080 {
  char pad0[0x44];
  float f44;
  float f48;
} Obj_00164080;

float FUN_00164080(Obj_00164080 *o)
{
  float s = o->f48;
  float v = FUN_00163aac(o);
  float t = (v - o->f44) * 2.0f;
  return s * ((t + o->f44) / o->f44);
}
