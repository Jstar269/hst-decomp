/* HSTMATCH module=hstp_trans_main.prx start=0x001fa858 end=0x001fa8a4 symbol=FUN_001fa858 lang=c99 */
/* Clone of src/eboot/FUN_001ec518.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_001f6b08();
extern void FUN_001f9c3c();

void FUN_001fa858(int *param_1,int param_2)
{
  if (*param_1 != 0) {
    FUN_001f9c3c(*param_1);
    FUN_001f6b08(*(int *)param_1[2],param_2);
  }
  return;
}
