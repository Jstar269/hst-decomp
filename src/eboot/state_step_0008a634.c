/* HSTMATCH module=EBOOT.BIN start=0x0008a634 end=0x0008a72c symbol=FUN_0008a634 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_002aef68(void *ctx);
extern int FUN_001fb4fc(void);
extern void FUN_0015d244(int value, int mode);
extern void FUN_00234158(int *timer, int frames);
extern int DAT_0034a678;

struct Sub {
  unsigned char pad00[0x515];
  unsigned char f515;         /* 0x515 */
  unsigned char f516;         /* 0x516 */
  unsigned char pad517[0x8b];
  unsigned char f5a2;         /* 0x5a2 */
};

struct Obj {
  unsigned char pad00[0x40];
  int f40;                    /* 0x40 */
  int state;                  /* 0x44 */
  int f48;                    /* 0x48 */
  unsigned char pad4c[0x54];
  struct Sub *sub;            /* 0xa0 */
  void *ctx;                  /* 0xa4 */
};

void FUN_0008a634(struct Obj *param_1)
{
  switch (param_1->state) {
  case 0:
    param_1->f48 = 0;
    param_1->state = param_1->state + 1;
    break;
  case 1:
    FUN_002aef68(param_1->ctx);
    if (param_1->sub->f515 != 0) {
      if (FUN_001fb4fc() != 0) {
        if (param_1->sub->f5a2 != 0) {
          FUN_0015d244(DAT_0034a678, 1);
          FUN_00234158(&DAT_0034a678, 75);
        }
        else {
          FUN_00234158(&DAT_0034a678, 30);
        }
      }
      else {
        FUN_0015d244(DAT_0034a678, 0);
        FUN_00234158(&DAT_0034a678, 75);
      }
    }
    else if (param_1->sub->f516 != 0) {
      param_1->f40 = 10;
    }
    break;
  }
}
