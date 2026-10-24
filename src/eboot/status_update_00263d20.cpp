/* HSTMATCH module=EBOOT.BIN start=0x00263d20 end=0x00263f8c symbol=FUN_00263d20 lang=c++ */
/* Hand-written reconstruction from the disassembly (Ghidra pseudocode ram-0x00263d20.c as a guide), from the lane fm4 near miss: the Obj0 vcall at +0x658 takes the dropped int argument 1, which shares its register (a1) with the stored literal 1; exact match verified; names and types await human review. */
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
  virtual void v1(int);
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
  ((Obj0 *)*(void **)(param_1 + 0x658))->v1(1);
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
