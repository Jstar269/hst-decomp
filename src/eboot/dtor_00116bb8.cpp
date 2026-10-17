/* HSTMATCH module=EBOOT.BIN start=0x00116bb8 end=0x00116c24 symbol=__dt__10C_00116bb8Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_00116cb4(void *self);
struct Blob_00116bb8 { int v; ~Blob_00116bb8() {} };
class B_00116bb8 { public: Blob_00116bb8 *data; ~B_00116bb8() { FUN_00116cb4(this); delete data; } };
class C_00116bb8 : public B_00116bb8 { public: int count; ~C_00116bb8(); };
C_00116bb8::~C_00116bb8() { count = 0; }
