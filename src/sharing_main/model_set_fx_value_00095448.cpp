/* HSTMATCH module=hstp_trans_main.prx start=0x00095448 end=0x000954d4 symbol=FUN_00095448 lang=c++ */
/* Clone of src/eboot/model_set_fx_value_00093524.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Effect { char pad0[0xc4]; float mc4; };
struct Model { char pad0[0x50]; Effect *m50; char pad54[4]; Effect *m58; char pad5c[8]; Effect *m64; };
extern "C" void FUN_00059ba8(Effect *, float, int);
extern "C" void FUN_00095448(Model *m, float f)
{
    Effect *e = m->m58;
    if (e) {
        FUN_00059ba8(e, f, -1);
        e->mc4 = f;
    }
    e = m->m50;
    if (e) {
        FUN_00059ba8(e, f, -1);
        e->mc4 = f;
    }
    e = m->m64;
    if (e) {
        FUN_00059ba8(e, f, -1);
        e->mc4 = f;
    }
}
