/* HSTMATCH module=hstp_trans_main.prx start=0x001f53dc end=0x001f5444 symbol=FUN_001f53dc lang=c99 */
/* Clone of src/eboot/FUN_001e71c4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00108f54();
extern void FUN_001f08e8();
extern void FUN_001f5444();

void FUN_001f53dc(int param_1,int param_2,int param_3,int param_4)
{
  FUN_001f08e8(param_1);
  FUN_00108f54(*(int *)(param_1 + 0x810),0);
  FUN_001f5444(param_1,param_2,param_3,param_4);
}
