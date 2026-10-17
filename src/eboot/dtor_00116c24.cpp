/* HSTMATCH module=EBOOT.BIN start=0x00116c24 end=0x00116c90 symbol=__dt__10C_00116c24Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_00116c90(void *self);
struct Blob_00116c24 { int v; ~Blob_00116c24() {} };
class B_00116c24 { public: Blob_00116c24 *data; ~B_00116c24() { FUN_00116c90(this); delete data; } };
class C_00116c24 : public B_00116c24 { public: int count; ~C_00116c24(); };
C_00116c24::~C_00116c24() { count = 0; }
