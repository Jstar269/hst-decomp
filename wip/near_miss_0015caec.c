/* HSTMATCH module=hstp_trans_main.prx start=0x0015caec end=0x0015cba4 symbol=FUN_0015caec lang=c99 */
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

extern undefined * DAT_003f344c;
extern int FUN_00157e10();
extern void FUN_001daeb8();
extern int FUN_001db8a4();
extern int FUN_001db960();

undefined4 FUN_0015caec(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 uVar2;
  int uVar3;
  uint *puVar4;
  undefined4 *puVar5;
  
  iVar1 = FUN_001db8a4(DAT_003f344c);
  if (iVar1 == 0) {
    uVar2 = *param_2;
    uVar3 = (unsigned char)FUN_001db960(DAT_003f344c);
    puVar4 = (uint *)FUN_00157e10(uVar2,*(undefined4 *)(*(int *)(param_1 + 4) + 0x10));
    *puVar4 = uVar3;
    FUN_001daeb8(DAT_003f344c,*(undefined4 *)(*(int *)(param_1 + 4) + 0xc));
    iVar1 = FUN_001db960(DAT_003f344c);
    if (iVar1 == 0) {
      puVar5 = (undefined4 *)FUN_00157e10(uVar2,0xb);
      *puVar5 = 0;
    }
    uVar2 = 1;
    *(undefined1 *)(DAT_003f344c + 0xfd) = 0;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

// Near miss: two words remain at the final DAT_003f344c load. Retail uses v0 as the lui base and v1 for the loaded pointer; this source uses v1 for both. Volatile-global and local-pointer views retained the mismatch.
// near miss from lane u6cr2-1 (unreviewed)
