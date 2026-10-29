/* HSTMATCH module=EBOOT.BIN start=0x00154cc0 end=0x00154dc8 symbol=FUN_00154cc0 lang=c++ data=0x002dc9e8 */
/* Hand-written reconstruction from the disassembly; exact match verified (id->object lookup in an inline helper with early returns, as in 0x0014fbd4/0x001543d0; names and types await human review). Data: its string literals (1 strings, 0x002dc9e8-0x002dca07) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
struct Obj {
    virtual void v0();
};
struct PBase { char pad0[0xe0]; };
struct Player : PBase, Obj {};
struct ObjMgr { char pad0[0x4c]; Obj **objs; /* 0x4c objects by small id */ };
struct Ctx { int regs; int unk04; int unk08; Obj *actor; };
struct FacialCmd { void *vtbl; int unk04; int objId; int facial; int delay; };

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
void FUN_0014fd94(char *, int, int, int);
Obj *FUN_001c6f70(ObjMgr *, int, int);
Obj *FUN_001c70c0(ObjMgr *);
void FUN_00288350(Obj *, int, int);
}

/* Resolve the object the command refers to (same id scheme as the sibling commands). */
inline Obj *Find(FacialCmd *self, Ctx *ctx)
{
    Obj *actor = ctx->actor;
    int id = self->objId;
    if (id == OBJ_ID_PLAYER)
        return DAT_0034a118;
    if (id < 0)
        return actor;
    if (id < OBJ_ID_TABLE_END)
        return DAT_0034a114->objs[id];
    if (id < OBJ_ID_LOOKUP_END)
        return FUN_001c6f70(DAT_0034a114, id, 0);
    return FUN_001c70c0(DAT_0034a114);
}

/* Script command "SetFacial": set a facial expression on the object, with a delay. */
extern "C" int FUN_00154cc0(FacialCmd *self, Ctx *ctx)
{
    if (DAT_003402f0 != 0) {
        FUN_0014d044(ctx);
        FUN_0014fd94("SetFacial [%d, %d (delay:%d)]\n", self->objId, self->facial, self->delay);
    }
    Obj *obj = Find(self, ctx);
    if (obj != 0)
        FUN_00288350(obj, self->facial, self->delay);
    return 0;
}
