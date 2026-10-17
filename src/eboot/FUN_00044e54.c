/* HSTMATCH module=EBOOT.BIN start=0x00044e54 end=0x00044eac symbol=FUN_00044e54 lang=c99 */
/* Clone of src/sharing_main/FUN_00044f4c.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern undefined4 DAT_0030ff7c;
extern undefined4 DAT_0030ff80;
extern int FUN_000df694();

void FUN_00044e54(undefined4 param_1,int param_2)
{
  int iVar1;
  uint local_8 [2];
  
  local_8[0] = 8;
  local_8[1] = 4;
  iVar1 = FUN_000df694(DAT_0030ff7c,param_2 + 3U & 0xfffffffc,local_8);
  DAT_0030ff80 = DAT_0030ff80 + *(int *)(iVar1 + -4);
  return;
}
