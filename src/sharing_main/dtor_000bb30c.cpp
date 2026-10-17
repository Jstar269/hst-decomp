/* HSTMATCH module=hstp_trans_main.prx start=0x000bb30c end=0x000bb394 symbol=__dt__10C_000bb30cFv */
/* Clone of src/eboot/dtor_000b801c.cpp (hstclone.py tag x21): addresses substituted; exact match verified; names and types await human review. */
/* Polymorphic class owning a polymorphic object at +0xf8: delete it through its virtual destructor and
   clear the pointer; the base destructor (0x1f0f0) is out of line. Names provisional. */
class Poly_000bb30c { public: virtual ~Poly_000bb30c(); };
class B_0001ed28 { public: virtual void key_0001ed28(); virtual ~B_0001ed28(); char pad[0xf4]; };
class C_000bb30c : public B_0001ed28 {
public:
    virtual void key_000bb30c();
    Poly_000bb30c *obj;
    virtual ~C_000bb30c();
};
C_000bb30c::~C_000bb30c()
{
    if (obj) {
        delete obj;
        obj = 0;
    }
}
