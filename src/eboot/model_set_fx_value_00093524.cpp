/* HSTMATCH module=EBOOT.BIN start=0x00093524 end=0x000935b0 symbol=FUN_00093524 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Effect { char pad0[0xc4]; float mc4; };
struct Model { char pad0[0x50]; Effect *m50; char pad54[4]; Effect *m58; char pad5c[8]; Effect *m64; };
extern "C" void FUN_00058ec4(Effect *, float, int);
extern "C" void FUN_00093524(Model *m, float f)
{
    Effect *e = m->m58;
    if (e) {
        FUN_00058ec4(e, f, -1);
        e->mc4 = f;
    }
    e = m->m50;
    if (e) {
        FUN_00058ec4(e, f, -1);
        e->mc4 = f;
    }
    e = m->m64;
    if (e) {
        FUN_00058ec4(e, f, -1);
        e->mc4 = f;
    }
}
