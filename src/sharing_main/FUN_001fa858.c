/* HSTMATCH module=hstp_trans_main.prx start=0x001fa858 end=0x001fa8a4 symbol=FUN_001fa858 lang=c99 */
/* Clone of src/eboot/FUN_001ec518.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_001f6b08();
extern void FUN_001f9c3c();

void FUN_001fa858(int *param_1,int param_2)
{
  if (*param_1 != 0) {
    FUN_001f9c3c(*param_1);
    FUN_001f6b08(*(int *)param_1[2],param_2);
  }
}
