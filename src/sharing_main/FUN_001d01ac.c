/* HSTMATCH module=hstp_trans_main.prx start=0x001d01ac end=0x001d020c symbol=FUN_001d01ac lang=c99 */
/* Clone of src/eboot/FUN_001c1f98.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
extern int FUN_00000788();
extern void FUN_00000a00();
extern void FUN_0008e7c8();

#define SUBOBJ_OFFSET 0x18
#define SUBOBJ_SIZE 0x120
#define SUBOBJ_COUNT 4

/* Deleting-destructor wrapper: destroys the four sub-objects, then frees the object when the flag is positive. */
int FUN_001d01ac(int self,short deleteFlag)
{
  if ((self != 0) && (FUN_00000788(self + SUBOBJ_OFFSET,FUN_0008e7c8,SUBOBJ_SIZE,SUBOBJ_COUNT), 0 < deleteFlag)) {
    FUN_00000a00(self);
  }
  return self;
}
