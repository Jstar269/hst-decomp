/* HSTMATCH module=EBOOT.BIN start=0x001abd8c end=0x001abe98 symbol=FUN_001abd8c lang=c++ */
/* Clone of src/sharing_main/dispatch_val_001b93f4.cpp (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

typedef unsigned char uchar;
typedef unsigned int undefined4;

extern "C" {
void *FUN_0019d474(void);
void FUN_001ab7e0(undefined4, int, int);
void FUN_001aa9a8(undefined4, int, int);
}

extern "C" void FUN_001abd8c(undefined4 param_1, int param_2)
{
  int uVar3;
  uchar val;

  val = *(uchar *)((int)FUN_0019d474() + 0x11c);
  switch (val) {
  case 0:
  case 4:
    int ok = 1;
    uVar3 = 0;
    int a2 = param_2;
    if (param_2 == 0) {
      a2 = param_2;
    }
    else if (param_2 == 2) {
      a2 = 3;
      uVar3 = 10;
    }
    else {
      ok = 0;
    }
    if (!ok) return;
    FUN_001ab7e0(param_1, param_2, a2);
    FUN_001aa9a8(param_1, param_2, uVar3);
    return;
  default:
    uVar3 = 0;
    if (param_2 == 0) {
      uVar3 = 20;
    }
    else if (param_2 == 1) {
      uVar3 = 30;
    }
    else if (param_2 == 2) {
      uVar3 = 40;
    }
    else if (param_2 == 3) {
      uVar3 = 50;
    }
    FUN_001ab7e0(param_1, param_2, param_2);
    FUN_001aa9a8(param_1, param_2, uVar3);
    break;
  }
}
