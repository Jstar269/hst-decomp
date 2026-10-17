/* HSTMATCH module=hstp_trans_main.prx start=0x001d8ec4 end=0x001d8f00 symbol=FUN_001d8ec4 lang=c99 */
/* Clone of src/eboot/FUN_001ca8f0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 * FUN_001d8f00();
extern uint * FUN_00239cb8();
extern int FUN_00239ea4();

void FUN_001d8ec4(void)
{
  char *iVar1;
  uint *puVar2;
  uint auStack_1250 [1172];
  
  iVar1 = (char *)(FUN_00239ea4());
  puVar2 = FUN_00239cb8(auStack_1250);
  FUN_001d8f00((undefined4 *)(iVar1 + 0xa210),puVar2);
  return;
}
