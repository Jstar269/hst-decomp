/* HSTMATCH module=EBOOT.BIN start=0x0012d868 end=0x0012d890 symbol=FUN_0012d868 lang=c99 */
/* Clone of src/sharing_main/FUN_00138d68.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
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

extern void FUN_0005f110();

void FUN_0012d868(int param_1)
{
  if (*(int *)(param_1 + 4) != 0) {
    FUN_0005f110(*(int *)(param_1 + 4));
  }
  return;
}
