/* HSTMATCH module=hstp_trans_main.prx start=0x0029c6a8 end=0x0029c74c symbol=FUN_0029c6a8 lang=c99 */
/* Clone of src/eboot/FUN_0028aeb4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern void FUN_0029cde8();
extern int * FUN_0029dec0();
extern int * FUN_0029df7c();
extern int * FUN_0029e038();

int FUN_0029c6a8(int param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != 0) {
    FUN_0029cde8();
    iVar1 = param_1 + 0x18;
    if ((iVar1 != 0) && (iVar1 != 0)) {
      FUN_0029e038(iVar1,0);
    }
    iVar1 = param_1 + 0xc;
    if ((iVar1 != 0) && (iVar1 != 0)) {
      FUN_0029df7c(iVar1,0);
    }
    if ((param_1 != 0) && (param_1 != 0)) {
      FUN_0029dec0(param_1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
