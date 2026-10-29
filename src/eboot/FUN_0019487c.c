/* HSTMATCH module=EBOOT.BIN start=0x0019487c end=0x0019494c symbol=FUN_0019487c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p1) corrected by hand: refined by hstperm.py random mutation (perm-p1/r00/f0460_0019487c_m01.c); readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct RecordTarget {
  char pad00[0x58];
  int target;       /* 0x58 object that receives the records */
} RecordTarget;

typedef struct RecordSource {
  char pad00[0x7c];
  u8 kind;          /* 0x7c */
} RecordSource;

/* Size in bytes of one record of the array. */
#define RECORD_STRIDE 0x10

/* The source kind that sets the flag passed on with each record. */
#define SOURCE_KIND_FLAGGED 2

extern void FUN_0005743c();
extern void FUN_00194438();

/* After FUN_00194438 reports success, hand each of the count records to the target object. */
void FUN_0019487c(RecordTarget *owner,RecordSource *source,int records,int count,u32 arg5,int useKind)
{
  bool flagged;
  int target;
  int i;
  u8 ok;
  
  ok = '\0';
  FUN_00194438(&ok,owner,source,arg5,useKind);
  if (ok != '\0') {
    flagged = false;
    if (useKind != 0) {
      flagged = source->kind == SOURCE_KIND_FLAGGED;
    }
    if (((records != 0) && (target = owner->target, target != 0)) &&
       (i = 0, 0 < count)) {
      do {
        FUN_0005743c(target,i,records,flagged);
        i = i + 1;
        records = records + RECORD_STRIDE;
      } while (i < count);
    }
  }
}
