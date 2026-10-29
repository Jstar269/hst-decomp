/* HSTMATCH module=EBOOT.BIN start=0x0012704c end=0x001270a8 symbol=FUN_0012704c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: parameter typed as a pointer (not int) so the base copy goes to a0 before the jal and the +0x1d0 address in the delay slot; readability pass; exact match verified; names and types await human review. */
#include "hst/motion_obj.h"

extern void FUN_00093cc8(MotionObj *);
extern void FUN_0012a254(MotionObj *, int, int, int);
extern void FUN_0012aa6c(MotionObj *, int, char *);
extern void FUN_0012ac28(MotionObj *);

/* Reset the object to motion kind 0 and run its setup helpers. */
void FUN_0012704c(MotionObj *self, int arg)
{
  FUN_0012a254(self,0,-1,0);
  FUN_0012aa6c(self,arg,self->data1d0);
  FUN_00093cc8(self);
  FUN_0012ac28(self);
}
