/* HSTMATCH module=EBOOT.BIN start=0x00238704 end=0x00238770 symbol=__dt__10C_00238704Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0023891c(void *self);
struct Blob_00238704 { int v; ~Blob_00238704() {} };
class B_00238704 { public: Blob_00238704 *data; ~B_00238704() { FUN_0023891c(this); delete data; } };
class C_00238704 : public B_00238704 { public: int count; ~C_00238704(); };
C_00238704::~C_00238704() { count = 0; }
