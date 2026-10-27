/* HSTMATCH module=hstp_trans_main.prx start=0x002a1d14 end=0x002a2024 symbol=FUN_002a1d14 lang=c++ helpers=FUN_002a130c@0x002a130c-0x002a1338 */
/* Clone of src/eboot/init_stages_002905bc.cpp (hstclone.py tag a0db26h2): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Sub { char pad[0x14]; int handle; char pad18[4]; } Sub;

typedef struct Obj {
  char pad0[0x10];
  int f10;
  int f14;
  int f18;
  int f1c;
  int f20;
  int f24;
  unsigned char f28;
  unsigned char f29;
  char pad2a[6];
  int f30;
  char pad34[0x50 - 0x34];
  Sub s50;
  Sub s6c;
  char pad88[0xec - 0x88];
  char fec[4];
} Obj;

extern "C" {
extern unsigned char DAT_003f3b3c;
extern char DAT_003a84cc;
extern char DAT_003a84d8;
extern char DAT_002db1f0[];
extern char DAT_003a8334[];
extern char DAT_003a8440[];
extern char DAT_003a84e4[];
extern char DAT_003a8500[];
extern char DAT_003a852c[];
extern char DAT_003a8550[];
extern char DAT_003a8568[];
extern char DAT_003a8584[];
extern char DAT_003a859c[];
extern char DAT_003a85c4[];
extern void FUN_000149a8(void *);
static void FUN_002a130c(...) { }
extern void FUN_002a2e74(Sub *);
extern unsigned char FUN_002a2ff0(Sub *, const char *, void *, void *, int, int, int);
extern void FUN_002c76f8(int);
extern int FUN_002c7730(void);
extern int FUN_002c7748(int);
extern int FUN_002c7c30(Obj *, int);
extern int FUN_002c7c38(Obj *, int *, int);
extern int FUN_002c7c58(Obj *);
extern int FUN_002c7c60(Obj *);
}

extern "C" int FUN_002a1d14(Obj *o, int p2, int p3, int p4)
{
  int r;
  if (o->f28 == 0) {
    FUN_002a130c(DAT_003a8440, p2);
    return 0;
  }
  FUN_000149a8(o->fec);
  o->f30 = p3;
  for (;;) {
    if (!(DAT_003f3b3c == 0 && (r = FUN_002c7c60(o)) >= 0 && r != 1)) {
      break;
    }
    FUN_002c76f8(1000);
  }
  if (DAT_003f3b3c != 0) {
    FUN_002a130c(DAT_003a84e4);
  } else {
    r = FUN_002c7c30(o, p2);
    if (r != 0) {
      FUN_002a130c(DAT_003a8500, r);
    } else {
      for (;;) {
        if (!(DAT_003f3b3c == 0 && (r = FUN_002c7c60(o)) != 2 && r != 4 && r != 0x200 && r >= 0)) {
          break;
        }
        FUN_002a130c(DAT_003a852c);
        FUN_002c76f8(1000);
      }
      if (DAT_003f3b3c != 0) {
        FUN_002a130c(DAT_003a84e4);
      } else {
        int k = FUN_002c7730();
        if (FUN_002a2ff0(&o->s50, DAT_003a8550, o, &DAT_003a84cc, k + 1, 0x1000, 0x4000) == 0) {
          FUN_002a130c(DAT_003a8568);
        } else {
          if (FUN_002a2ff0(&o->s6c, DAT_003a8584, o, &DAT_003a84d8, 16, 0x1000, 0) == 0) {
            FUN_002a130c(DAT_003a8568);
          } else {
            o->f10 = 0;
            o->f14 = 0;
            o->f18 = 1;
            o->f1c = 0;
            o->f20 = 0;
            o->f24 = 1;
            r = FUN_002c7c38(o, &o->f10, p4);
            if (r != 0) {
              FUN_002a130c(DAT_003a859c, r);
            } else {
              FUN_002a2e74(&o->s50);
              FUN_002a2e74(&o->s6c);
              o->f29 = 1;
              FUN_002a130c(DAT_003a85c4, p2);
              return 1;
            }
            if (o->s6c.handle >= 0) {
              r = FUN_002c7748(o->s6c.handle);
              if (r != 0) {
                FUN_002a130c(DAT_002db1f0, r);
              }
              o->s6c.handle = -1;
            }
          }
          if (o->s50.handle >= 0) {
            r = FUN_002c7748(o->s50.handle);
            if (r != 0) {
              FUN_002a130c(DAT_002db1f0, r);
            }
            o->s50.handle = -1;
          }
        }
      }
      r = FUN_002c7c58(o);
      if (r != 0) {
        FUN_002a130c(DAT_003a8334, r);
      }
    }
  }
  return 0;
}

// second pass (sn6): 4 words left (was 8). The prologue copy-order group is FIXED: Ghidra's `FUN_002a130c(DAT_003a8440)` in the early-failure arm passes the INCOMING a1 (p2) unchanged, i.e. it is
//  `FUN_002a130c(DAT_003a8440, p2)`; using a1 directly before its copy moves `move s1,a1` to the end (the bnez delay slot). Remaining: success arm `lui a0; li v0,1; move a1,s1; addiu a0; jal; sb v0,41(s2)` (sb in the jal slot)
//  vs ours `li v0,1; lui a0; move a1,s1; sb; jal; addiu a0`. Tried again on top of the fix: comma expressions in either argument, `int t = p2; o->f29 = 1; return F(fmt, t)`, a `char *fmt` local.
// improved by lane sn6 (unreviewed): 8 -> 4 differing words
