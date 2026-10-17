/* HSTMATCH module=EBOOT.BIN start=0x0027b670 end=0x0027b6dc symbol=__dt__10C_0027b670Fv */
/* Clone of src/eboot/dtor_0028d7f8.cpp (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
extern "C" void FUN_0027b6dc(void *self);
struct Blob_0027b670 { int v; ~Blob_0027b670() {} };
class B_0027b670 { public: Blob_0027b670 *data; ~B_0027b670() { FUN_0027b6dc(this); delete data; } };
class C_0027b670 : public B_0027b670 { public: int count; ~C_0027b670(); };
C_0027b670::~C_0027b670() { count = 0; }
