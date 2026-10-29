/* HSTMATCH module=EBOOT.BIN start=0x001543d0 end=0x001544ec symbol=FUN_001543d0 lang=c++ data=0x002dc8c4 */
/* Hand-written reconstruction from the disassembly; exact match verified (id->object lookup in an inline helper with early returns, as in 0x0014fbd4; names and types await human review). Data: its string literals (1 strings, 0x002dc8c4-0x002dc8dd) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
struct Obj {
    virtual void v0();
};
struct PBase { char pad0[0xe0]; };
struct Player : PBase, Obj {};
struct ObjMgr { char pad0[0x4c]; Obj **objs; /* 0x4c objects by small id */ };
struct Ctx { int regs; int unk04; int unk08; Obj *actor; };
struct LinkCmd { void *vtbl; int unk04; int komonoId; int targetId; };

/* Object ids as used by script commands. */
enum {
    OBJ_ID_PLAYER = -1,     /* the player object; other negative ids mean the context's actor */
    OBJ_ID_TABLE_END = 100, /* ids below are indexes into ObjMgr::objs */
    OBJ_ID_LOOKUP_END = 1000 /* ids below are looked up by id, larger ones by the second lookup */
};

extern "C" {
extern unsigned char DAT_003402f0; /* script trace flag */
extern ObjMgr *DAT_0034a114;
extern Player *DAT_0034a118;
void FUN_0014d044(Ctx *);
void FUN_0014fd94(char *, int, int);
Obj *FUN_001c6f70(ObjMgr *, int, int);
Obj *FUN_001c70c0(ObjMgr *, int);
void FUN_00293764(Obj *, Obj *);
}

/* Resolve the object the command refers to (same id scheme as the sibling commands). */
inline Obj *Find(LinkCmd *self, Ctx *ctx)
{
    Obj *actor = ctx->actor;
    int id = self->targetId;
    if (id == OBJ_ID_PLAYER)
        return DAT_0034a118;
    if (id < 0)
        return actor;
    if (id < OBJ_ID_TABLE_END)
        return DAT_0034a114->objs[id];
    if (id < OBJ_ID_LOOKUP_END)
        return FUN_001c6f70(DAT_0034a114, id, 0);
    return FUN_001c70c0(DAT_0034a114, id);
}

/* Script command "LinkKomono": link the komono object to the target object. */
extern "C" int FUN_001543d0(LinkCmd *self, Ctx *ctx)
{
    if (DAT_003402f0 != 0) {
        FUN_0014d044(ctx);
        FUN_0014fd94("LinkKomono [%d -> (%d)]\n", self->komonoId, self->targetId);
    }
    Obj *target = Find(self, ctx);
    Obj *komono = FUN_001c70c0(DAT_0034a114, self->komonoId);
    if (komono != 0 && target != 0)
        FUN_00293764(komono, target);
    return 0;
}
