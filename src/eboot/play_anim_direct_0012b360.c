/* HSTMATCH module=EBOOT.BIN start=0x0012b360 end=0x0012b3d4 symbol=FUN_0012b360 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned int undefined4;
extern int DAT_0033b538;
extern void FUN_0012ad54(int,int,int,int,int,int,float);
extern int FUN_0012b72c(int,undefined4,int);

void FUN_0012b360(int param_1,int param_2)
{
  int index = FUN_0012b72c(param_1,*(undefined4 *)(param_1 + 0x35c),4);
  if (index != 0) {
    index = index + *(int *)(param_1 + 0x354);
  }
  FUN_0012ad54(param_1,DAT_0033b538 + index,1,0,param_2,1,-1.0f);
}
