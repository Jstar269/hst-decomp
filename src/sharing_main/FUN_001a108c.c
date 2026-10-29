/* HSTMATCH module=hstp_trans_main.prx start=0x001a108c end=0x001a115c symbol=FUN_001a108c lang=c99 */
/* Clone of src/eboot/FUN_0019487c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00058090();
extern void FUN_001a0c48();

/* After FUN_001a0c48 reports success, hand each of the count records to the target object. */
void FUN_001a108c(RecordTarget *owner,RecordSource *source,int records,int count,u32 arg5,int useKind)
{
  bool flagged;
  int target;
  int i;
  u8 ok;
  
  ok = '\0';
  FUN_001a0c48(&ok,owner,source,arg5,useKind);
  if (ok != '\0') {
    flagged = false;
    if (useKind != 0) {
      flagged = source->kind == SOURCE_KIND_FLAGGED;
    }
    if (((records != 0) && (target = owner->target, target != 0)) &&
       (i = 0, 0 < count)) {
      do {
        FUN_00058090(target,i,records,flagged);
        i = i + 1;
        records = records + RECORD_STRIDE;
      } while (i < count);
    }
  }
}
