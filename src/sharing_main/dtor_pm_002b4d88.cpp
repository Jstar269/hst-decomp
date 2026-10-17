/* HSTMATCH module=hstp_trans_main.prx start=0x002b4d88 end=0x002b4e10 symbol=__dt__10C_002b4d88Fv */
/* Clone of src/eboot/dtor_pm_002a55f8.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Polymorphic class owning a polymorphic object at +0x54: delete it through its virtual destructor and
   clear the pointer; the base destructor (0x102ea4) is out of line (template instance, hsttmpl.py tag t3).
   Names provisional. */
class Poly_002b4d88 { public: virtual ~Poly_002b4d88(); };
class B_001087a8 { public: virtual void key_001087a8(); virtual ~B_001087a8(); char pad[0x50]; };
class C_002b4d88 : public B_001087a8 {
public:
    virtual void key_002b4d88();
    Poly_002b4d88 *obj;
    virtual ~C_002b4d88();
};
C_002b4d88::~C_002b4d88()
{
    if (obj) {
        delete obj;
        obj = 0;
    }
}
