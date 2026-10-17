/* HSTMATCH module=hstp_trans_main.prx start=0x000eeaa8 end=0x000eeaf0 symbol=FUN_000eeaa8 lang=c++ */
/* Clone of src/eboot/delete_member_000e99d4.cpp (hstclone.py tag c37): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (delete of a member through its virtual destructor); exact match verified; names and types await human review. */
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
struct VD { virtual ~VD(); };

extern "C" void FUN_000eeaa8(int param_1)
{
  VD *p = *(VD **)(param_1 + 0x540);
  if (p != 0) {
    delete p;
    *(VD **)(param_1 + 0x540) = 0;
  }
}
