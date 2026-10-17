/* HSTMATCH module=hstp_trans_main.prx start=0x000e5cf4 end=0x000e5d60 symbol=FUN_000e5cf4 lang=c++ */
/* Clone of src/eboot/release_members_000e172c.cpp (hstclone.py tag c37): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (release of an array member and a polymorphic member); exact match verified; names and types await human review. */
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

struct E { E(); int x; };
struct VD { virtual ~VD(); };
struct T { char pad[0x40]; VD *m40; char pad2[0x10]; E *m54; };
extern "C" void FUN_000e5d60(T *);

extern "C" void FUN_000e5cf4(T *self)
{
  FUN_000e5d60(self);
  if (self->m54) {
    delete[] self->m54;
    self->m54 = 0;
  }
  if (self->m40) {
    delete self->m40;
    self->m40 = 0;
  }
}
