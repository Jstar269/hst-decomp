/* HSTMATCH module=hstp_trans_main.prx start=0x001dc444 end=0x001dc484 symbol=FUN_001dc444 lang=c++ */
/* Clone of src/eboot/clamp_001cdd68.cpp (hstclone.py tag u6cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

static inline float Clamp_001dc444(const float &value, const float &low, const float &high)
{
  return value < low ? low : (!(value > high) ? value : high);
}

extern "C" float FUN_001dc444(float *param_1,float *param_2,float *param_3)
{
  return Clamp_001dc444(*param_1, *param_2, *param_3);
}
