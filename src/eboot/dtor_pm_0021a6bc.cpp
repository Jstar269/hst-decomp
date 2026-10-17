/* HSTMATCH module=EBOOT.BIN start=0x0021a6bc end=0x0021a744 symbol=__dt__10C_0021a6bcFv */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Polymorphic class owning a polymorphic object at +0xe0: delete it through its virtual destructor and
   clear the pointer; the base destructor (0x102ea4) is out of line (template instance, hsttmpl.py tag t3).
   Names provisional. */
class Poly_0021a6bc { public: virtual ~Poly_0021a6bc(); };
class B_00102ea4 { public: virtual void key_00102ea4(); virtual ~B_00102ea4(); char pad[0xdc]; };
class C_0021a6bc : public B_00102ea4 {
public:
    virtual void key_0021a6bc();
    Poly_0021a6bc *obj;
    virtual ~C_0021a6bc();
};
C_0021a6bc::~C_0021a6bc()
{
    if (obj) {
        delete obj;
        obj = 0;
    }
}
