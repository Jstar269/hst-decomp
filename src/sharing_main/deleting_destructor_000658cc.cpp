/* HSTMATCH module=hstp_trans_main.prx start=0x000658cc end=0x0006594c symbol=FUN_000658cc lang=c++ */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: expressed virtual slot +0x0c dispatch through V4; exact match verified; names and types await human review. */

extern unsigned char DAT_003b0398;
extern "C" void FUN_00000a00(void *);
extern "C" void *FUN_000673f4(void *, int);

struct V4
{
  virtual void Slot0();
  virtual void Slot1();
  virtual void Slot2();
};

extern "C" int * FUN_000658cc(int *param_1, short param_2)
{
  if (param_1 != 0) {
    *param_1 = (int)&DAT_003b0398;
    ((V4 *)param_1)->Slot1();
    int *piVar1 = param_1 + 1;
    if (piVar1 != 0 && piVar1 != 0) {
      FUN_000673f4(piVar1, 0);
    }
    if (param_2 > 0) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
