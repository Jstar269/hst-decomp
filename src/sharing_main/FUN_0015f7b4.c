/* HSTMATCH module=hstp_trans_main.prx start=0x0015f7b4 end=0x0015f820 symbol=FUN_0015f7b4 lang=c99 */
/* Clone of src/eboot/FUN_00153584.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003e9630;
extern undefined * DAT_003f344c;
extern char DAT_00383c48[];
extern void FUN_00158b2c();
extern void FUN_0015bb68();
extern void FUN_001d61c4();

undefined4 FUN_0015f7b4(int param_1,undefined4 param_2)
{
  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(param_2);
    FUN_0015bb68(DAT_00383c48,*(undefined4 *)(param_1 + 8),
                 *(undefined4 *)(param_1 + 0xc));
  }
  FUN_001d61c4(DAT_003f344c,*(undefined4 *)(DAT_003f344c + 0xcc),*(int *)(param_1 + 8) + -1,
               *(undefined4 *)(param_1 + 0xc),0);
  return 0;
}
