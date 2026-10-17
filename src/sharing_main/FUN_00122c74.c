/* HSTMATCH module=hstp_trans_main.prx start=0x00122c74 end=0x00122cc4 symbol=FUN_00122c74 lang=c99 */
/* Clone of src/eboot/FUN_00117c24.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003e95c4;
extern void FUN_00122dc0();
extern void FUN_00122e94();

void FUN_00122c74(int param_1)
{
  FUN_00122dc0(param_1,1,0xffffffec,1);
  FUN_00122e94(param_1);
  *(undefined1 *)(param_1 + 0x4c) = 1;
  *(undefined1 *)(*(int *)(DAT_003e95c4 + 0x80) + 0x79) = 0;
  return;
}
