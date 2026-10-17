/* HSTMATCH module=EBOOT.BIN start=0x00238698 end=0x00238704 symbol=__dt__10C_00238698Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_00238940(void *self);
struct Blob_00238698 { int v; ~Blob_00238698() {} };
class B_00238698 { public: Blob_00238698 *data; ~B_00238698() { FUN_00238940(this); delete data; } };
class C_00238698 : public B_00238698 { public: int count; ~C_00238698(); };
C_00238698::~C_00238698() { count = 0; }
