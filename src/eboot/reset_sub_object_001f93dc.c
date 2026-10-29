/* HSTMATCH module=EBOOT.BIN start=0x001f93dc end=0x001f94a4 symbol=FUN_001f93dc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/target_holder.h"

extern TargetRec *FUN_00218c00(TargetRec *);
extern void FUN_00219184(TargetRec *, int);
extern void FUN_00219210(TargetRec *);
extern void FUN_00219a50(TargetRec *, int);
extern void *FUN_00000bcc(unsigned);

/* Re-creates the target record (if one exists), refills it from the mirrored floats and runs its helper ten times. */
void FUN_001f93dc(TargetHolder *o)
{
  int i;
  TargetRec *mem;
  TargetRec *s;
  float f5, f6, f7, f8, f9;
  o->unk568 = 1;
  o->unk580 = 0.0f;
  if (o->rec != 0) {
    if (o->rec != 0) {
      FUN_00219184(o->rec, 1);
      o->rec = 0;
    }
    mem = FUN_00000bcc(TARGET_REC_SIZE);
    if (mem != 0) {
      mem = FUN_00218c00(mem);
    }
    o->rec = mem;
  }
  FUN_00219a50(o->rec, 2);
  f7 = o->unk574;
  f5 = o->unk580;
  f8 = o->unk57c;
  f6 = o->unk578;
  s = o->rec;
  i = 0;
  f9 = f7 + f5;
  s->unk10 = o->unk570;
  s->unk14 = f9;
  s->unk18 = f6;
  s->unk1c = f8;
  do {
    FUN_00219210(o->rec);
    i++;
  } while (i < 10);
}
