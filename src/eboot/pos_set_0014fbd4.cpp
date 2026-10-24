/* HSTMATCH module=EBOOT.BIN start=0x0014fbd4 end=0x0014fd94 symbol=FUN_0014fbd4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Script command: resolve the target object by id in an inline helper with early returns (-1: global player converted to its Obj base at +0xe0, negative: context object read up front, < 100: manager table at +0x4c, < 1000: 0x1c6f70, else 0x1c70c0), fetch its position/rotation via 0x1caee4 (default: DAT_002bc440 and the rotation from 0x22418 with axis 0,0,1), optional trace print, then call vtable slots 0x1c (pos) and 0x24 (rot). Names provisional. */
struct Vec4 {
    float x, y, z, w;
};

struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setPos(Vec4 *);
    virtual void v6();
    virtual void setRot(Vec4 *);
};
struct PBase { char pad0[0xe0]; };
struct Player : PBase, Obj {};
struct Mgr { char pad0[0x4c]; Obj **objs; };
struct Ctx { int a; int b; int c; Obj *obj; };
struct Cmd { void *vt; int a; int id; int pos; };
extern "C" {
extern unsigned char DAT_003402f0;
extern char DAT_002dc374[];
extern Mgr *DAT_0034a114;
extern Player *DAT_0034a118;
extern float DAT_002bc440[4];
int FUN_001caee4(Mgr *, int, Vec4 *, Vec4 *);
void FUN_00022418(Vec4 *, float *, Vec4 *);
void FUN_0014d044(Ctx *);
void FUN_0014fd94(char *, int);
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
extern "C" int FUN_0014fbd4(Cmd *self, Ctx *ctx)
{
    Vec4 d;
    Vec4 c;
    Vec4 b;
    Vec4 a;
    Obj *p = Find(self, ctx);
    if (FUN_001caee4(DAT_0034a114, self->pos, &d, &c) == 0) {
        d.x = DAT_002bc440[0];
        d.y = DAT_002bc440[1];
        d.z = DAT_002bc440[2];
        d.w = DAT_002bc440[3];
        b.x = 0.0f;
        b.y = 0.0f;
        b.z = 1.0f;
        b.w = 0.0f;
        FUN_00022418(&a, DAT_002bc440, &b);
        c = a;
    }
    if (DAT_003402f0 != 0) {
        FUN_0014d044(ctx);
        FUN_0014fd94(DAT_002dc374, self->id);
    }
    if (p != 0) {
        p->setPos(&d);
        p->setRot(&c);
    }
    return 0;
}
