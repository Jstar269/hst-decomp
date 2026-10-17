/* HSTMATCH module=EBOOT.BIN start=0x00222f58 end=0x0022305c symbol=FUN_00222f58 lang=c99 */
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

extern int DAT_0034a268;
extern int DAT_0034a26c;
extern void FUN_00103480(void);
extern void FUN_0022305c(void);

void FUN_00222f58(struct Obj *param_1)
{
  int i;
  
  param_1->b0 = 0;
  if (param_1->b2 == 0) {
    FUN_0022305c();
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

    FUN_00103480();
    
    {
      int j = 0;
      int q = DAT_0034a268;
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
      int q = DAT_0034a26c;
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
