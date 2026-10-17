/* HSTMATCH module=hstp_trans_main.prx start=0x001871b4 end=0x00187224 symbol=__dt__10D_001871b4Fv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_001871b4 { int v; ~Elem_001871b4() {} };
class V_001871b4 {
public:
    Elem_001871b4 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_001871b4() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_001871b4 : public V_001871b4 { public: ~D_001871b4(); };
D_001871b4::~D_001871b4() { size = 0; }
