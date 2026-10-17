/* HSTMATCH module=hstp_trans_main.prx start=0x0027cd10 end=0x0027cd7c symbol=__dt__10C_0027cd10Fv */
/* Clone of src/eboot/dtor_00106634.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
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
    virtual ~C_0027cd10();
};
C_0027cd10::~C_0027cd10() {}
