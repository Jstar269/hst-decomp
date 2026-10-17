/* HSTMATCH module=EBOOT.BIN start=0x001f4df0 end=0x001f4e40 symbol=FUN_001f4df0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned int undefined4;

typedef struct Sub { char pad[0x3c]; int field_3c; } Sub;
typedef struct Mgr { char pad[0xa8]; Sub *sub; } Mgr;
typedef struct Obj { char pad[0x521]; unsigned char flag; } Obj;

extern undefined DAT_0034179c;
extern Mgr *DAT_003386b0;
extern void FUN_001b3ce8(void *, int);
extern undefined4 FUN_001b4e14(void *, int, int, int, int);

void FUN_001f4df0(Obj *param_1)
{
  Sub *sub = DAT_003386b0->sub;
  if (param_1->flag != 0) {
    FUN_001b4e14(&sub->field_3c,0xbc,0,0,0);
  }
  FUN_001b3ce8(&DAT_0034179c,0x27);
}
