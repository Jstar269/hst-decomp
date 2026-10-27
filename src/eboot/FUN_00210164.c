/* HSTMATCH module=EBOOT.BIN start=0x00210164 end=0x002101cc symbol=FUN_00210164 lang=c99 */
/* Hand-written reconstruction (port of src/sharing_main/FUN_0021eda0.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
extern float DAT_00341174;
extern float DAT_0034117c;

inline float FUN_00210134(float t)
{
  return DAT_00341174 * 0.01f + DAT_0034117c * 0.01f * t;
}

float FUN_00210164(float x)
{
  if (x > DAT_00341174 * 0.01f) {
    return FUN_00210134(-1.0f);
  }
  return FUN_00210134(1.0f);
}
