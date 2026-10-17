/* HSTMATCH module=hstp_trans_main.prx start=0x000980c4 end=0x0009822c symbol=FUN_000980c4 lang=c++ */
/* Clone of src/eboot/player_dtor_00095fc0.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
extern char DAT_003b0568;
extern struct VC_2 *DAT_003f468c[];
extern void FUN_00000a00(void *);
extern int FUN_0001d930(void *, int);
extern void *FUN_0001ed28(void *, int);
extern void *FUN_000519d4(void *, int);
extern void *FUN_00057904(void *, int);
extern void FUN_000942f4(void *, int);
extern void FUN_0009aa88(void *);
extern void *FUN_000b75e8(void *, int);
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

extern "C" Player *FUN_000980c4(Player *self, short flag)
{
  if (self != 0) {
    self->vptr = &DAT_003b0568;
    if (self->m780 != 0) {
      delete self->m780;
      self->m780 = 0;
    }
    FUN_0009aa88(self);
    FUN_000942f4(self->m5bc, 1);
    VC_2 *q = DAT_003f468c[self->idx];
    if (q != 0) {
      if (q != 0) {
        delete q;
        DAT_003f468c[self->idx] = 0;
      }
      self->m5bc = 0;
    } else {
      VC_1 *p = self->m5bc;
      if (p != 0) {
        delete p;
        self->m5bc = 0;
      }
    }
    FUN_000519d4(self->m788, -1);
    FUN_00057904(self->m5d0, -1);
    if (self->m5c0 != 0) {
      if (self->m5c0 != 0)
        FUN_000b75e8(self->m5c0, 0);
    }
    FUN_0001d930(self->m80, -1);
    FUN_0001ed28(self, 0);
    if (0 < flag)
      FUN_00000a00(self);
  }
  return self;
}
