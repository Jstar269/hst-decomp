/* HSTMATCH module=EBOOT.BIN start=0x00210134 end=0x00210164 symbol=FUN_00210134 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

extern float DAT_00341174;
extern float DAT_0034117c;

float FUN_00210134(float param_1)
{
  return DAT_00341174 * 0.01f + DAT_0034117c * 0.01f * param_1;
}
