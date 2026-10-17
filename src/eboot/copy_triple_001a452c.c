/* HSTMATCH module=EBOOT.BIN start=0x001a452c end=0x001a4578 symbol=FUN_001a452c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: the FUN_001feec4 result and the object are typed structs (signed char at +0x3dd, unsigned char flag at +0x3df tested != 0), the three words copied member by member; exact match verified; names and types await human review. */
typedef struct Info_001feec4 {
  char pad0[0x3dd];
  char c3dd;
  char pad1;
  unsigned char b3df;
} Info_001feec4;

typedef struct Obj_001a452c {
  char pad0[0x2fc];
  int w2fc;
  int w300;
  int w304;
  int w308;
  int w30c;
  int w310;
} Obj_001a452c;

extern void FUN_0016baa0();
extern Info_001feec4 *FUN_001feec4();

void FUN_001a452c(Obj_001a452c *o)
{
  Info_001feec4 *info;

  info = FUN_001feec4();
  FUN_0016baa0((int)info->c3dd, info->b3df != 0);
  o->w308 = o->w2fc;
  o->w30c = o->w300;
  o->w310 = o->w304;
}
