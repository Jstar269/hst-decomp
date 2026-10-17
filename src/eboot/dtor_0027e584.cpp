/* HSTMATCH module=EBOOT.BIN start=0x0027e584 end=0x0027e5f0 symbol=__dt__10C_0027e584Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0027e5f0(void *self);
struct Blob_0027e584 { int v; ~Blob_0027e584() {} };
class B_0027e584 { public: Blob_0027e584 *data; ~B_0027e584() { FUN_0027e5f0(this); delete data; } };
class C_0027e584 : public B_0027e584 { public: int count; ~C_0027e584(); };
C_0027e584::~C_0027e584() { count = 0; }
