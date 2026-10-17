/* HSTMATCH module=hstp_trans_main.prx start=0x00277668 end=0x002776c0 symbol=FUN_00277668 lang=c99 */
/* Clone of src/eboot/FUN_00266760.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined4 FUN_001377d0();
extern undefined4 FUN_00137a18();
extern void FUN_00277704();

void FUN_00277668(int param_1)
{
  uchar cVar1;
  undefined1 uVar2;
  
  cVar1 = FUN_001377d0(param_1 + 0x80);
  if (cVar1 != '\0') {
    uVar2 = FUN_00137a18(param_1 + 0x80);
    *(undefined1 *)(param_1 + 0x120) = uVar2;
    if (*(uchar *)(param_1 + 0x120) == '\0') {
      FUN_00277704(param_1,1);
    }
  }
  return;
}
