/* HSTMATCH module=EBOOT.BIN start=0x0026bda4 end=0x0026beb8 symbol=__dt__10C_0026bda4Fv */
/* Clone of src/sharing_main/dtor_0027cd7c.cpp (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
class B_00102ea4 {
public:
    virtual void key_b();
    virtual ~B_00102ea4();
};
class M_00309380 : public B_00102ea4 {
public:
    virtual void key_m();
    virtual ~M_00309380() {}
};
class C_0027cd10 : public M_00309380 {
public:
    virtual void key_c();
    virtual ~C_0027cd10() {}
    char pad[0x10c - 4];
};
class C_0025e600 : public M_00309380 {
public:
    virtual void key_c();
    virtual ~C_0025e600();
    char pad[0x5e0 - 4];
};
class C_0026e6d0 : public M_00309380 {
public:
    virtual void key_c();
    virtual ~C_0026e6d0() {}
    char pad[0x3cc - 4];
};
class C_002744e8 : public M_00309380 {
public:
    virtual void key_c();
    virtual ~C_002744e8() {}
    char pad[0x8c - 4];
};
class C_0027cca4 : public M_00309380 {
public:
    virtual void key_c();
    virtual ~C_0027cca4() {}
};
class C_0026bda4 {
public:
    int f0;
    C_0027cd10 m4;
    C_0025e600 m110;
    C_0026e6d0 m6f0;
    C_002744e8 mabc;
    C_0027cca4 mb48;
    ~C_0026bda4();
};
C_0026bda4::~C_0026bda4() {}
