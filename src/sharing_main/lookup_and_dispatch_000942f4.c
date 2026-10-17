/* HSTMATCH module=hstp_trans_main.prx start=0x000942f4 end=0x000943b8 symbol=FUN_000942f4 lang=c99 */
/* Clone of src/eboot/lookup_and_dispatch_0009265c.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v21) corrected by hand: typed the string lookup and dispatch prototypes, used the null-result ternary, and expressed the final negative exit; exact match verified; names and types await human review. */
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

extern char DAT_00378b4c[];
extern char DAT_00378b68[];
extern int FUN_0002fea8(int param_1,char *param_2);
extern void FUN_00054fb0(int param_1,int param_2,int param_3,int param_4,int param_5);

void FUN_000942f4(int param_1,int param_2)
{
  int iVar1;
  
  if ((*(int *)(param_1 + 100) != 0) &&
     (iVar1 = *(int *)(*(int *)(param_1 + 100) + 0x8c), iVar1 != 0)) {
    iVar1 = *(int *)(iVar1 + 8);
    iVar1 = iVar1 != 0 ? FUN_0002fea8(iVar1,DAT_00378b4c) : -1;
    if (iVar1 >= 0) {
      FUN_00054fb0(*(int *)(*(int *)(param_1 + 100) + 0x8c),-1,iVar1,(param_2 != 0) ^ 1,0);
    }
    iVar1 = *(int *)(param_1 + 100);
    iVar1 = *(int *)(*(int *)(iVar1 + 0x8c) + 8);
    iVar1 = iVar1 != 0 ? FUN_0002fea8(iVar1,DAT_00378b68) : -1;
    if (iVar1 < 0) goto done;
    FUN_00054fb0(*(int *)(*(int *)(param_1 + 100) + 0x8c),-1,iVar1,param_2,0);
  }
done:
  return;
}
