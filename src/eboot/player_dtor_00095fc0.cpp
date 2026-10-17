/* HSTMATCH module=EBOOT.BIN start=0x00095fc0 end=0x00096128 symbol=FUN_00095fc0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
extern char DAT_0030729c;
extern struct VC_2 *DAT_0034b340[];
extern void FUN_00000a00(void *);
extern int FUN_0001dce4(void *, int);
extern void *FUN_0001f0f0(void *, int);
extern void *FUN_000510c0(void *, int);
extern void *FUN_00056cb0(void *, int);
extern void FUN_0009265c(void *, int);
extern void FUN_00098870(void *);
extern void *FUN_000b42f8(void *, int);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct VC_2 { virtual ~VC_2(); };

struct Player {
  void *vptr;
  char pad4[0x80 - 4];
  char m80[0x148 - 0x80];
  int idx;
  char pad14c[0x5bc - 0x14c];
  VC_1 *m5bc;
  char m5c0[0x10];
  char m5d0[0x780 - 0x5d0];
  VC_0 *m780;
  char pad784[4];
  char m788[8];
};

extern "C" Player *FUN_00095fc0(Player *self, short flag)
{
  if (self != 0) {
    self->vptr = &DAT_0030729c;
    if (self->m780 != 0) {
      delete self->m780;
      self->m780 = 0;
    }
    FUN_00098870(self);
    FUN_0009265c(self->m5bc, 1);
    VC_2 *q = DAT_0034b340[self->idx];
    if (q != 0) {
      if (q != 0) {
        delete q;
        DAT_0034b340[self->idx] = 0;
      }
      self->m5bc = 0;
    } else {
      VC_1 *p = self->m5bc;
      if (p != 0) {
        delete p;
        self->m5bc = 0;
      }
    }
    FUN_000510c0(self->m788, -1);
    FUN_00056cb0(self->m5d0, -1);
    if (self->m5c0 != 0) {
      if (self->m5c0 != 0)
        FUN_000b42f8(self->m5c0, 0);
    }
    FUN_0001dce4(self->m80, -1);
    FUN_0001f0f0(self, 0);
    if (0 < flag)
      FUN_00000a00(self);
  }
  return self;
}
