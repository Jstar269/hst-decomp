/* HSTMATCH module=hstp_trans_main.prx start=0x001367cc end=0x00136840 symbol=FUN_001367cc lang=c99 */
/* Clone of src/eboot/play_anim_direct_0012b360.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned int undefined4;
extern int DAT_003e4878;
extern void FUN_001361c0(int,int,int,int,int,int,float);
extern int FUN_00136b98(int,undefined4,int);

void FUN_001367cc(int param_1,int param_2)
{
  int index = FUN_00136b98(param_1,*(undefined4 *)(param_1 + 0x35c),4);
  if (index != 0) {
    index = index + *(int *)(param_1 + 0x354);
  }
  FUN_001361c0(param_1,DAT_003e4878 + index,1,0,param_2,1,-1.0f);
}
