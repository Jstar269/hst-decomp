/* HSTMATCH module=EBOOT.BIN start=0x00067498 end=0x00067500 symbol=FUN_00067498 lang=c99 */
/* Clone of src/sharing_main/FUN_000688ec.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_0030716c;
extern undefined4 * FUN_0001f06c();
extern void FUN_0006792c();
extern undefined4 * FUN_00067b28();

undefined4 * FUN_00067498(undefined4 *param_1)
{
  undefined1 auStack_4 [4];
  undefined4 local_8;
  undefined4 *local_c;
  
  FUN_0001f06c();
  *param_1 = (unsigned int)(&DAT_0030716c);
  FUN_00067b28(param_1 + 0xf);
  local_c = param_1 + 0x10;
  local_8 = param_1[0x11];
  FUN_0006792c(auStack_4,param_1 + 0xf,&local_8,&local_c);
  param_1[0x12] = 0x3f800000;
  return param_1;
}
