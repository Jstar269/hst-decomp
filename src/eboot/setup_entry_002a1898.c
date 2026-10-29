/* HSTMATCH module=EBOOT.BIN start=0x002a1898 end=0x002a1a4c symbol=FUN_002a1898 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed struct views and prototypes (the float-argument calls FUN_00057bc0/FUN_00057b58/FUN_00058ec4 and the float-returning clamp); readability pass; exact match verified; names and types await human review. */
#include "hst/anim_host.h"

/* Setup request: entry id, animation state and mode. */
typedef struct EntryArgs {
  int id;      /* 0x00 */
  int state;   /* 0x04 */
  int mode;    /* 0x08 */
} EntryArgs;

extern float DAT_00300658;
extern float DAT_0030066c;
extern float DAT_00300670;
extern float DAT_00300674;
extern float DAT_00300678;
extern void FUN_00057b58(AnimHost *, int, int, float);
extern void FUN_00057bc0(AnimHost *, int, int, float, float, float);
extern void FUN_00058ddc(AnimHost *, int, int);
extern void FUN_00058ec4(AnimHost *, int, float);
extern void FUN_00059084(AnimHost *, int);
extern void FUN_00103480(EntryData *);
extern void FUN_00114fb8(int);
extern float FUN_001cdd68(float *, float *, float *); /* clamp: value, low, high */
extern EntryPart *FUN_001d1f80(EntryData *, int);
extern void FUN_001d2124(EntryPart *);
extern void FUN_001d61e4(int);
extern void FUN_002a0b84(EntryData *, int);
extern void FUN_002a1398(AnimHost *, int, int);
extern void FUN_002a165c(AnimHost *, int);
extern void FUN_002a1a4c(EntryBlock *, int);

/* Loads an entry into the host: resets its data, clamps the two part values, then starts its animation state. */
void FUN_002a1898(AnimHost *host, EntryArgs *args, unsigned char flag)
{
  EntryData *entry;
  int id;
  int state;
  float clamped;
  float shifted0;
  float shifted1;

  id = args->id;
  entry = host->entry;
  FUN_002a0b84(entry, 1);
  FUN_002a1a4c(&entry->block, id);
  FUN_001d2124(entry->part);
  FUN_001d61e4(entry->unk68);
  FUN_00114fb8(entry->unk6c);
  entry->unk70 = flag;
  shifted0 = DAT_00300658 + FUN_001d1f80(entry, 0)->unk78;
  clamped = FUN_001cdd68(&shifted0, &DAT_0030066c, &DAT_00300670);
  FUN_001d1f80(entry, 0)->unk78 = clamped;
  shifted1 = entry->part->unk78 + DAT_00300658;
  clamped = FUN_001cdd68(&shifted1, &DAT_00300674, &DAT_00300678);
  entry->part->unk78 = clamped;
  FUN_00103480(entry);
  host->flag_a = 1;
  FUN_002a165c(host, args->mode);
  state = args->state;
  host->state = state;
  if (state == HOST_STATE_SPECIAL) {
    FUN_00057bc0(host, 1, -1, 0.0f, 0.0f, 0.0f);
    FUN_00057b58(host, 1, state, 0.0f);
  } else {
    FUN_002a1398(host, 1, state);
  }
  FUN_00058ddc(host, 1, 1);
  FUN_00058ec4(host, 1, 1.0f);
  FUN_00059084(host, 1);
}
