/* HSTMATCH module=hstp_trans_main.prx start=0x001af93c end=0x001afa1c symbol=FUN_001af93c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: typed struct fields, unsigned char flags, flag test folded into the first if, ok-branch first; exact match verified; names and types await human review. */
typedef unsigned int undefined4;

extern "C" {
extern void *FUN_0020d1e0(int, int, int);
extern void FUN_0011e940(undefined4, int, void *, int, int);
extern void FUN_001bc52c(void *, int);
extern char *FUN_0020d694();
extern undefined4 DAT_003ea8ec;
extern undefined4 DAT_003f39a8;
}

struct Global_003e1e04 { char pad[0x178]; unsigned char f178; };
extern "C" Global_003e1e04 *DAT_003e1e04;

struct Info_0020d694 { char pad[0x3ac]; undefined4 f3ac; char pad3b0[8]; int f3b8; };

struct Obj_001af93c {
  char pad00[0x44];
  int f44;
  char pad48[5];
  unsigned char f4d;
  char pad4e[0x1a];
  char sub68[0x23c];
  unsigned char f2a4;
};

extern "C" int FUN_001af93c(Obj_001af93c *self)
{
  bool ok = false;
  if (self->f2a4 != 0 && self->f4d == 0) {
    if (DAT_003e1e04->f178 != 0) {
      ok = true;
    } else {
      Info_0020d694 *info = (Info_0020d694 *)FUN_0020d694();
      if (info->f3ac == DAT_003f39a8) {
        if (info->f3b8 != 14) {
          ok = true;
        }
      } else {
        ok = true;
      }
    }
    if (ok) {
      self->f44 = 0x13;
      void *p = FUN_0020d1e0(0x11, 0x10, 2);
      FUN_0011e940(DAT_003ea8ec, 1, p, 0, 0);
      FUN_001bc52c(self->sub68, 1);
      return 1;
    }
  }
  return 0;
}
