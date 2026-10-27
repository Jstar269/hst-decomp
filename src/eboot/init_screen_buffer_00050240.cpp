/* HSTMATCH module=EBOOT.BIN start=0x00050240 end=0x00050370 symbol=FUN_00050240 lang=c++ data=0x002d0e7c */
/* Clone of src/sharing_main/init_screen_buffer_00050b1c.cpp (hstclone.py tag s10170158a2r1e): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d0e7c-0x002d0e8f) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag sh2/v0c) corrected by hand: typed owner struct with the mode byte and object pointer past 0x1a000 (lui/addu access), new-then-construct as `mem = alloc(); if (mem) mem = ctor(mem);`, flipped ternary polarity; exact match verified; names and types await human review. */
struct Obj {
  char pad00[0x22];
  unsigned char b22;
};

struct Self {
  char pad00[0x1a0a0];
  unsigned char mode;
  Obj *obj;
};

extern "C" {
void *FUN_00000bcc(unsigned);
void *FUN_000114c0(void *, int, unsigned);
void *FUN_0004e780(void **, void **, int, int, int, int);
void FUN_00050370(Self *);
Obj *FUN_00050fc0(void *);
void FUN_00051274(Obj *, char *, void *, int, int);
}

extern "C" void FUN_00050240(Self *self, int arg, unsigned flag)
{
  if (self->obj == 0 || self->mode != (flag & 0xff)) {
    FUN_00050370(self);
    self->mode = flag;
    void *mem = FUN_00000bcc(0x48);
    if (mem) mem = FUN_00050fc0(mem);
    self->obj = (Obj *)mem;
    void *buf = 0;
    void *aux = 0;
    void *surf = FUN_0004e780(&buf, &aux, flag != 0 ? 1 : 3, 0, 0x1e0, 0x110);
    int n = self->mode != 0 ? 2 : 4;
    FUN_000114c0(buf, 0, n * 0x1fe00);
    FUN_00051274(self->obj, "FrameBufferTexture", surf, arg, 0x10);
    self->obj->b22 = 0;
  }
}
