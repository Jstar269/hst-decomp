/* HSTMATCH module=EBOOT.BIN start=0x0014fbd4 end=0x0014fd94 symbol=FUN_0014fbd4 lang=c++ data=0x002dc374 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc374-0x002dc37f) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

/* Object ids of the "SetPos" command: -1 is the global player, other negatives mean the context object. */
enum { OBJ_ID_PLAYER = -1, OBJ_ID_TABLE_LIMIT = 100, OBJ_ID_LOOKUP_LIMIT = 1000 };

struct Mgr { char pad0[0x4c]; Obj **objs; };
struct Ctx { int unk0; int unk4; int unk8; Obj *obj; };
struct Cmd { void *vt; int unk4; int id; int posIndex; };
extern "C" {
extern unsigned char DAT_003402f0;
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
    if (id == OBJ_ID_PLAYER)
        return DAT_0034a118;
    if (id < 0)
        return obj;
    if (id < OBJ_ID_TABLE_LIMIT)
        return DAT_0034a114->objs[id];
    if (id < OBJ_ID_LOOKUP_LIMIT)
        return FUN_001c6f70(DAT_0034a114, id, 0);
    return FUN_001c70c0(DAT_0034a114);
}
extern "C" int FUN_0014fbd4(Cmd *self, Ctx *ctx)
{
    Vec4 pos;
    Vec4 rot;
    Vec4 axis;
    Vec4 defaultRot;
    Obj *target = Find(self, ctx);
    if (FUN_001caee4(DAT_0034a114, self->posIndex, &pos, &rot) == 0) {
        pos.x = DAT_002bc440[0];
        pos.y = DAT_002bc440[1];
        pos.z = DAT_002bc440[2];
        pos.w = DAT_002bc440[3];
        axis.x = 0.0f;
        axis.y = 0.0f;
        axis.z = 1.0f;
        axis.w = 0.0f;
        FUN_00022418(&defaultRot, DAT_002bc440, &axis);
        rot = defaultRot;
    }
    if (DAT_003402f0 != 0) {
        FUN_0014d044(ctx);
        FUN_0014fd94("SetPos:%d\n", self->id);
    }
    if (target != 0) {
        target->setPos(&pos);
        target->setRot(&rot);
    }
    return 0;
}
