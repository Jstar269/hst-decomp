/* HSTMATCH module=EBOOT.BIN start=0x000f355c end=0x000f35e4 symbol=__dt__10C_000f355cFv */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Polymorphic class owning a polymorphic object at +0x1b8: delete it through its virtual destructor and
   clear the pointer; the base destructor (0x102ea4) is out of line (template instance, hsttmpl.py tag t3).
   Names provisional. */
class Poly_000f355c { public: virtual ~Poly_000f355c(); };
class B_00102ea4 { public: virtual void key_00102ea4(); virtual ~B_00102ea4(); char pad[0x1b4]; };
class C_000f355c : public B_00102ea4 {
public:
    virtual void key_000f355c();
    Poly_000f355c *obj;
    virtual ~C_000f355c();
};
C_000f355c::~C_000f355c()
{
    if (obj) {
        delete obj;
        obj = 0;
    }
}
