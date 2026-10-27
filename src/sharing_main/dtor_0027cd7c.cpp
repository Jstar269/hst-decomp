/* HSTMATCH module=hstp_trans_main.prx start=0x0027cd7c end=0x0027ce90 symbol=__dt__10C_0027cd7cFv */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
class B_001087a8 {
public:
    virtual void key_b();
    virtual ~B_001087a8();
};
class M_003b264c : public B_001087a8 {
public:
    virtual void key_m();
    virtual ~M_003b264c() {}
};
class C_0027cd10 : public M_003b264c {
public:
    virtual void key_c();
    virtual ~C_0027cd10() {}
    char pad[0x10c - 4];
};
class C_0026f428 : public M_003b264c {
public:
    virtual void key_c();
    virtual ~C_0026f428();
    char pad[0x5e0 - 4];
};
class C_0026e6d0 : public M_003b264c {
public:
    virtual void key_c();
    virtual ~C_0026e6d0() {}
    char pad[0x3cc - 4];
};
class C_002744e8 : public M_003b264c {
public:
    virtual void key_c();
    virtual ~C_002744e8() {}
    char pad[0x8c - 4];
};
class C_0027cca4 : public M_003b264c {
public:
    virtual void key_c();
    virtual ~C_0027cca4() {}
};
class C_0027cd7c {
public:
    int f0;
    C_0027cd10 m4;
    C_0026f428 m110;
    C_0026e6d0 m6f0;
    C_002744e8 mabc;
    C_0027cca4 mb48;
    ~C_0027cd7c();
};
C_0027cd7c::~C_0027cd7c() {}
