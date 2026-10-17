/* HSTMATCH module=EBOOT.BIN start=0x001551c4 end=0x00155248 symbol=FUN_001551c4 lang=c++ */
/* Clone of src/eboot/obj_report_001550c0.cpp (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* The first callee is declared (void *, int, float, int): that parameter order schedules the argument loads like retail (float load first, lw a1 in the jal delay slot); the print stub is variadic and the float is widened with (double) (__extendsfdf2). */
struct Ctx { int pad0; int pad4; int pad8; void *p; };
struct Obj { int pad0; int pad4; float f; int b; int c; };
extern "C" void FUN_002885dc(void *, int, float, int);
extern "C" void FUN_0014d044(Ctx *);
extern "C" void FUN_0014fd94(const char *, ...);
extern unsigned char DAT_003402f0;
extern char DAT_002dca70[];
extern "C" int FUN_001551c4(Obj *o, Ctx *c)
{
    if (c->p != 0)
        FUN_002885dc(c->p, o->c, o->f, o->b);
    if (DAT_003402f0 != 0) {
        FUN_0014d044(c);
        FUN_0014fd94(DAT_002dca70, o->c, (double)o->f, o->b);
    }
    return 0;
}
