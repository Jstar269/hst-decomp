/* HSTMATCH module=EBOOT.BIN start=0x0029a9a0 end=0x0029aa6c symbol=FUN_0029a9a0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: preserve the allocation result and assign the initialized result through one shared field store; exact match verified; names and types await human review. */
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

extern int FUN_00000bcc();
extern undefined4 * FUN_000ff4fc();

undefined1 * FUN_0029a9a0(undefined1 *param_1)
{
  int iVar1;
  undefined4 uVar2;
  
  *param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x10) = 0;
  param_1[0x14] = 1;
  param_1[0x15] = 1;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x7420) = 0;
  *(undefined4 *)(param_1 + 0xe424) = 0;
  *(undefined4 *)(param_1 + 0x15828) = 0;
  *(undefined4 *)(param_1 + 0x1582c) = 0;
  *(undefined4 *)(param_1 + 0x15830) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x15834) = 0;
  *(undefined4 *)(param_1 + 0x15838) = 0;
  iVar1 = FUN_00000bcc(0x14);
  uVar2 = iVar1;
  if (iVar1 != 0)
    uVar2 = (unsigned int)(FUN_000ff4fc(iVar1,0x40000));
  *(undefined4 *)(param_1 + 0x1c) = uVar2;
  return param_1;
}
