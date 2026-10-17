/* HSTMATCH module=hstp_trans_main.prx start=0x002355a4 end=0x00235654 symbol=FUN_002355a4 lang=c99 */
/* Clone of src/eboot/record_update_00226030.c (hstclone.py tag u5cr3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: ordered saved locals and moved the empty-range exit ahead of cursor initialization; exact match verified; names and types await human review. */
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

extern void FUN_00108f54();
extern void FUN_00111908();
extern void FUN_00111944();
extern void FUN_00233cac();

void FUN_002355a4(int param_1)
{
  int iVar3;
  int iVar2;
  int iVar1;
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x3c) + 0x24);
  FUN_00111908(*(undefined4 *)(iVar3 + 0x8c));
  *(undefined4 *)(iVar3 + 0x90) = 0;
  *(undefined1 *)(iVar3 + 0x118) = 0;
  iVar2 = 0;
  if (*(int *)(iVar3 + 0x94) <= 0) goto done;
  iVar1 = iVar3;
  do {
    FUN_00111944(*(undefined4 *)(iVar3 + 0x8c),(int)*(float *)(iVar1 + 0x98),
                 (int)*(float *)(iVar1 + 0xd8),0,0,1);
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 4;
  } while (iVar2 < *(int *)(iVar3 + 0x94));
done:
  FUN_00108f54(iVar3,0);
  *(undefined1 *)(iVar3 + 0x54) = 0;
  FUN_00233cac(iVar3,*(undefined4 *)(iVar3 + 0x90));
  return;
}
