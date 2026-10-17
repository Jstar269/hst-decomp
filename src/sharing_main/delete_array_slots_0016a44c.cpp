/* HSTMATCH module=hstp_trans_main.prx start=0x0016a44c end=0x0016a4b4 symbol=FUN_0016a44c lang=c++ */
/* Clone of src/eboot/delete_array_slots_0015dec0.cpp (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: loop index declared before the walking pointer (s-register order); exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code(...);
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
extern int DAT_003e9738;
}
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_0016a44c(void)
{
  int iVar3;
  int iVar2;
  int *piVar1;
  
  iVar3 = 0;
  iVar2 = DAT_003e9738;
  do {
    piVar1 = *(int **)(iVar2 + 0x34);
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      *(undefined4 *)(iVar2 + 0x34) = 0;
    }
    iVar3 = iVar3 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar3 < 3);
  return;
}
