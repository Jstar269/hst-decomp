/* HSTMATCH module=EBOOT.BIN start=0x001cdd14 end=0x001cdd68 symbol=FUN_001cdd14 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

struct ResultMethods {
  virtual ~ResultMethods();
  virtual int F0();
  virtual int F1();
  virtual int F2();
  virtual int F3();
  virtual int F4();
  virtual int F5();
  virtual int F6();
  virtual int F7();
  virtual int F8();
  virtual int F9();
  virtual int F10();
};

extern "C" bool FUN_001cdd14(ResultMethods *param_1)
{
  int iVar2;
  bool bVar1;

  iVar2 = param_1->F10();
  bVar1 = iVar2 == 2;
  if (!bVar1) {
    iVar2 = param_1->F10();
    bVar1 = iVar2 == 3;
  }
  return bVar1;
}
