/* HSTMATCH module=hstp_trans_main.prx start=0x0021eda0 end=0x0021ee08 symbol=FUN_0021eda0 lang=c99 */
/* Hand-written reconstruction from the disassembly: the body is two inlined copies of the same-file neighbour FUN_0021ed70 (src/sharing_main/FUN_0021ed70.c), defined inline in front of it, which keeps the `* 1.0f` and the value-first products and puts the add in each arm; exact match verified; names and types await human review. */
extern float DAT_003ea4b4;
extern float DAT_003ea4bc;

inline float FUN_0021ed70(float t)
{
  return DAT_003ea4b4 * 0.01f + DAT_003ea4bc * 0.01f * t;
}

float FUN_0021eda0(float x)
{
  if (x > DAT_003ea4b4 * 0.01f) {
    return FUN_0021ed70(-1.0f);
  }
  return FUN_0021ed70(1.0f);
}
