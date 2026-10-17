/* HSTMATCH module=hstp_trans_main.prx start=0x00120a18 end=0x00120a94 symbol=__dt__10C_00120a18Fv */
/* Clone of src/eboot/dtor_00115800.cpp (hstclone.py tag c37): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Deleting destructor of a polymorphic class three levels above B_0010642c: C (vtable 0x3b10c0) :
   X (vtable 0x3b0cd4) : M (vtable 0x3b0a68) : B (out-of-line destructor 0x100b24). Each inlined implicit
   base destructor stores its vtable behind its own `if (this)`; the key_* virtuals keep the vtables out
   of this unit. Same shape as src/eboot/dtor_00106634.cpp with one more layer. Names provisional. */
class B_0010642c {
public:
    virtual void key_b();
    virtual ~B_0010642c();
};
class M_003b0a68 : public B_0010642c {
public:
    virtual void key_m();
    virtual ~M_003b0a68() {}
};
class X_003b0cd4 : public M_003b0a68 {
public:
    virtual void key_x();
    virtual ~X_003b0cd4() {}
};
class C_00120a18 : public X_003b0cd4 {
public:
    virtual void key_c();
    virtual ~C_00120a18();
};
C_00120a18::~C_00120a18() {}
// EXACT with two vtable symbols that are not in symbols/EBOOT.BIN.txt yet (verified with
// `hstmatch.py --symbols-extra` holding exactly these lines):
//   __vt__10C_00120a18 = 0x3b10c0;
//   __vt__10X_00307a90 = 0x3b0cd4;
// Family: 0x11587c (C vtable 0x3b7c3c, X vtable 0x3b7a08), 0x115afc (C vtable 0x3b7df4, X vtable 0x3b7a08).
// Move to src/eboot/ once the symbols are added.
