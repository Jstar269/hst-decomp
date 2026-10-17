/* HSTMATCH module=EBOOT.BIN start=0x00064a08 end=0x00064a88 symbol=FUN_00064a08 lang=c++ */
/* Clone of src/sharing_main/deleting_destructor_000658cc.cpp (hstclone.py tag u3r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: expressed virtual slot +0x0c dispatch through V4; exact match verified; names and types await human review. */

extern unsigned char DAT_003070cc;
extern "C" void FUN_00000a00(void *);
extern "C" void *FUN_00065fa0(void *, int);

struct V4
{
  virtual void Slot0();
  virtual void Slot1();
  virtual void Slot2();
};

extern "C" int * FUN_00064a08(int *param_1, short param_2)
{
  if (param_1 != 0) {
    *param_1 = (int)&DAT_003070cc;
    ((V4 *)param_1)->Slot1();
    int *piVar1 = param_1 + 1;
    if (piVar1 != 0 && piVar1 != 0) {
      FUN_00065fa0(piVar1, 0);
    }
    if (param_2 > 0) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
