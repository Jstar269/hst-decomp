/* HSTMATCH module=EBOOT.BIN start=0x002a55f8 end=0x002a5680 symbol=__dt__10C_002a55f8Fv */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Polymorphic class owning a polymorphic object at +0x54: delete it through its virtual destructor and
   clear the pointer; the base destructor (0x102ea4) is out of line (template instance, hsttmpl.py tag t3).
   Names provisional. */
class Poly_002a55f8 { public: virtual ~Poly_002a55f8(); };
class B_00102ea4 { public: virtual void key_00102ea4(); virtual ~B_00102ea4(); char pad[0x50]; };
class C_002a55f8 : public B_00102ea4 {
public:
    virtual void key_002a55f8();
    Poly_002a55f8 *obj;
    virtual ~C_002a55f8();
};
C_002a55f8::~C_002a55f8()
{
    if (obj) {
        delete obj;
        obj = 0;
    }
}
