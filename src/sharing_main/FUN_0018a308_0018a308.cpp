/* HSTMATCH module=hstp_trans_main.prx start=0x0018a308 end=0x0018a380 symbol=FUN_0018a308 lang=c++ */
/* Clone of src/eboot/FUN_0017dc14_0017dc14.cpp (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: this/float argument order and clamp access; exact match verified; names and types await human review. */

extern "C" int FUN_00177ea4();

struct StateView_0018a308 { char pad[0x4c]; float value; };

static inline float Clamp(const float &value, const float &low, const float &high)
{
  return value < low ? low : (!(value > high) ? value : high);
}

static inline const float &Current(const struct StateView_0018a308 *state)
{
  return state->value;
}

extern "C" void FUN_0018a308(int param_2,float param_1)
{
  int iVar1;
  
  iVar1 = FUN_00177ea4();
  *(float *)(param_2 + 0x4c) = *(float *)(param_2 + 0x4c) + param_1;
  *(float *)(param_2 + 0x4c) = Clamp(Current((const struct StateView_0018a308 *)param_2),
                 *(float *)(iVar1 + 0x1c), *(float *)(iVar1 + 0x20));
}
