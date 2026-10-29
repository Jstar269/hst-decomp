/* HSTMATCH module=EBOOT.BIN start=0x0001c010 end=0x0001c0fc symbol=FUN_0001c010 lang=c99 data=0x002cfc10 */
/* Ghidra pseudocode (hstgen.py tag g2) corrected by hand: removed cc=gcc171-Os (retail is MWCC), typed 60.0f float literal for FUN_00062150, reordered *(uchar *)(param_1 + 0x1009) != 0 branch first, and added callback null check; readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002cfc10-0x002cfc22) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

#define OPEN_REPEAT_COUNT 3          /* times the follow-up pair of calls runs */
#define OPEN_UNSET_LIMIT 0x7fffffff  /* value stored in the global when the source is used as is */

typedef struct Binder {
  int handle;         /* 0x00, result of the open (0 on failure) */
  char pad04[0x14];
  int unk18;          /* 0x18 */
  int unk1c;          /* 0x1c */
  char pad20[0x4024 - 0x20];
  u8 raw;             /* 0x4024, the source is used as is instead of being opened */
  char pad4025[3];
  void (*callback)(void);  /* 0x4028, called after a successful open */
} Binder;

extern u32 DAT_0030ebd0;
extern void FUN_0001b918(char *, int);
extern int FUN_0001be84(int, int, int);
extern void FUN_0001c104(Binder *);
extern int FUN_000464ec(void);
extern void FUN_00062150(float param_1);
extern void FUN_002b78f0(void);
extern void FUN_002b7a78(void);

/* Open a binder from `source` (used directly when `raw` is set), call its callback on success, and return whether it is open. */
int FUN_0001c010(Binder *binder, int source, u8 raw)
{
  int i;
  
  FUN_002b78f0();
  FUN_0001c104(binder);
  FUN_0001b918("openBinder(\"%s\")\n", source);
  binder->raw = raw;
  if (binder->raw != 0) {
    binder->handle = source;
    DAT_0030ebd0 = OPEN_UNSET_LIMIT;
  }
  else {
    binder->handle = FUN_0001be84(source, binder->unk18, binder->unk1c);
  }
  if ((binder->handle != 0) && (binder->callback != 0)) {
    binder->callback();
  }
  if (FUN_000464ec() != 0) {
    for (i = 0; i < OPEN_REPEAT_COUNT; i++) {
      FUN_00062150(60.0f);
      FUN_002b7a78();
    }
  }
  return binder->handle != 0;
}
