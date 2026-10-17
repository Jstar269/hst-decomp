/* HSTMATCH module=hstp_trans_main.prx start=0x0025e1cc end=0x0025e29c symbol=FUN_0025e1cc lang=c99 */
/* Clone of src/eboot/initialize_slots_0024df94.c (hstclone.py tag u5cr3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reordered nested-loop counters and isolated the final record cursor; exact match verified; names and types await human review. */
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

extern void FUN_0025e430();

int FUN_0025e1cc(int param_1)
{
  int iVar1;
  int iVar3;
  int iVar2;
  
  iVar1 = 0;
  do {
    iVar3 = 0;
    do {
      iVar2 = 0;
      do {
        FUN_0025e430(param_1,iVar1 == 0,iVar3,iVar2,0xffffffff);
        iVar2 = iVar2 + 1;
      } while (iVar2 < 6);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x10);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  *(undefined4 *)(param_1 + 0xc0) = 0;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  {
    int off = 0;
    char *p = (char *)param_1;
    do {
      *(undefined4 *)(p + 200) = 0;
      *(undefined4 *)(p + 0xcc) = 0;
      *(undefined4 *)(p + 0xd0) = 0;
      *(undefined4 *)(p + 0xd4) = 0;
      *(undefined4 *)(p + 0xd8) = 0;
      *(undefined4 *)(p + 0xdc) = 0;
      off = off + 7;
      *(undefined4 *)(p + 0xe0) = 0;
      p = p + 0x1c;
    } while (off < 0xe);
  }
  return param_1;
}
