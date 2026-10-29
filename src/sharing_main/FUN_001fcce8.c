/* HSTMATCH module=hstp_trans_main.prx start=0x001fcce8 end=0x001fcd4c symbol=FUN_001fcce8 lang=c99 */
/* Clone of src/eboot/FUN_001ee8ec.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

/* Object whose sub-object at 0x28 has its own destructor (FUN_000550a0). */
typedef struct MemberOwner {
  char pad00[0x28];
  char member[1];  /* 0x28 */
} MemberOwner;

extern void FUN_00000a00();
extern int * FUN_000550a0();

/* Deleting destructor: destroys the sub-object, then frees the object when flags is positive. */
MemberOwner *FUN_001fcce8(MemberOwner *self,short flags)
{
  char *member;
  
  if (self != 0) {
    member = self->member;
    if ((member != 0) && (member != 0)) {
      FUN_000550a0(member,0);
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
