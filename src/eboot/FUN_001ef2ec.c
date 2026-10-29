/* HSTMATCH module=EBOOT.BIN start=0x001ef2ec end=0x001ef3f8 symbol=FUN_001ef2ec lang=c99 data=0x002ee7d0 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002ee7d0-0x002ee806) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/prize_screen.h"

extern int DAT_00310fc4;
extern int DAT_0034b5d0;
extern void FUN_00000020(char *);
extern void FUN_001ef3f8(char *);
extern void FUN_000429a0(int);
extern void FUN_00042698(int, int, int);
extern void * FUN_00000bcc(int);
extern void * FUN_00218c00(void *);
extern void FUN_001f2954(PrizeScreen *);
extern void FUN_001f898c(PrizeScreen *);
extern void FUN_001fb928(PrizeSub *, int, int);
extern void FUN_001fb9dc(PrizeSub *);
extern void FUN_001ef424(PrizeScreen *);
extern void FUN_001ff668(void);
extern void FUN_002adfc4(int);
extern void FUN_00000028(void);

/* Start-up of the prize screen: logs, clears the state, allocates the helper object and initialises the parts. */
void FUN_001ef2ec(PrizeScreen *self)
{
    void *obj;

    FUN_00000020("Prize");
    FUN_001ef3f8("============ Start Prize ===================\n");
    FUN_000429a0(DAT_00310fc4);
    FUN_00042698(DAT_00310fc4, 0x200, 0x100);
    self->unk515 = 0;
    self->unk516 = 0;
    self->unk517 = 0;
    self->unk817c = 0;
    self->unk8198 = 0;
    self->unk558 = 0;
    self->unk3e8 = 0;
    self->unk3f8 = 0;
    self->unk3ec = 0;
    self->unk3fc = 0;
    self->unk3f0 = 0;
    self->unk400 = 0;
    self->unk3f4 = 0;
    self->unk404 = 0;
    self->unk520 = 0;
    obj = FUN_00000bcc(0x20);
    if (obj != 0)
        obj = FUN_00218c00(obj);
    self->obj = obj;
    FUN_001f2954(self);
    FUN_001f898c(self);
    FUN_001fb928(&self->sub, 1, 1);
    FUN_001fb9dc(&self->sub);
    FUN_001ef424(self);
    FUN_001ff668();
    FUN_002adfc4(DAT_0034b5d0);
    FUN_00000028();
}
