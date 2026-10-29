/* HSTMATCH module=EBOOT.BIN start=0x001ee8ec end=0x001ee950 symbol=FUN_001ee8ec lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

/* Object whose sub-object at 0x28 has its own destructor (FUN_00054554). */
typedef struct MemberOwner {
  char pad00[0x28];
  char member[1];  /* 0x28 */
} MemberOwner;

extern void FUN_00000a00();
extern int * FUN_00054554();

/* Deleting destructor: destroys the sub-object, then frees the object when flags is positive. */
MemberOwner *FUN_001ee8ec(MemberOwner *self,short flags)
{
  char *member;
  
  if (self != 0) {
    member = self->member;
    if ((member != 0) && (member != 0)) {
      FUN_00054554(member,0);
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
