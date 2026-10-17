/* HSTMATCH module=hstp_trans_main.prx start=0x001c6940 end=0x001c69e4 symbol=FUN_001c6940 lang=c99 */
/* Clone of src/eboot/FUN_001b8c54.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_003eaad8;
extern void FUN_00000a00();
extern int FUN_001c0454();
extern void FUN_001c6a18();
extern void FUN_001c71e4();

int FUN_001c6940(int param_1,short param_2)
{
  undefined1 auStack_4 [4];
  undefined4 local_8;
  int local_c;
  
  if (param_1 != 0) {
    FUN_001c6a18();
    if ((((param_1 != 0) && (FUN_001c0454((int)&DAT_003eaad8,0), param_1 != 0)) && (param_1 != 0)) &&
       (param_1 != 0)) {
      local_c = param_1 + 4;
      local_8 = *(undefined4 *)(param_1 + 8);
      FUN_001c71e4(auStack_4,param_1,&local_8,&local_c);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
