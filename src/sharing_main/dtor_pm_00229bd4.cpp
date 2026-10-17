/* HSTMATCH module=hstp_trans_main.prx start=0x00229bd4 end=0x00229c5c symbol=__dt__10C_00229bd4Fv */
/* Clone of src/eboot/dtor_pm_0021a6bc.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Polymorphic class owning a polymorphic object at +0xe0: delete it through its virtual destructor and
   clear the pointer; the base destructor (0x102ea4) is out of line (template instance, hsttmpl.py tag t3).
   Names provisional. */
class Poly_00229bd4 { public: virtual ~Poly_00229bd4(); };
class B_001087a8 { public: virtual void key_001087a8(); virtual ~B_001087a8(); char pad[0xdc]; };
class C_00229bd4 : public B_001087a8 {
public:
    virtual void key_00229bd4();
    Poly_00229bd4 *obj;
    virtual ~C_00229bd4();
};
C_00229bd4::~C_00229bd4()
{
    if (obj) {
        delete obj;
        obj = 0;
    }
}
