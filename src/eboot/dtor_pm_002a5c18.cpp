/* HSTMATCH module=EBOOT.BIN start=0x002a5c18 end=0x002a5ca0 symbol=__dt__10C_002a5c18Fv */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Polymorphic class owning a polymorphic object at +0x1700: delete it through its virtual destructor and
   clear the pointer; the base destructor (0x102ea4) is out of line (template instance, hsttmpl.py tag t3).
   Names provisional. */
class Poly_002a5c18 { public: virtual ~Poly_002a5c18(); };
class B_00102ea4 { public: virtual void key_00102ea4(); virtual ~B_00102ea4(); char pad[0x16fc]; };
class C_002a5c18 : public B_00102ea4 {
public:
    virtual void key_002a5c18();
    Poly_002a5c18 *obj;
    virtual ~C_002a5c18();
};
C_002a5c18::~C_002a5c18()
{
    if (obj) {
        delete obj;
        obj = 0;
    }
}
