/* HSTMATCH module=hstp_trans_main.prx start=0x002b53a8 end=0x002b5430 symbol=__dt__10C_002b53a8Fv */
/* Clone of src/eboot/dtor_pm_002a5c18.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Polymorphic class owning a polymorphic object at +0x1700: delete it through its virtual destructor and
   clear the pointer; the base destructor (0x102ea4) is out of line (template instance, hsttmpl.py tag t3).
   Names provisional. */
class Poly_002b53a8 { public: virtual ~Poly_002b53a8(); };
class B_001087a8 { public: virtual void key_001087a8(); virtual ~B_001087a8(); char pad[0x16fc]; };
class C_002b53a8 : public B_001087a8 {
public:
    virtual void key_002b53a8();
    Poly_002b53a8 *obj;
    virtual ~C_002b53a8();
};
C_002b53a8::~C_002b53a8()
{
    if (obj) {
        delete obj;
        obj = 0;
    }
}
