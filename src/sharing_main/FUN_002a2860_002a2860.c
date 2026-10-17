/* HSTMATCH module=hstp_trans_main.prx start=0x002a2860 end=0x002a28c0 symbol=FUN_002a2860 lang=c99 */
/* Clone of src/eboot/FUN_00291158_00291158.c (hstclone.py tag u6cr3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: typed the float field and used a zero-result switch case; exact match verified; names and types await human review. */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern int FUN_002a28c0(void *,int);
extern int FUN_002a2988(void *,int,int);

int FUN_002a2860(void *param_1,int *param_2)
{
  int result = FUN_002a28c0(param_1,param_2[0]);
  switch (result) {
  case 0:
    return 0;
  default: {
    int value = (int)(((float *)param_2)[1] * 32768.0f);
    return FUN_002a2988(param_1,value,value);
  }
  }
}
