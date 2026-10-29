/* HSTMATCH module=EBOOT.BIN start=0x001c1f98 end=0x001c1ff8 symbol=FUN_001c1f98 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
extern int FUN_00000788();
extern void FUN_00000a00();
extern void FUN_0008d07c();

#define SUBOBJ_OFFSET 0x18
#define SUBOBJ_SIZE 0x120
#define SUBOBJ_COUNT 4

/* Deleting-destructor wrapper: destroys the four sub-objects, then frees the object when the flag is positive. */
int FUN_001c1f98(int self,short deleteFlag)
{
  if ((self != 0) && (FUN_00000788(self + SUBOBJ_OFFSET,FUN_0008d07c,SUBOBJ_SIZE,SUBOBJ_COUNT), 0 < deleteFlag)) {
    FUN_00000a00(self);
  }
  return self;
}
