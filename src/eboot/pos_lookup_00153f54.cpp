/* HSTMATCH module=EBOOT.BIN start=0x00153f54 end=0x0015405c symbol=FUN_00153f54 lang=c++ data=0x002dc838 */
/* Hand-written reconstruction from the disassembly; exact match verified (id->object lookup in an inline helper with early returns, as in 0x0014fbd4/0x001543d0; names and types await human review). Data: its string literals (1 strings, 0x002dc838-0x002dc84e) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
struct Obj {
    virtual void v0();
    char pad4[0x4c];
    float f50;
};
struct PBase { char pad0[0xe0]; };
struct Player : PBase, Obj {};
struct Mgr { char pad0[0x4c]; Obj **objs; };
struct Ctx { int a; int b; int c; Obj *obj; };
struct Cmd { void *vt; int a; int id; float pos; };
extern "C" {
extern unsigned char DAT_003402f0;
extern Mgr *DAT_0034a114;
extern Player *DAT_0034a118;
void FUN_0014d044(Ctx *);
void FUN_0014fd94(char *, int, long long);
long long FUN_00020f5c(float);
Obj *FUN_001c6f70(Mgr *, int, int);
Obj *FUN_001c70c0(Mgr *);
}
inline Obj *Find(Cmd *self, Ctx *ctx)
{
    Obj *obj = ctx->obj;
    int id = self->id;
    if (id == -1)
        return DAT_0034a118;
    if (id < 0)
        return obj;
    if (id < 100)
        return DAT_0034a114->objs[id];
    if (id < 1000)
        return FUN_001c6f70(DAT_0034a114, id, 0);
    return FUN_001c70c0(DAT_0034a114);
}
extern "C" int FUN_00153f54(Cmd *self, Ctx *ctx)
{
    if (DAT_003402f0 != 0) {
        FUN_0014d044(ctx);
        FUN_0014fd94("SetTalkDist[%d:%.3f]\n", self->id, FUN_00020f5c(self->pos));
    }
    Obj *p = Find(self, ctx);
    if (p != 0)
        p->f50 = self->pos;
    return 0;
}
