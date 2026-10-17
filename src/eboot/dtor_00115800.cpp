/* HSTMATCH module=EBOOT.BIN start=0x00115800 end=0x0011587c symbol=__dt__10C_00115800Fv */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Deleting destructor of a polymorphic class three levels above B_00100b24: C (vtable 0x307bf8) :
   X (vtable 0x307a90) : M (vtable 0x30779c) : B (out-of-line destructor 0x100b24). Each inlined implicit
   base destructor stores its vtable behind its own `if (this)`; the key_* virtuals keep the vtables out
   of this unit. Same shape as src/eboot/dtor_00106634.cpp with one more layer. Names provisional. */
class B_00100b24 {
public:
    virtual void key_b();
    virtual ~B_00100b24();
};
class M_0030779c : public B_00100b24 {
public:
    virtual void key_m();
    virtual ~M_0030779c() {}
};
class X_00307a90 : public M_0030779c {
public:
    virtual void key_x();
    virtual ~X_00307a90() {}
};
class C_00115800 : public X_00307a90 {
public:
    virtual void key_c();
    virtual ~C_00115800();
};
C_00115800::~C_00115800() {}
// EXACT with two vtable symbols that are not in symbols/EBOOT.BIN.txt yet (verified with
// `hstmatch.py --symbols-extra` holding exactly these lines):
//   __vt__10C_00115800 = 0x00307bf8;
//   __vt__10X_00307a90 = 0x00307a90;
// Family: 0x11587c (C vtable 0x307c3c, X vtable 0x307a08), 0x115afc (C vtable 0x307df4, X vtable 0x307a08).
// Move to src/eboot/ once the symbols are added.
