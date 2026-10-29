/* HSTMATCH module=EBOOT.BIN start=0x002b0704 end=0x002b07c4 symbol=FUN_002b0704 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Near-miss wip (lane u5cr1-2, unreviewed) corrected by hand: Ghidra dropped FUN_0010b6d4's third argument, which is the already computed iVar5 - 1 held in a2; exact match verified; names and types await human review. */
#include "hst/types.h"

#define CHANNEL_COUNT 10
#define STEP_COUNT 6

/* Owner of CHANNEL_COUNT per-channel tables; `channel` selects the active one. */
typedef struct ChannelOwner {
  char pad0[0x94];
  int channel;                 /* 0x94 */
  char pad98[0x110 - 0x98];
  int limit[CHANNEL_COUNT];    /* 0x110 */
  char pad138[0x384 - 0x138];
  char *sub;                   /* 0x384 */
  char pad388[0x3a8 - 0x388];
  int saved[CHANNEL_COUNT];    /* 0x3a8 */
  int start[CHANNEL_COUNT];    /* 0x3d0 */
  int level;                   /* 0x3f8 */
} ChannelOwner;

extern void FUN_0010b6d4(void *, int, int);
extern void FUN_0010b8cc();

/* Counts how many of the STEP_COUNT thresholds above the channel's start index are below its limit, updates level, refreshes the sub-object. */
void FUN_002b0704(ChannelOwner *self,u32 arg)
{
  int ch;
  int *limitp;
  int i;
  int idx;
  int count;
  int current;
  int expected;
  
  ch = self->channel;
  limitp = &self->limit[ch];
  count = 0;
  i = 0;
  idx = self->start[ch] << 1;
  do {
    if (idx < *limitp) {
      count = count + 1;
    }
    i = i + 1;
    idx = idx + 1;
  } while (i < STEP_COUNT);
  current = self->level;
  expected = count - 1;
  if (current != expected) {
    FUN_0010b6d4(self->sub,0,expected);
    self->level = count + -1;
  }
  FUN_0010b8cc(self->sub,arg,0);
  self->saved[self->channel] = *(int *)(self->sub + 0xdc);
}
