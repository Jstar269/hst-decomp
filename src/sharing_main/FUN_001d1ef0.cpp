/* HSTMATCH module=hstp_trans_main.prx start=0x001d1ef0 end=0x001d1f38 symbol=FUN_001d1ef0 lang=c++ */
/* Clone of src/eboot/FUN_001c3b64.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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
}
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_001d1ef0(int param_1)
{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x58);
  if (piVar1 != (int *)0x0) {
    delete ((VC_0 *)(piVar1));
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  return;
}
