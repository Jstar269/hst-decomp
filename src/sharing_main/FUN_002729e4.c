/* HSTMATCH module=hstp_trans_main.prx start=0x002729e4 end=0x00272a4c symbol=FUN_002729e4 lang=c99 */
/* Clone of src/eboot/FUN_00261bbc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_001055a4();

void FUN_002729e4(int param_1,int param_2)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(param_1 + param_2 * 0xf0);
  FUN_001055a4(*puVar1,0x80808080);
  FUN_001055a4(puVar1[3],0x80808080);
  FUN_001055a4(puVar1[4],puVar1[6]);
  FUN_001055a4(puVar1[5],0x80808080);
  return;
}
