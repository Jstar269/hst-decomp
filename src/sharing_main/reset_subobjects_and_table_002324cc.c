/* HSTMATCH module=hstp_trans_main.prx start=0x002324cc end=0x002325d0 symbol=FUN_002324cc lang=c99 */
/* Clone of src/eboot/reset_subobjects_and_table_00222f58.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: typed subobject access in loop, block-scoped counter/pointer in clear loops; exact match verified; names and types await human review. */

typedef unsigned char undefined1;

typedef struct Sub Sub;
typedef struct Obj Obj;

struct Sub {
    char pad[0x60];
    float f96;
    float f100;
    char pad2[0x78 - 0x68];
    float f120;
};

struct Obj {
    char pad[0x60];
    int state;
    int pad1;
    Sub *sub[2];
    char pad2[0x40];
    unsigned char b0;
    char pad3;
    unsigned char b2;
    char pad4;
    float f180;
    float f184;
};

extern int DAT_003f3598;
extern int DAT_003f359c;
extern void FUN_00108dac(void);
extern void FUN_002325d0(void);

void FUN_002324cc(struct Obj *param_1)
{
  int i;
  
  param_1->b0 = 0;
  if (param_1->b2 == 0) {
    FUN_002325d0();
  }
  else {
    param_1->state = 100;
    for (i = 0; i < 2; i++) {
      if (param_1->sub[i] != 0) {
        if (i == 0) {
          param_1->sub[i]->f96 = param_1->f180;
          param_1->sub[i]->f100 = param_1->f184;
        }
        param_1->sub[i]->f120 = 1.0f;
      }
    }

    FUN_00108dac();
    
    {
      int j = 0;
      int q = DAT_003f3598;
      do {
        *(undefined1 *)(q + 0x20) = 0;
        *(undefined1 *)(q + 0x50) = 0;
        *(undefined1 *)(q + 0x80) = 0;
        *(undefined1 *)(q + 0xb0) = 0;
        *(undefined1 *)(q + 0xe0) = 0;
        *(undefined1 *)(q + 0x110) = 0;
        *(undefined1 *)(q + 0x140) = 0;
        j = j + 8;
        *(undefined1 *)(q + 0x170) = 0;
        q = q + 0x180;
      } while (j < 0x10);
    }

    {
      int j = 0;
      int q = DAT_003f359c;
      do {
        *(undefined1 *)(q + 0x20) = 0;
        *(undefined1 *)(q + 0x50) = 0;
        *(undefined1 *)(q + 0x80) = 0;
        *(undefined1 *)(q + 0xb0) = 0;
        *(undefined1 *)(q + 0xe0) = 0;
        *(undefined1 *)(q + 0x110) = 0;
        *(undefined1 *)(q + 0x140) = 0;
        j = j + 8;
        *(undefined1 *)(q + 0x170) = 0;
        q = q + 0x180;
      } while (j < 0x10);
    }
  }
}
