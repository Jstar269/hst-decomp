/* HSTMATCH module=EBOOT.BIN start=0x001eed14 end=0x001eed9c symbol=__dt__10C_001eed14Fv */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Polymorphic class owning a polymorphic object at +0x90: delete it through its virtual destructor and
   clear the pointer; the base destructor (0x60e7c) is out of line (template instance, hsttmpl.py tag t3).
   Names provisional. */
class Poly_001eed14 { public: virtual ~Poly_001eed14(); };
class B_00060e7c { public: virtual void key_00060e7c(); virtual ~B_00060e7c(); char pad[0x8c]; };
class C_001eed14 : public B_00060e7c {
public:
    virtual void key_001eed14();
    Poly_001eed14 *obj;
    virtual ~C_001eed14();
};
C_001eed14::~C_001eed14()
{
    if (obj) {
        delete obj;
        obj = 0;
    }
}
