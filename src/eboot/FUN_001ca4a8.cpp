/* HSTMATCH module=EBOOT.BIN start=0x001ca4a8 end=0x001ca60c symbol=FUN_001ca4a8 lang=c++ data=0x002eaa48 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002eaa48-0x002eaa50) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/event_owner.h"

extern "C" {
extern int *DAT_0034a118;
extern char DAT_0034179c[];
extern void FUN_001b2430(char *);
extern void FUN_00288828(int, int, int);
extern void FUN_00022434(float *, float *, float *);
extern void FUN_00048f08(float *, float *);
extern void FUN_00022498(float *, float *, float);
extern void FUN_00022418(float *, float *, float *);
extern void FUN_001cc7d0(int, char *);
}

struct ObjEvent {
    virtual void o0();
    virtual void o1();
    virtual void o2();
    virtual void o3();
    virtual void o4();
    virtual void setVec(float *);
    virtual void o6();
    virtual void setMat(int);
    virtual void o8();
    virtual void o9();
    virtual void o10();
    virtual void o11();
    virtual void o12();
    virtual void o13();
    virtual void o14();
    virtual void o15();
    virtual void o16();
    virtual void o17();
    virtual void o18();
    virtual void o19();
    virtual void end();
};

struct Singleton {
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual void q3();
    virtual void q4();
    virtual void q5();
    virtual void q6();
    virtual void q7();
    virtual void q8();
    virtual void q9();
    virtual void q10();
    virtual void q11();
    virtual void q12();
    virtual void q13();
    virtual void q14();
    virtual void q15();
    virtual void q16();
    virtual void q17();
    virtual void q18();
    virtual void q19();
    virtual void q20();
    virtual void q21();
    virtual void q22();
    virtual void q23();
    virtual void q24();
    virtual void q25();
    virtual void q26();
    virtual void q27();
    virtual void q28();
    virtual void q29();
    virtual void q30();
    virtual void q31();
    virtual void q32();
    virtual void q33();
    virtual void q34();
    virtual void q35();
    virtual void q36();
    virtual float *get();
};

/* Look up the event object for the last slot, hand it a vector and the transform data, then end it. */
extern "C" void FUN_001ca4a8(EventOwner *self)
{
    int slot = self->unk50 - 1;
    float v[4];
    float w[4];
    float u[4];
    float y[4];
    float t[4];
    float z[4];
    float *p;

    FUN_001b2430(DAT_0034179c);
    FUN_00288828(slot, self->unkc0, 1001);
    self->current = self->table[slot];
    p = ((Singleton *)DAT_0034a118)->get();
    v[0] = p[0];
    v[1] = p[1];
    v[2] = p[2];
    v[3] = p[3];
    FUN_00022434(t, self->unka0, v);
    u[0] = t[0];
    u[1] = t[1];
    u[2] = t[2];
    u[3] = t[3];
    FUN_00048f08(w, u);
    FUN_00022498(z, w, 0.5f);
    y[0] = z[0];
    y[1] = z[1];
    y[2] = z[2];
    y[3] = z[3];
    FUN_00022418(v, v, y);
    ((ObjEvent *)self->current)->setVec(v);
    ((ObjEvent *)self->current)->setMat((int)self->unka0);
    ((ObjEvent *)self->current)->end();
    FUN_001cc7d0((int)self, "event98");
}
// EXACT (89/89 words). The last delta was the argument setup order for FUN_00022434: retail
// materialises a0 (sp+0x20) before a1 (s0+0xa0). It only flips when the second argument is a
// FLOAT pointer (the float array member `self->unka0`) with the callee declared
// `(float *, float *, float *)`. The same call with an int middle parameter emits a1 first and
// stays 2 words off.
// Facts: the DAT_0034a118 virtual call and the 0x98-object calls MUST be C++ virtual dispatch --
// MWCC then loads through t9 (`lw t9,0(a0); lw t9,0x9c(t9); jalr t9`), which is what retail does;
// a C function-pointer call emits `lw v0,slot; jalr v0` instead. The vtable in this build has two
// header slots, so a method at vtable offset 0x1c is declared as the SIXTH virtual (index 5),
// 0x24 as index 7 and 0x58 as index 20; the 0x9c slot is index 37. Virtuals take only their
// explicit parameters (this is implicit): setVec(float*), setMat(int), end().
