/* HSTMATCH module=hstp_trans_main.prx start=0x00238948 end=0x002389a0 symbol=FUN_00238948 lang=c99 */
/* Clone of src/eboot/FUN_002293d4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_000009e4();
extern void FUN_000652ac();
extern void FUN_00238ed0();

void FUN_00238948(int param_1)
{
  int local_4;
  
  local_4 = *(int *)(param_1 + 0xc);
  if (local_4 != param_1 + 4) {
    do {
      FUN_000009e4(*(undefined4 *)(local_4 + 0xc));
      FUN_000652ac(&local_4);
    } while (local_4 != param_1 + 4);
  }
  FUN_00238ed0(param_1);
  return;
}
