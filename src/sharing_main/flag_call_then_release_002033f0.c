/* HSTMATCH module=hstp_trans_main.prx start=0x002033f0 end=0x00203440 symbol=FUN_002033f0 lang=c99 */
/* Hand-written reconstruction from the disassembly (port of the matched EBOOT twin src/eboot/flag_call_then_release_001f4df0.c with the Sharing addresses); exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned int undefined4;

typedef struct Sub { char pad[0x3c]; int field_3c; } Sub;
typedef struct Mgr { char pad[0xa8]; Sub *sub; } Mgr;
typedef struct Obj { char pad[0x521]; unsigned char flag; } Obj;

extern undefined DAT_003eaad8;
extern Mgr *DAT_003e19f0;
extern void FUN_001c1f44(void *, int);
extern undefined4 FUN_001c2a28(void *, int, int, int, int);

void FUN_002033f0(Obj *param_1)
{
  Sub *sub = DAT_003e19f0->sub;
  if (param_1->flag != 0) {
    FUN_001c2a28(&sub->field_3c,0xbc,0,0,0);
  }
  FUN_001c1f44(&DAT_003eaad8,0x27);
}
