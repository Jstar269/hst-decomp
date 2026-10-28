/* HSTMATCH module=hstp_trans_main.prx start=0x001d01ac end=0x001d020c symbol=FUN_001d01ac lang=c99 */
/* Clone of src/eboot/FUN_001c1f98.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern int FUN_00000788();
extern void FUN_00000a00();
extern void FUN_0008e7c8();

int FUN_001d01ac(int param_1,short param_2)
{
  if ((param_1 != 0) && (FUN_00000788(param_1 + 0x18,FUN_0008e7c8,0x120,4), 0 < param_2)) {
    FUN_00000a00(param_1);
  }
  return param_1;
}
