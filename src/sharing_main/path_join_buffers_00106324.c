/* HSTMATCH module=hstp_trans_main.prx start=0x00106324 end=0x0010642c symbol=FUN_00106324 lang=c99 */
/* Clone of src/eboot/path_join_buffers_00100a1c.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: if/else order restored (param_4 != 0 first, then the empty-string test, null case last); exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined DAT_0037f7f4;
extern char DAT_0037f824[];
extern uint * FUN_00014788();
extern uint * FUN_000149a8();
extern int FUN_00014a58();
extern void FUN_00105fe4();

void FUN_00106324(int param_1,char *param_2,undefined4 param_3,char *param_4,undefined4 param_5)
{
  int iVar1;
  undefined1 auStack_100 [256];
  undefined1 auStack_200 [256];
  
  iVar1 = FUN_00014a58(param_3,&DAT_0037f7f4,4);
  if (iVar1 == 0) {
    param_2 = DAT_0037f824;
  }
  FUN_000149a8(auStack_100,param_2);
  FUN_00014788(auStack_100,param_3);
  if (param_4 != (char *)0x0) {
    if (*param_4 == 0) {
      FUN_00105fe4(param_1,auStack_100,param_4,param_5);
    }
    else {
      FUN_000149a8(auStack_200,param_2);
      FUN_00014788(auStack_200,param_4);
      FUN_00105fe4(param_1,auStack_100,auStack_200,param_5);
    }
  }
  else {
    FUN_00105fe4(param_1,auStack_100,0,param_5);
  }
  FUN_000149a8(param_1 + 0x59,param_3);
  return;
}
