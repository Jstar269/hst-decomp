/* HSTMATCH module=hstp_trans_main.prx start=0x00264d0c end=0x00264d50 symbol=FUN_00264d0c lang=c99 */
/* Clone of src/eboot/idx_flags_slot_null_00254894.c (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
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

typedef struct Obj_00264d0c {
  int f0;
  uchar a4[236];
  uchar af0[236];
  int slot[1];
} Obj_00264d0c;

int FUN_00264d0c(Obj_00264d0c *o, int idx)
{
  int ok = (o->af0[idx] != 0) ^ 1;
  if (ok) ok = o->a4[idx] != 0;
  if (ok) ok = o->slot[idx] == 0;
  return ok;
}
