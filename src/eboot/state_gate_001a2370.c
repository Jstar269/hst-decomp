/* HSTMATCH module=EBOOT.BIN start=0x001a2370 end=0x001a2450 symbol=FUN_001a2370 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: invert the state gates and combine the probe comparisons; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00338ac4;
extern u32 DAT_003415ac;
extern u32 DAT_0034a678;
extern void FUN_00114168();
extern void FUN_001aee54();
extern u8 * FUN_001fea10();
extern int FUN_001feec4();

#define NEXT_STATE 0x13 /* state id set when the gate opens */
#define PROBE_VALUE 0xe /* probe field value that does not open the gate by itself */

typedef struct GateObj {
  char pad00[0x44];
  u32 state;        /* 0x44 */
  char pad48[5];
  u8 blocked;       /* 0x4d */
  char pad4e[0x68 - 0x4e];
  char sub[0x23c];  /* 0x68 sub-object refreshed when the gate opens */
  u8 enabled;       /* 0x2a4 */
} GateObj;

typedef struct Flags {
  char pad00[0x178];
  u8 override;      /* 0x178 */
} Flags;

typedef struct Probe {
  char pad00[0x3ac];
  int key;          /* 0x3ac */
  char pad3b0[8];
  int kind;         /* 0x3b8 */
} Probe;

/* Returns 1 (and moves the object to its next state) when it is enabled, not blocked and the probe check passes. */
u32 FUN_001a2370(GateObj *self)
{
  bool open;
  Probe *probe;
  u32 text;
  
  open = false;
  if (self->enabled != '\0') {
    if (self->blocked == '\0') {
      if (((Flags *)DAT_00338ac4)->override != '\0') {
        open = true;
      }
      else {
        probe = (Probe *)FUN_001feec4();
        if ((probe->key != DAT_0034a678) ||
            (probe->kind != PROBE_VALUE)) {
          open = true;
        }
      }
      if (open) {
        self->state = NEXT_STATE;
        text = (unsigned int)(FUN_001fea10(0x11,0x10,2));
        FUN_00114168(DAT_003415ac,1,text,0,0);
        FUN_001aee54(self->sub,1);
        return 1;
      }
    }
  }
  return 0;
}
