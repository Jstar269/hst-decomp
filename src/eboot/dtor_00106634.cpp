/* HSTMATCH module=EBOOT.BIN start=0x00106634 end=0x001066a0 symbol=__dt__10C_00106634Fv */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
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
class C_00106634 : public M_0030779c {
public:
    virtual void key_c();
    virtual ~C_00106634();
};
C_00106634::~C_00106634() {}
