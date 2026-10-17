/* HSTMATCH module=hstp_trans_main.prx start=0x0020d058 end=0x0020d090 symbol=FUN_0020d058 lang=c99 */
/* Clone of src/eboot/FUN_001fe888.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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


int FUN_0020d058(int *param_1)
{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  do {
    if (*param_1 != 0x7fffffff) {
      iVar1 = iVar1 + 1;
    }
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 8;
  } while (iVar2 < 10);
  return iVar1;
}
