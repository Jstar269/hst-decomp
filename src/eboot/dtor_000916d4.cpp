/* HSTMATCH module=EBOOT.BIN start=0x000916d4 end=0x00091740 symbol=__dt__10D_000916d4Fv */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor calls the out-of-line
   clear() at 0x91740 and deletes the element block. Names provisional. */
extern "C" void FUN_00091740(void *self);
struct Elem_000916d4 { int v; ~Elem_000916d4() {} };
class V_000916d4 { public: Elem_000916d4 *data; int size; ~V_000916d4() { FUN_00091740(this); delete data; } };
class D_000916d4 : public V_000916d4 { public: ~D_000916d4(); };
D_000916d4::~D_000916d4() { size = 0; }
