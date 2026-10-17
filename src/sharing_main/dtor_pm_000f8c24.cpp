/* HSTMATCH module=hstp_trans_main.prx start=0x000f8c24 end=0x000f8cac symbol=__dt__10C_000f8c24Fv */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Polymorphic class owning a polymorphic object at +0x1b8: delete it through its virtual destructor and
   clear the pointer; the base destructor (0x1087a8) is out of line (template instance, hsttmpl.py tag t3s).
   Names provisional. */
class Poly_000f8c24 { public: virtual ~Poly_000f8c24(); };
class B_001087a8 { public: virtual void key_001087a8(); virtual ~B_001087a8(); char pad[0x1b4]; };
class C_000f8c24 : public B_001087a8 {
public:
    virtual void key_000f8c24();
    Poly_000f8c24 *obj;
    virtual ~C_000f8c24();
};
C_000f8c24::~C_000f8c24()
{
    if (obj) {
        delete obj;
        obj = 0;
    }
}
