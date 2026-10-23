/* HSTMATCH module=EBOOT.BIN start=0x0029ab94 end=0x0029acec symbol=FUN_0029ab94 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct RefObj {
  virtual void Release(int);
  virtual void Slot0();
};

extern "C" void FUN_002b7960(int, int);
extern "C" void FUN_000c06f0(RefObj *);
extern "C" int FUN_002b7dc0(void);
extern "C" void FUN_002b7738(int);
extern "C" void FUN_0029a584(const char *fmt, ...);
extern "C" void FUN_000ba78c(RefObj *);
extern "C" void FUN_00000a00(char *);
extern "C" char DAT_002cb8bc[];
extern "C" char DAT_002cb8d0[];
extern "C" char DAT_002cb8f4[];
extern "C" RefObj *DAT_00338ac4;

extern "C" char *FUN_0029ab94(char *param_1,short param_2)
{
  RefObj *p;
  int r;

  if (param_1 != 0) {
    FUN_002b7960(0,0x26);
    if (*(RefObj **)(param_1 + 8) != 0) {
      FUN_000c06f0(*(RefObj **)(param_1 + 8));
    }
    p = *(RefObj **)(param_1 + 8);
    if (p != 0) {
      if (p != 0) {
        p->Release(1);
      }
      *(int *)(param_1 + 8) = 0;
    }
    r = *(int *)(param_1 + 0xc);
    if (r >= 0) {
      FUN_002b7738(r);
      *(int *)(param_1 + 0xc) = -1;
    }
    if (*(unsigned char *)param_1 != 0) {
      *(unsigned char *)param_1 = 0;
      r = FUN_002b7dc0();
      if (r < 0) {
        FUN_0029a584(DAT_002cb8f4,r);
      } else {
        FUN_0029a584(DAT_002cb8d0);
      }
      FUN_000ba78c(DAT_00338ac4);
    }
    if (DAT_00338ac4 != 0) {
      if (DAT_00338ac4 != 0) {
        DAT_00338ac4->Release(1);
      }
      DAT_00338ac4 = 0;
    }
    FUN_0029a584(DAT_002cb8bc);
    p = *(RefObj **)(param_1 + 0x1c);
    if (p != 0) {
      if (p != 0) {
        p->Release(1);
      }
      *(int *)(param_1 + 0x1c) = 0;
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
