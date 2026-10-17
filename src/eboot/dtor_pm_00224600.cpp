/* HSTMATCH module=EBOOT.BIN start=0x00224600 end=0x00224688 symbol=__dt__10C_00224600Fv */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Polymorphic class owning a polymorphic object at +0x88: delete it through its virtual destructor and
   clear the pointer; the base destructor (0x102ea4) is out of line (template instance, hsttmpl.py tag t3).
   Names provisional. */
class Poly_00224600 { public: virtual ~Poly_00224600(); };
class B_00102ea4 { public: virtual void key_00102ea4(); virtual ~B_00102ea4(); char pad[0x84]; };
class C_00224600 : public B_00102ea4 {
public:
    virtual void key_00224600();
    Poly_00224600 *obj;
    virtual ~C_00224600();
};
C_00224600::~C_00224600()
{
    if (obj) {
        delete obj;
        obj = 0;
    }
}
