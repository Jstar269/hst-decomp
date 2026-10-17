/* HSTMATCH module=hstp_trans_main.prx start=0x0017d9b8 end=0x0017da40 symbol=FUN_0017d9b8 lang=c99 */
/* Clone of src/eboot/fun_0017168c.c (hstclone.py tag u4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (started from hstgen.py tag a1/v0); matching idiom: reuse total for total < 5 so MWCC branches on the comparison result register; exact match verified; names and types await human review. */
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

extern void FUN_001c0018(void *, int *);
extern undefined4 FUN_001c0ce8();
extern undefined DAT_003eaad8;

struct Self {
  char pad0[0x588];
  int x588;
  int x58c;
  int x590;
  int x594;
  int x598;
  char pad1[0x98];
  int handle;
};

void FUN_0017d9b8(struct Self *param_1)
{
  undefined4 uVar1;

  int total = 0;
  total += param_1->x588;
  total += param_1->x58c;
  total += param_1->x590;
  total += param_1->x594;
  total += param_1->x598;
  if ((total = (total < 5))) {
  }
  else {
    if (param_1->handle >= 0) {
      FUN_001c0018(&DAT_003eaad8,&param_1->handle);
    }
    uVar1 = FUN_001c0ce8(&DAT_003eaad8,0x58);
    param_1->handle = uVar1;
  }
  return;
}
