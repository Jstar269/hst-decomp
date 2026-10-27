/* HSTMATCH module=hstp_trans_main.prx start=0x00161590 end=0x00161614 symbol=FUN_00161590 lang=c++ data=0x00383f40 */
/* Clone of src/eboot/obj_report_001550c0.cpp (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00383f40-0x00383f57) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* The first callee is declared (void *, int, float, int): that parameter order schedules the argument loads like retail (float load first, lw a1 in the jal delay slot); the print stub is variadic and the float is widened with (double) (__extendsfdf2). */
struct Ctx { int pad0; int pad4; int pad8; void *p; };
struct Obj { int pad0; int pad4; float f; int b; int c; };
extern "C" void FUN_00299cc8(void *, int, float, int);
extern "C" void FUN_00158b2c(Ctx *);
extern "C" void FUN_0015bb68(const char *, ...);
extern unsigned char DAT_003e9630;
extern "C" int FUN_00161590(Obj *o, Ctx *c)
{
    if (c->p != 0)
        FUN_00299cc8(c->p, o->c, o->f, o->b);
    if (DAT_003e9630 != 0) {
        FUN_00158b2c(c);
        FUN_0015bb68("SeVolume [%s:%.3f:%d]\n", o->c, (double)o->f, o->b);
    }
    return 0;
}
