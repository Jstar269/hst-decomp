/* HSTMATCH module=EBOOT.BIN start=0x001ea40c end=0x001ea468 symbol=__dt__10C_001ea40cFv */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
class B_00102ea4 {
public:
    virtual void key_b();
    virtual ~B_00102ea4();
};
class C_001ea40c : public B_00102ea4 {
public:
    virtual void key_c();
    virtual ~C_001ea40c();
};
C_001ea40c::~C_001ea40c() {}
