/* HSTMATCH module=EBOOT.BIN start=0x001543d0 end=0x001544ec symbol=FUN_001543d0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified (id->object lookup in an inline helper with early returns, as in 0x0014fbd4; names and types await human review). */
struct Obj {
    virtual void v0();
};
struct PBase { char pad0[0xe0]; };
struct Player : PBase, Obj {};
struct Mgr { char pad0[0x4c]; Obj **objs; };
struct Ctx { int a; int b; int c; Obj *obj; };
struct Cmd { void *vt; int a; int id; int pos; };
extern "C" {
extern unsigned char DAT_003402f0;
extern char DAT_002dc8c4[];
extern Mgr *DAT_0034a114;
extern Player *DAT_0034a118;
void FUN_0014d044(Ctx *);
void FUN_0014fd94(char *, int, int);
Obj *FUN_001c6f70(Mgr *, int, int);
Obj *FUN_001c70c0(Mgr *, int);
void FUN_00293764(Obj *, Obj *);
}
inline Obj *Find(Cmd *self, Ctx *ctx)
{
    Obj *obj = ctx->obj;
    int id = self->pos;
    if (id == -1)
        return DAT_0034a118;
    if (id < 0)
        return obj;
    if (id < 100)
        return DAT_0034a114->objs[id];
    if (id < 1000)
        return FUN_001c6f70(DAT_0034a114, id, 0);
    return FUN_001c70c0(DAT_0034a114, id);
}
extern "C" int FUN_001543d0(Cmd *self, Ctx *ctx)
{
    if (DAT_003402f0 != 0) {
        FUN_0014d044(ctx);
        FUN_0014fd94(DAT_002dc8c4, self->id, self->pos);
    }
    Obj *p = Find(self, ctx);
    Obj *cur = FUN_001c70c0(DAT_0034a114, self->id);
    if (cur != 0 && p != 0)
        FUN_00293764(cur, p);
    return 0;
}
