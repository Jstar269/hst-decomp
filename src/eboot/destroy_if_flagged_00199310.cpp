/* HSTMATCH module=EBOOT.BIN start=0x00199310 end=0x00199398 symbol=FUN_00199310 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
extern int DAT_00309194[];
extern char DAT_00341771;
extern int FUN_002b7cd0(void *);
extern void FUN_002b7c30();
extern void FUN_0001f0f0(void *, int);
extern void FUN_00000a00(void *);
}

extern "C" void *FUN_00199310(void *param_1, short param_2)
{
  if (param_1 != 0) {
    *(void **)param_1 = DAT_00309194;
    switch (FUN_002b7cd0(param_1)) {
    case 3:
      FUN_002b7c30();
      break;
    }
    DAT_00341771 = 0;
    FUN_0001f0f0(param_1, 0);
    if (0 < (int)param_2)
      FUN_00000a00(param_1);
  }
  return param_1;
}
