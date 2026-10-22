/* HSTMATCH module=EBOOT.BIN start=0x000df44c end=0x000df5c0 symbol=FUN_000df44c lang=c99 */
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
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern unsigned int DAT_00338b4c;
extern void FUN_000dfd78(void *p, int n);
extern int FUN_002b77b8(void);
extern void FUN_002b77e8(int h);
extern int FUN_002b7880(char *name, int a, int b, unsigned int size, int c, int d);
extern void FUN_002b78b8(int fd);
extern int FUN_002b7950(int fd, void *out);
extern int FUN_002b79b8(void *p, char *name, int n, int a, int b);

struct Obj {
  int f00;
  int f04;
  int f08;
  unsigned char name[0x20];
  int f2c;
  int f30;
  int f34;
  int f38[8];
  int f58;
  int f5c;
  int f60;
};

struct Obj *FUN_000df44c(char *param_1, int param_2, unsigned int param_3)
{
  int fd;
  unsigned int flags;
  char *name;
  int i;
  unsigned char *src;
  unsigned int size;
  unsigned int val;
  struct Obj *obj;
  void *out[4];

  flags = param_3;
  name = param_1;
  size = (param_2 + 0xff) & 0xffffff00;
  fd = FUN_002b7880(name, 2, (flags & 0x4000) ? 0x4000 : 0, size, 1, 0);
  if (fd < 0) goto fail;
  if (FUN_002b7950(fd, out) < 0) goto fail_close;
  obj = (struct Obj *)out[0];
  val = (flags & 1) ? size : 0;
  obj->f08 = val | ((flags >> 14) & 1);
  obj->f04 = fd;
  i = 0;
  if (*name != '\0') {
    src = (unsigned char *)name;
    do {
      obj->name[i] = *src;
      i++;
      src = (unsigned char *)name + i;
    } while ((name[i] != '\0') & (i < 0x1f));
  }
  obj->name[i] = 0;
  obj->f34 = 1;
  obj->f2c = (int)size;
  obj->f30 = 0;
  if (FUN_002b79b8(obj->f38, name, 0x200, 0, 0) < 0) goto fail_close;
  obj->f5c = (int)&obj->f58;
  obj->f58 = (int)&obj->f58;
  FUN_000dfd78(&obj->f60, (int)size - 0x60);
  {
    int h = FUN_002b77b8();
    obj->f00 = (int)obj + 1;
    DAT_00338b4c = DAT_00338b4c + 1;
    FUN_002b77e8(h);
  }
  return obj;
fail_close:
  FUN_002b78b8(fd);
fail:
  return 0;
}
// SKIP: retail's second instruction pair `addiu s1,a1,255; ins s1,zero,0,8` clears the low byte with
// Allegrex `ins rd,$zero` (also `movn`, plain beqz/bltz, cold failure block AFTER the epilogue, and the
// branchless `sltu/slti/and` && at the loop tail): newer Sony Allegrex GCC output, not mwccpsp 219.
// Ruled out: every `& 0xffffff00` / `& ~0xff` / bitfield / union spelling under mwccpsp gives `li;and`;
// gcc171/gcc171x-O2 give 87/93 words and do not emit `ins rd,$zero` either. Structure (fields, calls,
// loop) otherwise mirrors retail.
// near miss from lane od3 (unreviewed)
