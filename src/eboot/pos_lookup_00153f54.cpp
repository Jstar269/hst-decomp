/* HSTMATCH module=EBOOT.BIN start=0x00153f54 end=0x0015405c symbol=FUN_00153f54 lang=c++ data=0x002dc838 */
/* Hand-written reconstruction from the disassembly; exact match verified (id->object lookup in an inline helper with early returns, as in 0x0014fbd4/0x001543d0; names and types await human review). Data: its string literals (1 strings, 0x002dc838-0x002dc84e) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */

/* Ids below TARGET_TABLE_END index the host's object table; larger ones are looked up. */
enum {
    TARGET_ID_GLOBAL = -1,      /* the global object */
    TARGET_TABLE_END = 100,
    TARGET_LOOKUP_END = 1000
};
struct Target {
    virtual void v0();
    char pad4[0x4c];
    float talk_dist;    /* 0x50 */
};
struct TargetBase { char pad0[0xe0]; };
struct GlobalTarget : TargetBase, Target {};
struct Host { char pad0[0x4c]; Target **objs; };
struct Ctx { int a; int b; int c; Target *actor; };
struct Cmd { void *vt; int a; int id; float dist; };
extern "C" {
extern unsigned char DAT_003402f0; /* script trace flag */
extern Host *DAT_0034a114;
extern GlobalTarget *DAT_0034a118;
void FUN_0014d044(Ctx *);
void FUN_0014fd94(char *, int, long long);
long long FUN_00020f5c(float);
Target *FUN_001c6f70(Host *, int, int);
Target *FUN_001c70c0(Host *);
}
/* Resolve the command's target id to an object: global, the running actor, a table entry or a lookup. */
inline Target *Find(Cmd *self, Ctx *ctx)
{
    Target *actor = ctx->actor;
    int id = self->id;
    if (id == TARGET_ID_GLOBAL)
        return DAT_0034a118;
    if (id < 0)
        return actor;
    if (id < TARGET_TABLE_END)
        return DAT_0034a114->objs[id];
    if (id < TARGET_LOOKUP_END)
        return FUN_001c6f70(DAT_0034a114, id, 0);
    return FUN_001c70c0(DAT_0034a114);
}
/* Script command "SetTalkDist": set the talk distance of the target object. */
extern "C" int FUN_00153f54(Cmd *self, Ctx *ctx)
{
    if (DAT_003402f0 != 0) {
        FUN_0014d044(ctx);
        FUN_0014fd94("SetTalkDist[%d:%.3f]\n", self->id, FUN_00020f5c(self->dist));
    }
    Target *target = Find(self, ctx);
    if (target != 0)
        target->talk_dist = self->dist;
    return 0;
}
