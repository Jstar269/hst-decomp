/* HSTMATCH module=EBOOT.BIN start=0x002905bc end=0x002908cc symbol=FUN_002905bc lang=c99 */
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

extern unsigned char DAT_0034a80c;
extern char DAT_002ff5c0;
extern char DAT_002ff5cc;
extern char DAT_002cabbc[];
extern char DAT_002ff408[];
extern char DAT_002ff534[];
extern char DAT_002ff5d8[];
extern char DAT_002ff5f4[];
extern char DAT_002ff620[];
extern char DAT_002ff644[];
extern char DAT_002ff65c[];
extern char DAT_002ff678[];
extern char DAT_002ff690[];
extern char DAT_002ff6b8[];
extern void FUN_000149a8(void *);
extern int FUN_0028fb44(const char *, ...);
extern void FUN_00291868(Sub *);
extern unsigned char FUN_002919e4(Sub *, const char *, void *, void *, int, int, int);
extern void FUN_002b7958(int);
extern int FUN_002b7990(void);
extern int FUN_002b79a8(int);
extern int FUN_002b7eb0(Obj *, int);
extern int FUN_002b7eb8(Obj *, int *, int);
extern int FUN_002b7ed8(Obj *);
extern int FUN_002b7ee0(Obj *);

int FUN_002905bc(Obj *o, int p2, int p3, int p4)
{
  int r;
  if (o->f28 == 0) {
    FUN_0028fb44(DAT_002ff534);
    return 0;
  }
  FUN_000149a8(o->fec);
  o->f30 = p3;
  for (;;) {
    if (!(DAT_0034a80c == 0 && (r = FUN_002b7ee0(o)) >= 0 && r != 1)) {
      break;
    }
    FUN_002b7958(1000);
  }
  if (DAT_0034a80c != 0) {
    FUN_0028fb44(DAT_002ff5d8);
  } else {
    r = FUN_002b7eb0(o, p2);
    if (r != 0) {
      FUN_0028fb44(DAT_002ff5f4, r);
    } else {
      for (;;) {
        if (!(DAT_0034a80c == 0 && (r = FUN_002b7ee0(o)) != 2 && r != 4 && r != 0x200 && r >= 0)) {
          break;
        }
        FUN_0028fb44(DAT_002ff620);
        FUN_002b7958(1000);
      }
      if (DAT_0034a80c != 0) {
        FUN_0028fb44(DAT_002ff5d8);
      } else {
        int k = FUN_002b7990();
        if (FUN_002919e4(&o->s50, DAT_002ff644, o, &DAT_002ff5c0, k + 1, 0x1000, 0x4000) == 0) {
          FUN_0028fb44(DAT_002ff65c);
        } else {
          if (FUN_002919e4(&o->s6c, DAT_002ff678, o, &DAT_002ff5cc, 16, 0x1000, 0) == 0) {
            FUN_0028fb44(DAT_002ff65c);
          } else {
            o->f10 = 0;
            o->f14 = 0;
            o->f18 = 1;
            o->f1c = 0;
            o->f20 = 0;
            o->f24 = 1;
            r = FUN_002b7eb8(o, &o->f10, p4);
            if (r != 0) {
              FUN_0028fb44(DAT_002ff690, r);
            } else {
              FUN_00291868(&o->s50);
              FUN_00291868(&o->s6c);
              o->f29 = 1;
              return FUN_0028fb44(DAT_002ff6b8, p2);
            }
            if (o->s6c.handle >= 0) {
              r = FUN_002b79a8(o->s6c.handle);
              if (r != 0) {
                FUN_0028fb44(DAT_002cabbc, r);
              }
              o->s6c.handle = -1;
            }
          }
          if (o->s50.handle >= 0) {
            r = FUN_002b79a8(o->s50.handle);
            if (r != 0) {
              FUN_0028fb44(DAT_002cabbc, r);
            }
            o->s50.handle = -1;
          }
        }
      }
      r = FUN_002b7ed8(o);
      if (r != 0) {
        FUN_0028fb44(DAT_002ff408, r);
      }
    }
  }
  return 0;
}

// Near miss: 8 of 196 words differ (hstmatch/hstdiff), two groups:
//  - entry block: ours emits `move s1,a1; move s3,a2; move s0,a3` before the bnez and `move s2,a0` in its slot; retail has
//    `move s3,a2; move s0,a3; move s2,a0` and `move s1,a1` in the slot (same register assignment, only the order differs);
//  - success arm: retail schedules `lui a0; li v0,1; move a1,s1; addiu a0,a0,lo; jal; sb v0,41(s2)` (the sb in the jal slot), ours
//    `li v0,1; lui a0; move a1,s1; sb v0,41(s2); jal; addiu a0,a0,lo`.
// What matched: for(;;){if(!(cond))break;..} top-tested wait loops; the ONE nested form that keeps the Q2 failure arm as `b 0x2908ac; nop`
// (early `return 0` only for the first test; the later G test and everything after it nested as if/else); the success path in the ELSE of the
// Q4 status test (fail arm first, jumping over it to the handle-close blocks); two handle sub-objects (+0x50, +0x6c, handle at +0x14) closed with
// FUN_002b79a8(handle) (the dropped argument); the c1/c2 failure arms nested as if(c==0){Log}else{...}.
// Tried without effect on the two groups: result variable, goto, do{}while(0)+break, switch(r) forms, C vs C++ (incl. member function), inline setter or
// comma expression for the flag, local copies of p2 or the object, parameter type changes, extra use of p2 after the cleanup call.
