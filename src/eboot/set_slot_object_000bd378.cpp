/* HSTMATCH module=EBOOT.BIN start=0x000bd378 end=0x000bd480 symbol=FUN_000bd378 lang=c++ data=0x002d5458 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002d5458-0x002d5495) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/member_host.h"

extern "C" {
extern void FUN_000ba3ac(...);
extern void *FUN_00000bcc(unsigned);
extern char DAT_003073e4;
}

/* Creates the per-member record for the current member, storing the two values given. */
extern "C" int FUN_000bd378(MemberHost *self, int param_2, int param_3)
{
    if (self->cur < 0) {
        FUN_000ba3ac("CreateCHMasterObj() failed.\n");
        return 0;
    }
    OwnedObj *p = self->slots[self->cur];
    if (p) {
        delete p;
        self->slots[self->cur] = 0;
    }
    MemberObjRec *r = (MemberObjRec *)FUN_00000bcc(0x14);
    if (r) {
        r->vptr = &DAT_003073e4;
        r->unk8 = 0;
        r->unk4 = 0;
        r->unkc = 0;
        r->unk10 = 0;
    }
    self->slots[self->cur] = (OwnedObj *)r;
    ((MemberObjRec *)self->slots[self->cur])->unkc = param_3;
    ((MemberObjRec *)self->slots[self->cur])->unk4 = param_2;
    FUN_000ba3ac("CreateCHMasterObj() success\n");
    return 1;
}
