/* HSTMATCH module=EBOOT.BIN start=0x00238770 end=0x002387dc symbol=__dt__10C_00238770Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_002388f8(void *self);
struct Blob_00238770 { int v; ~Blob_00238770() {} };
class B_00238770 { public: Blob_00238770 *data; ~B_00238770() { FUN_002388f8(this); delete data; } };
class C_00238770 : public B_00238770 { public: int count; ~C_00238770(); };
C_00238770::~C_00238770() { count = 0; }
