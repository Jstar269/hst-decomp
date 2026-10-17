/* HSTMATCH module=EBOOT.BIN start=0x000b801c end=0x000b80a4 symbol=__dt__10C_000b801cFv */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Polymorphic class owning a polymorphic object at +0xf8: delete it through its virtual destructor and
   clear the pointer; the base destructor (0x1f0f0) is out of line. Names provisional. */
class Poly_000b801c { public: virtual ~Poly_000b801c(); };
class B_0001f0f0 { public: virtual void key_0001f0f0(); virtual ~B_0001f0f0(); char pad[0xf4]; };
class C_000b801c : public B_0001f0f0 {
public:
    virtual void key_000b801c();
    Poly_000b801c *obj;
    virtual ~C_000b801c();
};
C_000b801c::~C_000b801c()
{
    if (obj) {
        delete obj;
        obj = 0;
    }
}
