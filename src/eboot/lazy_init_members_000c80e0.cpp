/* HSTMATCH module=EBOOT.BIN start=0x000c80e0 end=0x000c8178 symbol=FUN_000c80e0 lang=c++ */
/* Clone of src/sharing_main/lazy_init_members_000cbc80.cpp (hstclone.py tag s10170158a2r1e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2/v0c) corrected by hand: struct with the three member pointers and new-then-construct as `mem = alloc(); if (mem) mem = ctor(mem); m = mem;`; exact match verified; names and types await human review. */
extern "C" {
void *FUN_00000bcc(unsigned);
void *FUN_000d3204(void *);
void *FUN_000d4288(void *);
void *FUN_000d4cd4(void *);
}

struct Self {
  char pad00[0x50];
  void *m50;
  void *m54;
  void *m58;
};

extern "C" int FUN_000c80e0(Self *self)
{
  if (self->m50 == 0) {
    void *mem = FUN_00000bcc(0x7b0);
    if (mem) mem = FUN_000d3204(mem);
    self->m50 = mem;
  }
  if (self->m54 == 0) {
    void *mem = FUN_00000bcc(0x54);
    if (mem) mem = FUN_000d4288(mem);
    self->m54 = mem;
  }
  if (self->m58 == 0) {
    void *mem = FUN_00000bcc(0x720);
    if (mem) mem = FUN_000d4cd4(mem);
    self->m58 = mem;
  }
  return 1;
}
