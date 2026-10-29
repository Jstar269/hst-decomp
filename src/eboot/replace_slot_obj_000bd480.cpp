/* HSTMATCH module=EBOOT.BIN start=0x000bd480 end=0x000bd568 symbol=FUN_000bd480 lang=c++ data=0x002d5498 */
/* Ghidra pseudocode (hstgen.py tag a5/v17c) corrected by hand: typed 7-byte entry struct (unsigned char on = lbu) and slot array member addressed as g->slots[idx] at every use (the local-pointer form flips the addu operands), allocation stored with the merged store (beqzl) and o->c written through the new object; readability pass; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002d5498-0x002d54e2) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/member_host.h"

extern "C" {
extern char DAT_003073e4;
extern int FUN_00000a90(...);
extern void *FUN_00000bcc(...);
extern void FUN_000ba3ac(...);
}

/* Replaces the owned object of member idx with a new record; fails if the member slot is unused. */
extern "C" int FUN_000bd480(MemberHost *g, int idx, int a, int b)
{
    if (g->members[idx].used == 0) {
        FUN_000ba3ac("CreateCHReplicaObj() member is not exist\n");
        return 0;
    }
    if (g->slots[idx] != 0) {
        delete g->slots[idx];
        g->slots[idx] = 0;
    }
    MemberObjRec *o = (MemberObjRec *)FUN_00000bcc(0x14);
    if (o != 0) {
        o->vptr = &DAT_003073e4;
        o->unk8 = 0;
        o->unk4 = 0;
        o->unkc = 0;
        o->unk10 = 0;
    }
    g->slots[idx] = (OwnedObj *)o;
    o->unkc = b;
    ((MemberObjRec *)g->slots[idx])->unk4 = a;
    int r = FUN_00000a90(b);
    ((MemberObjRec *)g->slots[idx])->unk8 = r;
    FUN_000ba3ac("CreateCHReplicaObj() success\n");
    return 1;
}
