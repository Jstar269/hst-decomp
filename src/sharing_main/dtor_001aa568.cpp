/* HSTMATCH module=hstp_trans_main.prx start=0x001aa568 end=0x001aa678 symbol=__dt__10C_001aa568Fv */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Real C++ destructor: the class (vtable 0x3b24fc) derives from B_001087a8 and owns an array of
   polymorphic 0x48-byte objects (delete[] -> __destroy_new_array with their dtor 0x519d4), a polymorphic
   object at +0x8c (virtual deleting dtor), a member at +0x68 (base with dtor 0x4138 plus a member with
   dtor 0x463a0, destroyed with flag -1) and a polymorphic member at +0xa0 (vtable 0x3b2538, inline dtor
   over B_001087a8); the body first calls three routines on the global DAT_003eaad8. MWCC generates the
   vptr store, the per-member `if (this)` tests, the base dtor call and the deleting tail. key_*() keep
   the vtables out of this unit. Class names are address placeholders. */
class B_001087a8 {
public:
    virtual void key_b();
    virtual ~B_001087a8();
    char pad4[0x50];
};

class B_00004138 {
public:
    ~B_00004138();
    char pad0[0xc];
};

class S_000463a0 {
public:
    ~S_000463a0();
    unsigned flags;
    int f4;
    char *p8;
};

class M68_001aa568 : public B_00004138 {
public:
    S_000463a0 name;
};

class M_003b2538 : public B_001087a8 {
public:
    virtual void key_m();
    virtual ~M_003b2538() {}
};

class E_000519d4 {
public:
    virtual ~E_000519d4();
    char pad4[0x44];
};

class VC_0 {
public:
    virtual ~VC_0();
};

extern "C" {
extern char DAT_003eaad8[];
void FUN_001c20b8(char *);
void FUN_001c170c(char *, int);
void FUN_001c0da0(char *);
}

class C_001aa568 : public B_001087a8 {
public:
    virtual void key_c();
    virtual ~C_001aa568();
    E_000519d4 *items;
    char pad58[0x68 - 0x58];
    M68_001aa568 m68;
    char pad80[0x8c - 0x80];
    VC_0 *obj;
    char pad90[0xa0 - 0x90];
    M_003b2538 sub;
};

C_001aa568::~C_001aa568()
{
    FUN_001c20b8(DAT_003eaad8);
    FUN_001c170c(DAT_003eaad8, 13);
    FUN_001c0da0(DAT_003eaad8);
    if (obj) {
        delete obj;
        obj = 0;
    }
    if (items) {
        delete[] items;
        items = 0;
    }
}
