/* HSTMATCH module=EBOOT.BIN start=0x001519b4 end=0x00151acc symbol=FUN_001519b4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Script command "SetVisible %d %s": optional trace hook and debug print (0x14d044, variadic stub 0x14fd94,
   on/off strings), then resolve the target object by id (-1: the global player converted to its Obj base at
   +0xe0, a derived-to-base null-checked add; negative: the context object, read up front; < 100: manager
   table at +0x4c; < 1000: lookup 0x1c6f70; else 0x1c70c0) in an inline helper with early returns, and copy
   the visible flag into it. Names provisional. */
struct Obj_001519b4 { char pad0[0x54]; unsigned char visible; };
struct PBase_001519b4 { char pad0[0xe0]; };
struct Player_001519b4 : PBase_001519b4, Obj_001519b4 {};
struct Mgr_001519b4 { char pad0[0x4c]; Obj_001519b4 **objs; };
struct Ctx_001519b4 { int a; int b; int c; Obj_001519b4 *obj; };
struct Cmd_001519b4 { void *vt; int a; int id; unsigned char visible; };
extern "C" {
extern unsigned char DAT_003402f0;
extern char DAT_002dc568[];
extern char DAT_002dc57c[];
extern char DAT_002dc580[];
extern Mgr_001519b4 *DAT_0034a114;
extern Player_001519b4 *DAT_0034a118;
void FUN_0014d044(Ctx_001519b4 *ctx);
void FUN_0014fd94(char *fmt, ...);
Obj_001519b4 *FUN_001c6f70(Mgr_001519b4 *m, int id, int z);
Obj_001519b4 *FUN_001c70c0(Mgr_001519b4 *m, int id);
}
inline Obj_001519b4 *Find_001519b4(int id, Ctx_001519b4 *ctx)
{
    Obj_001519b4 *obj = ctx->obj;
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
extern "C" int FUN_001519b4(Cmd_001519b4 *self, Ctx_001519b4 *ctx)
{
    if (DAT_003402f0) {
        FUN_0014d044(ctx);
        FUN_0014fd94(DAT_002dc568, self->id, self->visible ? DAT_002dc57c : DAT_002dc580);
    }
    Obj_001519b4 *obj = Find_001519b4(self->id, ctx);
    if (obj)
        obj->visible = self->visible;
    return 0;
}
