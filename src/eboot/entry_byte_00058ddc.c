/* HSTMATCH module=EBOOT.BIN start=0x00058ddc end=0x00058e50 symbol=FUN_00058ddc lang=c99 */
/* Clone of src/sharing_main/entry_byte_00059ac0.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: scoped negative-index loop locals and formed the direct-path offset before adding the object base; exact match verified; names and types await human review. */
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


void FUN_00058ddc(int param_1,undefined1 param_2,int param_3)
{
  if (param_3 < 0) {
    int iVar2 = *(int *)(param_1 + 0x158);
    if (iVar2 <= *(int *)(param_1 + 0x15c)) {
      int iVar1 = param_1 + iVar2 * 0x34;
      do {
        *(undefined1 *)(iVar1 + 0xf8) = param_2;
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 0x34;
      } while (iVar2 <= *(int *)(param_1 + 0x15c));
    }
  }
  else {
    int offset = param_3 * 0x34;
    offset += param_1;
    *(undefined1 *)(offset + 0xf8) = param_2;
  }
  return;
}
