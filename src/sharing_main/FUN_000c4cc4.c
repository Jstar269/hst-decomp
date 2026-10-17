/* HSTMATCH module=hstp_trans_main.prx start=0x000c4cc4 end=0x000c4d4c symbol=FUN_000c4cc4 lang=c99 */
/* Clone of src/eboot/FUN_000c1624.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_002d0310;
extern undefined DAT_0037c3ac;
extern undefined DAT_0037c3bc;
extern undefined DAT_0037c3c4;
extern char DAT_0037c3b4[];
extern undefined4 * FUN_00011090();
extern uint * FUN_000114c0();

void FUN_000c4cc4(int param_1)
{
  if (param_1 != 0) {
    FUN_000114c0(param_1,0,0x4c);
    FUN_00011090(param_1 + 0x20,&DAT_002d0310,0x10);
    *(undefined **)(param_1 + 0x30) = &DAT_0037c3ac;
    *(char **)(param_1 + 0x34) = DAT_0037c3b4;
    *(undefined **)(param_1 + 0x38) = &DAT_0037c3bc;
    *(undefined **)(param_1 + 0x3c) = &DAT_0037c3c4;
    *(undefined **)(param_1 + 0x40) = &DAT_0037c3c4;
    *(undefined4 *)(param_1 + 0x44) = 1;
    *(undefined1 *)(param_1 + 0x48) = 1;
  }
  return;
}
