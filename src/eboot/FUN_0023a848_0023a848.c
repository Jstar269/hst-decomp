/* HSTMATCH module=EBOOT.BIN start=0x0023a848 end=0x0023a900 symbol=FUN_0023a848 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: wrote the threshold as count >= 2 to match the retail comparison result register; exact match verified; names and types await human review. */
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

extern undefined * DAT_002cfc8c;
extern void FUN_002395f8();
extern void FUN_00239a7c();
extern void FUN_0023c2ac();

void FUN_0023a848(int param_1)
{
  FUN_002395f8();
  if (*(int *)(param_1 + 0x3c) >= 2) {
    FUN_00239a7c(param_1);
  }
  FUN_0023c2ac(param_1 + 0x50);
  *(undefined4 *)(param_1 + 0x17dc) = *(undefined4 *)(param_1 + 0x17d8);
  *(undefined4 *)(param_1 + 0x17f0) = *(undefined4 *)(param_1 + 0x17ec);
  *(undefined4 *)(param_1 + 0x17d8) = *(undefined4 *)(param_1 + 0x17d4);
  *(undefined4 *)(param_1 + 0x17ec) = *(undefined4 *)(param_1 + 0x17e8);
  *(undefined4 *)(param_1 + 0x17d4) = *(undefined4 *)(param_1 + 0x17d0);
  *(undefined4 *)(param_1 + 0x17e8) = *(undefined4 *)(param_1 + 0x17e4);
  *(undefined4 *)(param_1 + 0x17d0) = *(undefined4 *)(param_1 + 0x17cc);
  *(undefined4 *)(param_1 + 0x17e4) = *(undefined4 *)(param_1 + 0x17e0);
  *(int *)(param_1 + 0x17cc) = ((int)*(char *)(DAT_002cfc8c + 0x89) << 0x1e) >> 0x1e;
  *(int *)(param_1 + 0x17e0) = ((int)*(char *)(DAT_002cfc8c + 0x89) << 0x1a) >> 0x1e;
  return;
}
