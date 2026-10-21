/* HSTMATCH module=hstp_trans_main.prx start=0x002a9834 end=0x002a98e4 symbol=FUN_002a9834 lang=c99 */
/* Clone of src/eboot/report_status_errors_0029a5b0.c (hstclone.py tag c160307): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the global tested first is FUN_002c7af8's argument (Ghidra dropped it, so retail loads it into a0); exact match verified; names and types await human review. */
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

extern int DAT_003a8b9c;
extern char DAT_003a8c10[];
extern char DAT_003a8c48[];
extern char DAT_003a8c78[];
extern char DAT_003a8ca8[];
extern void FUN_002a9808(const char *, int);
extern int FUN_002c7af8(int);
extern int FUN_002c7b00();
extern int FUN_002c7b18();
extern int FUN_002c7bc8();

void FUN_002a9834(void)
{
  int iVar1;
  int initial_count = DAT_003a8b9c;
  
  if (0 < initial_count) {
    iVar1 = FUN_002c7af8(initial_count);
    if (iVar1 < 0) {
      FUN_002a9808(DAT_003a8c10,iVar1);
    }
    DAT_003a8b9c = -1;
  }
  iVar1 = FUN_002c7b00();
  if (iVar1 < 0) {
    FUN_002a9808(DAT_003a8c48,iVar1);
  }
  iVar1 = FUN_002c7bc8();
  if (iVar1 < 0) {
    FUN_002a9808(DAT_003a8c78,iVar1);
  }
  iVar1 = FUN_002c7b18();
  if (iVar1 < 0) {
    FUN_002a9808(DAT_003a8ca8,iVar1);
  }
  return;
}
