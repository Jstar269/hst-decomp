/* HSTMATCH module=hstp_trans_main.prx start=0x0015d8f4 end=0x0015d974 symbol=FUN_0015d8f4 lang=c99 data=0x00383a28 */
/* Clone of src/eboot/FUN_0015184c.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00383a28-0x00383a3c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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
extern undefined4 DAT_003f344c;
extern void FUN_00158b2c();
extern void FUN_0015bb68();
extern void FUN_001d5588();

undefined4 FUN_0015d8f4(int param_1,int param_2)
{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(*(int *)(param_2 + 0xc) + 0x30);
  FUN_001d5588(DAT_003f344c,uVar1,*(undefined4 *)(param_1 + 8));
  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(param_2);
    FUN_0015bb68("SetMyLavel [%d:%s]\n",uVar1,*(undefined4 *)(param_1 + 8));
  }
  return 0;
}
