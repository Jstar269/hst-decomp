/* HSTMATCH module=EBOOT.BIN start=0x0021f750 end=0x0021f7d8 symbol=__dt__10C_0021f750Fv */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Polymorphic class owning a polymorphic object at +0x8c: delete it through its virtual destructor and
   clear the pointer; the base destructor (0x102ea4) is out of line (template instance, hsttmpl.py tag t3).
   Names provisional. */
class Poly_0021f750 { public: virtual ~Poly_0021f750(); };
class B_00102ea4 { public: virtual void key_00102ea4(); virtual ~B_00102ea4(); char pad[0x88]; };
class C_0021f750 : public B_00102ea4 {
public:
    virtual void key_0021f750();
    Poly_0021f750 *obj;
    virtual ~C_0021f750();
};
C_0021f750::~C_0021f750()
{
    if (obj) {
        delete obj;
        obj = 0;
    }
}
