/* HSTMATCH module=EBOOT.BIN start=0x0004cfd0 end=0x0004d028 symbol=FUN_0004cfd0 lang=c99 */
/* Clone of src/sharing_main/FUN_0004d2c4.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern undefined DAT_0030ab9c;
extern undefined DAT_0030fbfd;
extern undefined4 DAT_00311158;
extern void FUN_0001c810();
extern int FUN_002b7738();

undefined4 FUN_0004cfd0(void)
{
  undefined4 uVar1;
  
  if (DAT_00311158 == 0) {
    if (DAT_0030fbfd != '\0') {
      FUN_0001c810((int)&DAT_0030ab9c);
      return 0;
    }
  }
  else {
    DAT_00311158 = DAT_00311158 + -1;
  }
  uVar1 = FUN_002b7738();
  return uVar1;
}
