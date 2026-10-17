/* HSTMATCH module=hstp_trans_main.prx start=0x001fd110 end=0x001fd198 symbol=__dt__10C_001fd110Fv */
/* Clone of src/eboot/dtor_pm_001eed14.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Polymorphic class owning a polymorphic object at +0x90: delete it through its virtual destructor and
   clear the pointer; the base destructor (0x60e7c) is out of line (template instance, hsttmpl.py tag t3).
   Names provisional. */
class Poly_001fd110 { public: virtual ~Poly_001fd110(); };
class B_00061d00 { public: virtual void key_00061d00(); virtual ~B_00061d00(); char pad[0x8c]; };
class C_001fd110 : public B_00061d00 {
public:
    virtual void key_001fd110();
    Poly_001fd110 *obj;
    virtual ~C_001fd110();
};
C_001fd110::~C_001fd110()
{
    if (obj) {
        delete obj;
        obj = 0;
    }
}
