/* HSTMATCH module=EBOOT.BIN start=0x001da278 end=0x001da300 symbol=__dt__10C_001da278Fv */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Polymorphic class owning a polymorphic object at +0x3c: delete it through its virtual destructor and
   clear the pointer; the base destructor (0x1f0f0) is out of line (template instance, hsttmpl.py tag t3).
   Names provisional. */
class Poly_001da278 { public: virtual ~Poly_001da278(); };
class B_0001f0f0 { public: virtual void key_0001f0f0(); virtual ~B_0001f0f0(); char pad[0x38]; };
class C_001da278 : public B_0001f0f0 {
public:
    virtual void key_001da278();
    Poly_001da278 *obj;
    virtual ~C_001da278();
};
C_001da278::~C_001da278()
{
    if (obj) {
        delete obj;
        obj = 0;
    }
}
