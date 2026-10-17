/* HSTMATCH module=EBOOT.BIN start=0x00055724 end=0x00055768 symbol=FUN_00055724 lang=c99 */
/* Clone of src/sharing_main/FUN_000562d0.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00054358();
extern void FUN_000555b4();

void FUN_00055724(undefined4 param_1,int param_2)
{
  undefined4 uVar1;
  undefined1 auStack_40 [64];
  
  uVar1 = *(undefined4 *)(param_2 + 0x8c);
  FUN_000555b4(auStack_40);
  FUN_00054358(param_1,uVar1,auStack_40);
  return;
}
