/* HSTMATCH module=hstp_trans_main.prx start=0x00161694 end=0x00161718 symbol=FUN_00161694 lang=c++ */
/* Clone of src/eboot/obj_report_001550c0.cpp (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* The first callee is declared (void *, int, float, int): that parameter order schedules the argument loads like retail (float load first, lw a1 in the jal delay slot); the print stub is variadic and the float is widened with (double) (__extendsfdf2). */
struct Ctx { int pad0; int pad4; int pad8; void *p; };
struct Obj { int pad0; int pad4; float f; int b; int c; };
extern "C" void FUN_00299d10(void *, int, float, int);
extern "C" void FUN_00158b2c(Ctx *);
extern "C" void FUN_0015bb68(const char *, ...);
extern unsigned char DAT_003e9630;
extern char DAT_00383f58[];
extern "C" int FUN_00161694(Obj *o, Ctx *c)
{
    if (c->p != 0)
        FUN_00299d10(c->p, o->c, o->f, o->b);
    if (DAT_003e9630 != 0) {
        FUN_00158b2c(c);
        FUN_0015bb68(DAT_00383f58, o->c, (double)o->f, o->b);
    }
    return 0;
}
