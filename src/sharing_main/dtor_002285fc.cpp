/* HSTMATCH module=hstp_trans_main.prx start=0x002285fc end=0x00228668 symbol=__dt__10C_002285fcFv */
/* Clone of src/eboot/dtor_00106634.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
class B_0005b0f4 {
public:
    virtual void key_b();
    virtual ~B_0005b0f4();
};
class M_003b02f8 : public B_0005b0f4 {
public:
    virtual void key_m();
    virtual ~M_003b02f8() {}
};
class C_002285fc : public M_003b02f8 {
public:
    virtual void key_c();
    virtual ~C_002285fc();
};
C_002285fc::~C_002285fc() {}
