/* HSTMATCH module=hstp_trans_main.prx start=0x0028f060 end=0x0028f0a8 symbol=FUN_0028f060 lang=c99 */
/* Clone of src/eboot/entry_lookup_0027dc90.c (hstclone.py tag lnmc): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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

extern int *DAT_003f3b14;

int *FUN_0028f060(int param_1,int *param_2)
{
  int *result;
  int *base;
  int i;
  int *p;

  result = 0;
  base = DAT_003f3b14;
  p = base;
  for (i = 0; i < 0x80; i++) {
    if (param_1 == *(int *)((char *)p + 0x30)) {
      result = (int *)((char *)base + i * 0x40);
      if (param_2 != 0) {
        *param_2 = i;
      }
      break;
    }
    p = (int *)((char *)p + 0x40);
  }
  return result;
}
// near miss from lane od3 (unreviewed)
