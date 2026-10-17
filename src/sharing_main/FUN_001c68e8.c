/* HSTMATCH module=hstp_trans_main.prx start=0x001c68e8 end=0x001c6940 symbol=FUN_001c68e8 lang=c99 */
/* Clone of src/eboot/FUN_001b8bfc.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_001c71e4();
extern undefined4 * FUN_001c73f4();

int FUN_001c68e8(int param_1)
{
  undefined4 uStack_4;
  int local_8;
  int local_c;
  
  FUN_001c73f4((undefined4 *)param_1);
  *(undefined1 *)(param_1 + 0xc) = 0;
  local_c = param_1 + 4;
  local_8 = *(int *)(param_1 + 8);
  FUN_001c71e4(&uStack_4,(int *)param_1,&local_8,&local_c);
  *(undefined4 *)(param_1 + 0x10) = 9;
  return param_1;
}
