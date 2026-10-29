/* HSTMATCH module=EBOOT.BIN start=0x002b066c end=0x002b0704 symbol=FUN_002b066c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: added empty Tag temporary by value and float parameter for subobject configuration; readability pass; exact match verified; names and types await human review. */
#define CHANNEL_COUNT 10

struct Tag {};

/* One per-channel entry (12 bytes); only the word at +4 is read. */
struct Channel {
  char pad0[4];
  int arg;       /* 0x4 passed on to the channel setup */
  char pad8[4];
};

struct Obj {
  char pad_0[0x3c];
  char base[0x54];                /* 0x3c embedded sub-object, set up first */
  char flag90;                    /* 0x90 */
  char pad_91[7];
  Channel channels[CHANNEL_COUNT]; /* 0x98 */
  char pad_110[0x27c];
  void *sub;                      /* 0x38c optional child, configured when present */
};

extern "C" void FUN_00103628(void *, int);
extern "C" void FUN_002b3a24(void *, int, Tag);
extern "C" void FUN_00103540(void *, float);
extern "C" void FUN_001037c8(void *, int);

extern "C" void FUN_002b066c(Obj *self)
{
  FUN_00103628(&self->base, 1);
  self->flag90 = 1;
  int i = 0;
  do {
    FUN_002b3a24(&self->channels[i], self->channels[i].arg, Tag());
    i++;
  } while (i < CHANNEL_COUNT);

  if (self->sub != 0) {
    FUN_00103540(self->sub, 100000.0f);
    FUN_001037c8(self->sub, -1);
  }
}
