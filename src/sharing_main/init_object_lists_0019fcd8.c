/* HSTMATCH module=hstp_trans_main.prx start=0x0019fcd8 end=0x0019ff00 symbol=FUN_0019fcd8 lang=c99 */
/* Clone of src/eboot/init_object_lists_001934c8.c (hstclone.py tag fm4c): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct {
    int key;
    unsigned int idx;
} Key;

extern int DAT_003eaa88;
extern int *DAT_003eaa70;
extern int *DAT_003eaa74;
extern int *DAT_003eaa78;
extern int *DAT_003eaa7c;
extern int *DAT_003eaa80;

extern int FUN_00000bcc(int);
extern void FUN_0019ff68(int);
extern void FUN_001a2df0(void *, int, Key *);

int FUN_0019fcd8(void)
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
  if (DAT_003eaa88 == 0) {
  if ((obj = FUN_00000bcc(0x50)) != 0) {
    FUN_0019ff68(obj);
    FUN_0019ff68(obj + 0x10);
    FUN_0019ff68(obj + 0x20);
    FUN_0019ff68(obj + 0x30);
    FUN_0019ff68(obj + 0x40);
  }
  DAT_003eaa88 = obj;
  pu = DAT_003eaa70;
  u = 0;
  if (*pu != 0) {
    i = 0;
    do {
      k1.key = pu[1] + i + 0xf;
      k1.idx = u;
      FUN_001a2df0(b1, DAT_003eaa88 + 0x30, &k1);
      u = u + 1;
      i = i + 0x9c;
    } while (u < *pu);
  }
  pu = DAT_003eaa74;
  u = 0;
  if (*pu != 0) {
    i = 0;
    do {
      k2.key = pu[1] + i;
      k2.idx = u;
      FUN_001a2df0(b2, DAT_003eaa88 + 0x10, &k2);
      u = u + 1;
      i = i + 0x6c;
    } while (u < *pu);
  }
  pu = DAT_003eaa78;
  u = 0;
  if (*pu != 0) {
    i = 0;
    do {
      k3.key = pu[1] + i;
      k3.idx = u;
      FUN_001a2df0(b3, DAT_003eaa88, &k3);
      u = u + 1;
      i = i + 0x70;
    } while (u < *pu);
  }
  pu = DAT_003eaa7c;
  u = 0;
  if (*pu != 0) {
    i = 0;
    do {
      k4.key = pu[1] + i + 0xf;
      k4.idx = u;
      FUN_001a2df0(b4, DAT_003eaa88 + 0x40, &k4);
      u = u + 1;
      i = i + 0x9c;
    } while (u < *pu);
  }
  pu = DAT_003eaa80;
  u = 0;
  if (*pu != 0) {
    i = 0;
    do {
      k5.key = pu[1] + i;
      k5.idx = u;
      FUN_001a2df0(b5, DAT_003eaa88 + 0x20, &k5);
      u = u + 1;
      i = i + 0x6c;
    } while (u < *pu);
  }
  ret = 1;
  }
  return ret;
}
