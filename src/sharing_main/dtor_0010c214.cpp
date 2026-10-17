/* HSTMATCH module=hstp_trans_main.prx start=0x0010c214 end=0x0010c280 symbol=__dt__10C_0010c214Fv */
/* Clone of src/eboot/dtor_00106634.cpp (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
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
class C_0010c214 : public M_003b0a68 {
public:
    virtual void key_c();
    virtual ~C_0010c214();
};
C_0010c214::~C_0010c214() {}
