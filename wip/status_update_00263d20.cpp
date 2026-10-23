/* HSTMATCH module=EBOOT.BIN start=0x00263d20 end=0x00263f8c symbol=FUN_00263d20 lang=c++ */
/* Hand-written reconstruction from the disassembly (Ghidra pseudocode ram-0x00263d20.c as a guide).
// NEAR MISS: 155/155 words, 4 words differ, both in the +0x58 block (from +0x4c):
// retail `lw v0,88(s0); li a1,1; sw a1,216(v0); sb zero,276(v0)`, ours keeps the object
// pointer in v1 and the literal in v0. Tried as the source: int / void * / char * / typed-struct
// locals, `o[0x36]=1` indexing, unsigned/bool variants, the local declared at function top,
// re-dereferencing the field (gives two loads instead of one), and true/(int)true. In a
// reduced copy of the surrounding code the same statement compiles to retail's v0/a1 form,
// so the colouring is driven by something else in the full function - do not chase it
// without a new idea. Everything else in the function matches byte for byte, including
// the two-hoisted-loads `||` test (f74/f78 locals, v1/v0). */

struct Obj {
  virtual void v0();
  virtual void v1(int);
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5();
  virtual void v6();
  virtual void v7();
};

struct Obj0 {
  virtual void v0();
  virtual void v1();
};

extern "C" {
extern char *DAT_0034a7c4;
extern char *DAT_00338ac4;
extern void *DAT_003415ac;
extern char DAT_002c0e20[];
extern char DAT_002c0e1c[];
extern char DAT_002c0e18[];

void FUN_0010b6d4(void *, int, int);
int FUN_0018c9f4(int);
void FUN_00114168(void *, int, void *, int, int);
void FUN_000ffb3c(void *, int);
void FUN_00103628(void *, int);

void FUN_00263d20(int param_1)
{
  ((Obj *)*(void **)(param_1 + 0x58))->v1(*(int *)(param_1 + 0x1850) == 0);
  FUN_0010b6d4(*(void **)(param_1 + 0x58), 0,
               (*(unsigned short *)(*(int *)(param_1 + 0x69c) + 0x0e) & 3) == 0);
  int i2 = *(int *)(param_1 + 0x58);
  *(int *)(i2 + 0xd8) = 1;
  *(char *)(i2 + 0x114) = 0;
  ((Obj0 *)*(void **)(param_1 + 0x658))->v1();
  ((Obj *)*(void **)(param_1 + 0x680))->v1(1);
  int f74 = *(int *)(*(int *)(param_1 + 0x640) + 0x74);
  int f78 = *(int *)(*(int *)(param_1 + 0x640) + 0x78);
  if (f74 != 0 || f78 != 0) {
    FUN_000ffb3c(*(void **)(param_1 + 0x6e0), 0);
    FUN_000ffb3c(*(void **)(param_1 + 0x6d8), 0);
    FUN_000ffb3c(*(void **)(param_1 + 0x6dc), 0);
  }
  ((Obj *)DAT_0034a7c4)->v7();
  void *msg;
  if (*(int *)(param_1 + 0x1850) == 0) {
    int h = FUN_0018c9f4(0x11);
    if (*(int *)(h + 4) == 0) {
      msg = DAT_002c0e20;
    } else if (*(int *)(*(int *)(h + 8) + 8) < 0x11) {
      msg = DAT_002c0e1c;
    } else if (*(int *)(*(int *)(h + 0xc) + 0xc4) < 2) {
      msg = DAT_002c0e18;
    } else {
      msg = *(void **)(*(int *)(*(int *)(h + 0xc) + 0xc0) + 4);
    }
    FUN_00114168(DAT_003415ac, 0, msg, 0, 0);
  } else {
    bool ok = true;
    if (DAT_00338ac4 != 0 && *(unsigned char *)(DAT_00338ac4 + 0x178) == 0) {
      ok = false;
    }
    if (ok && *(int *)(param_1 + 0x1854) == 0 &&
        *(unsigned char *)(*(int *)(param_1 + 0x640) + 0x4d0) == 0) {
      *(unsigned char *)(*(int *)(param_1 + 0x640) + 0x4d0) = 1;
      int h = FUN_0018c9f4(0x11);
      if (*(int *)(h + 4) == 0) {
        msg = DAT_002c0e20;
      } else if (*(int *)(*(int *)(h + 8) + 8) < 0x11) {
        msg = DAT_002c0e1c;
      } else if (*(int *)(*(int *)(h + 0xc) + 0xc4) < 0xc) {
        msg = DAT_002c0e18;
      } else {
        msg = *(void **)(*(int *)(*(int *)(h + 0xc) + 0xc0) + 0x2c);
      }
      FUN_00114168(DAT_003415ac, 2, msg, 0, 0);
    } else {
      FUN_00103628(DAT_003415ac, 1);
    }
  }
  ((Obj *)*(void **)(param_1 + 0x6a0))->v1(0);
  FUN_000ffb3c(*(void **)(param_1 + 0x6a4), 0);
}
}
// near miss from lane fm4 (unreviewed)
