/* HSTMATCH module=hstp_trans_main.prx start=0x000cbc80 end=0x000cbd18 symbol=FUN_000cbc80 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag sh2/v0c) corrected by hand: struct with the three member pointers and new-then-construct as `mem = alloc(); if (mem) mem = ctor(mem); m = mem;`; exact match verified; names and types await human review. */
extern "C" {
void *FUN_00000bcc(unsigned);
void *FUN_000d6e60(void *);
void *FUN_000d7f4c(void *);
void *FUN_000d89c4(void *);
}

struct Self {
  char pad00[0x50];
  void *m50;
  void *m54;
  void *m58;
};

extern "C" int FUN_000cbc80(Self *self)
{
  if (self->m50 == 0) {
    void *mem = FUN_00000bcc(0x7b0);
    if (mem) mem = FUN_000d6e60(mem);
    self->m50 = mem;
  }
  if (self->m54 == 0) {
    void *mem = FUN_00000bcc(0x54);
    if (mem) mem = FUN_000d7f4c(mem);
    self->m54 = mem;
  }
  if (self->m58 == 0) {
    void *mem = FUN_00000bcc(0x720);
    if (mem) mem = FUN_000d89c4(mem);
    self->m58 = mem;
  }
  return 1;
}
