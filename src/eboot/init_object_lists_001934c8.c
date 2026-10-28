/* HSTMATCH module=EBOOT.BIN start=0x001934c8 end=0x001936f0 symbol=FUN_001934c8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct {
    int key;
    unsigned int idx;
} Key;

extern int DAT_00341748;
extern int *DAT_00341730;
extern int *DAT_00341734;
extern int *DAT_00341738;
extern int *DAT_0034173c;
extern int *DAT_00341740;

extern int FUN_00000bcc(int);
extern void FUN_00193758(int);
extern void FUN_001964f8(void *, int, Key *);

int FUN_001934c8(void)
{
  int *pu;
  unsigned int u;
  int i;
  int obj;
  int ret;
  u8 b1[8];
  Key k1;
  u8 b2[8];
  Key k2;
  u8 b3[8];
  Key k3;
  u8 b4[8];
  Key k4;
  u8 b5[8];
  Key k5;

  ret = 0;
  if (DAT_00341748 == 0) {
  if ((obj = FUN_00000bcc(0x50)) != 0) {
    FUN_00193758(obj);
    FUN_00193758(obj + 0x10);
    FUN_00193758(obj + 0x20);
    FUN_00193758(obj + 0x30);
    FUN_00193758(obj + 0x40);
  }
  DAT_00341748 = obj;
  pu = DAT_00341730;
  u = 0;
  if (*pu != 0) {
    i = 0;
    do {
      k1.key = pu[1] + i + 0xf;
      k1.idx = u;
      FUN_001964f8(b1, DAT_00341748 + 0x30, &k1);
      u = u + 1;
      i = i + 0x9c;
    } while (u < *pu);
  }
  pu = DAT_00341734;
  u = 0;
  if (*pu != 0) {
    i = 0;
    do {
      k2.key = pu[1] + i;
      k2.idx = u;
      FUN_001964f8(b2, DAT_00341748 + 0x10, &k2);
      u = u + 1;
      i = i + 0x6c;
    } while (u < *pu);
  }
  pu = DAT_00341738;
  u = 0;
  if (*pu != 0) {
    i = 0;
    do {
      k3.key = pu[1] + i;
      k3.idx = u;
      FUN_001964f8(b3, DAT_00341748, &k3);
      u = u + 1;
      i = i + 0x70;
    } while (u < *pu);
  }
  pu = DAT_0034173c;
  u = 0;
  if (*pu != 0) {
    i = 0;
    do {
      k4.key = pu[1] + i + 0xf;
      k4.idx = u;
      FUN_001964f8(b4, DAT_00341748 + 0x40, &k4);
      u = u + 1;
      i = i + 0x9c;
    } while (u < *pu);
  }
  pu = DAT_00341740;
  u = 0;
  if (*pu != 0) {
    i = 0;
    do {
      k5.key = pu[1] + i;
      k5.idx = u;
      FUN_001964f8(b5, DAT_00341748 + 0x20, &k5);
      u = u + 1;
      i = i + 0x6c;
    } while (u < *pu);
  }
  ret = 1;
  }
  return ret;
}
