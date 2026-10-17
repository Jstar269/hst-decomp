/* HSTMATCH module=hstp_trans_main.prx start=0x00111414 end=0x00111474 symbol=FUN_00111414 lang=c99 */
/* Clone of src/eboot/FUN_0010b308.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00111474();
extern void FUN_00120e84();

void FUN_00111414(int param_1)
{
  *(undefined4 *)(param_1 + 0xd4) = 0;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  *(undefined4 *)(param_1 + 0x110) = 0;
  *(undefined1 *)(param_1 + 0x114) = 0;
  *(undefined4 *)(param_1 + 0x118) = 0;
  if (*(uint *)(param_1 + 0x128) < 4) {
    FUN_00120e84(param_1 + 0x120,4);
  }
  *(undefined1 *)(param_1 + 0x12d) = 1;
  FUN_00111474(param_1,0);
  return;
}
