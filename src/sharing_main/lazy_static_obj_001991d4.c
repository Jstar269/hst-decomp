/* HSTMATCH module=hstp_trans_main.prx start=0x001991d4 end=0x00199274 symbol=FUN_001991d4 lang=c99 */
/* Clone of src/eboot/lazy_static_obj_0018c9f4.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: the function-local static guard DAT_003ea8f4 is a signed char and DAT_003ea904 a struct {char; int} (sb/sw), the registration record is passed as a symbol address; exact match verified; names and types await human review. */
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

extern undefined DAT_002f6260;
extern undefined * DAT_003ea8f0;
extern char DAT_003ea8f4;
extern char DAT_003ea8f8[];
typedef struct T { char c; int i; } T;
extern T DAT_003ea904;
extern undefined4 FUN_00000f74();
extern undefined4 FUN_00110adc();
extern void FUN_001022b8();

undefined1 * FUN_001991d4(int param_1)
{
  undefined1 *puVar1;
  
  if ((DAT_003ea8f0 == 0) && (param_1 == 0x10)) {
    if (DAT_003ea8f4 == 0) {
      DAT_003ea904.c = 0;
      DAT_003ea904.i = 0;
      FUN_00000f74(&DAT_003ea904,FUN_001022b8,DAT_003ea8f8);
      DAT_003ea8f4 = 1;
    }
    FUN_00110adc(&DAT_003ea904,&DAT_002f6260);
    puVar1 = (unsigned char *)(&DAT_003ea904);
  }
  else {
    puVar1 = (undefined1 *)(DAT_003ea8f0 + param_1 * 0x10);
  }
  return puVar1;
}
