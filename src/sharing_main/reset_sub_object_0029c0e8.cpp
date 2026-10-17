/* HSTMATCH module=hstp_trans_main.prx start=0x0029c0e8 end=0x0029c1a0 symbol=FUN_0029c0e8 lang=c++ */
/* Clone of src/eboot/reset_sub_object_0028a8f4.cpp (hstclone.py tag s10170158a1r2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Sub {
  char pad0[0xc0];
  unsigned char c0;
  char pad1[3];
  float c4;
  char pad2[4];
  float cc;
  float d0;
};

struct Self {
  char pad[0x74];
  Sub *sub;
};

extern "C" void FUN_000587ac(float, Sub *, int, int);
extern "C" void FUN_00059ba8(float, Sub *, int);
extern "C" void FUN_00059c1c(float, Sub *, int);
extern "C" void FUN_0005ff00(float, Sub *);
extern "C" void FUN_00059ac0(Sub *, int, int);
extern "C" void FUN_00059d68(Sub *, int);

extern "C" void FUN_0029c0e8(Self *self, int a1, int a2)
{
  FUN_000587ac(0.0f, self->sub, 0, a1);
  Sub *p = self->sub;
  FUN_00059ba8(1.0f, p, -1);
  p->c4 = 1.0f;
  p = self->sub;
  FUN_00059c1c(0.0f, p, -1);
  FUN_0005ff00(0.0f, p);
  p = self->sub;
  FUN_00059ac0(p, a2, -1);
  p->c0 = a2;
  p = self->sub;
  FUN_00059d68(p, -1);
  p->d0 = p->c4;
}
