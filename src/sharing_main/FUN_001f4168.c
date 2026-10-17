/* HSTMATCH module=hstp_trans_main.prx start=0x001f4168 end=0x001f41d4 symbol=FUN_001f4168 lang=c99 */
/* Clone of src/eboot/FUN_001e5f50.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_00108f54();
extern void FUN_001f08e8();
extern void FUN_001f443c();

void FUN_001f4168(int param_1,undefined4 param_2,uint param_3,int param_4)
{
  FUN_001f08e8(param_1);
  FUN_00108f54(*(int *)(param_1 + 0x1958),0);
  FUN_001f443c(param_1,param_2,param_3,param_4,'\0');
  return;
}
