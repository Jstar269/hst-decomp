/* HSTMATCH module=hstp_trans_main.prx start=0x00233b74 end=0x00233bfc symbol=__dt__10C_00233b74Fv */
/* Clone of src/eboot/dtor_pm_00224600.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Polymorphic class owning a polymorphic object at +0x88: delete it through its virtual destructor and
   clear the pointer; the base destructor (0x102ea4) is out of line (template instance, hsttmpl.py tag t3).
   Names provisional. */
class Poly_00233b74 { public: virtual ~Poly_00233b74(); };
class B_001087a8 { public: virtual void key_001087a8(); virtual ~B_001087a8(); char pad[0x84]; };
class C_00233b74 : public B_001087a8 {
public:
    virtual void key_00233b74();
    Poly_00233b74 *obj;
    virtual ~C_00233b74();
};
C_00233b74::~C_00233b74()
{
    if (obj) {
        delete obj;
        obj = 0;
    }
}
