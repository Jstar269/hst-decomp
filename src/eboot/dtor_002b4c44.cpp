/* HSTMATCH module=EBOOT.BIN start=0x002b4c44 end=0x002b4cb0 symbol=__dt__10C_002b4c44Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_002b4cb0(void *self);
struct Blob_002b4c44 { int v; ~Blob_002b4c44() {} };
class B_002b4c44 { public: Blob_002b4c44 *data; ~B_002b4c44() { FUN_002b4cb0(this); delete data; } };
class C_002b4c44 : public B_002b4c44 { public: int count; ~C_002b4c44(); };
C_002b4c44::~C_002b4c44() { count = 0; }
