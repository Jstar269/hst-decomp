/* HSTMATCH module=hstp_trans_main.prx start=0x001e1f70 end=0x001e1fa4 symbol=FUN_001e1f70 lang=c99 */
/* Clone of src/eboot/FUN_001d416c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

/* Linear interpolation between two ints by t (0.0 gives from, 1.0 gives to), truncated. */
int FUN_001e1f70(float t,int from,int to)
{
  return (int)((1.0f - t) * (float)from + t * (float)to);
}
