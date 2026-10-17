/* HSTMATCH module=hstp_trans_main.prx start=0x001e835c end=0x001e83e4 symbol=__dt__10C_001e835cFv */
/* Clone of src/eboot/dtor_pm_001da278.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Polymorphic class owning a polymorphic object at +0x3c: delete it through its virtual destructor and
   clear the pointer; the base destructor (0x1f0f0) is out of line (template instance, hsttmpl.py tag t3).
   Names provisional. */
class Poly_001e835c { public: virtual ~Poly_001e835c(); };
class B_0001ed28 { public: virtual void key_0001ed28(); virtual ~B_0001ed28(); char pad[0x38]; };
class C_001e835c : public B_0001ed28 {
public:
    virtual void key_001e835c();
    Poly_001e835c *obj;
    virtual ~C_001e835c();
};
C_001e835c::~C_001e835c()
{
    if (obj) {
        delete obj;
        obj = 0;
    }
}
