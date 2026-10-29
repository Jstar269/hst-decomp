/* HSTMATCH module=EBOOT.BIN start=0x00258180 end=0x00258294 symbol=FUN_00258180 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a3) corrected by hand: typed the pointer walk and ordered the cursor and count locals to match the loop registers; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

#define CHILD_COUNT 4
#define CHILD_WORD 0x30 /* word index of ChildOwner.child[0], used while walking the object as a word array */
#define ENTRY_SIZE 0x458 /* bytes per entry of the entry array */
#define ENTRY_COUNT 4

/* Object with four owned children, a member at 0x24c and an array of four entries at 0x6f0. */
typedef struct ChildOwner {
  const void *vtable;               /* 0x000 */
  char pad04[0xbc];
  u32 child[CHILD_COUNT];           /* 0x0c0 owned objects, deleted and cleared */
  char padd0[0x24c - 0xd0];
  char member[0x6f0 - 0x24c];       /* 0x24c */
  char entry[ENTRY_COUNT][ENTRY_SIZE]; /* 0x6f0 */
} ChildOwner;

extern u8 DAT_00309380;
extern u8 DAT_00309968;
extern u8 DAT_0034179c;
extern void FUN_00000788();
extern void FUN_00000a00(void *);
extern u32 FUN_00049094();
extern int FUN_0005ba00();
extern u32 * FUN_00102ea4();
extern void FUN_001b3008();
extern void FUN_001b3e2c();
extern int FUN_0025a0e8();
extern void FUN_0008d72c();

/* Destructor: release the global slot state, delete the four owned children, destroy the member at 0x24c and the entry array, run the base destructor, and free the object when `flag` is positive. */
ChildOwner * FUN_00258180(ChildOwner *self,short flag)
{
  u32 i;
  u32 *cursor;
  char *member;
  
  if (self != (ChildOwner *)0x0) {
    self->vtable = &DAT_00309968;
    FUN_001b3e2c((int *)&DAT_0034179c);
    FUN_001b3008((int *)&DAT_0034179c);
    FUN_00000788(self->entry,FUN_0008d72c,ENTRY_SIZE,ENTRY_COUNT);
    if ((char *)self + 0x60 != (char *)0) {
      FUN_00049094(1);
      i = 0;
      cursor = (u32 *)self;
      do {
        if (cursor[CHILD_WORD] != 0) {
          FUN_0005ba00(cursor[CHILD_WORD],1);
          cursor[CHILD_WORD] = 0;
        }
        i = i + 1;
        cursor = cursor + 1;
      } while (i < CHILD_COUNT);
      member = self->member;
      if ((member != (char *)0x0) && (member != (char *)0x0)) {
        FUN_0025a0e8((int)member,0);
      }
    }
    if (self != (ChildOwner *)0x0) {
      self->vtable = &DAT_00309380;
      FUN_00102ea4(self,0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
