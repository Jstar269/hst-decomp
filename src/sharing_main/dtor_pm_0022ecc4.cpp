/* HSTMATCH module=hstp_trans_main.prx start=0x0022ecc4 end=0x0022ed4c symbol=__dt__10C_0022ecc4Fv */
/* Clone of src/eboot/dtor_pm_0021f750.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Polymorphic class owning a polymorphic object at +0x8c: delete it through its virtual destructor and
   clear the pointer; the base destructor (0x102ea4) is out of line (template instance, hsttmpl.py tag t3).
   Names provisional. */
class Poly_0022ecc4 { public: virtual ~Poly_0022ecc4(); };
class B_001087a8 { public: virtual void key_001087a8(); virtual ~B_001087a8(); char pad[0x88]; };
class C_0022ecc4 : public B_001087a8 {
public:
    virtual void key_0022ecc4();
    Poly_0022ecc4 *obj;
    virtual ~C_0022ecc4();
};
C_0022ecc4::~C_0022ecc4()
{
    if (obj) {
        delete obj;
        obj = 0;
    }
}
