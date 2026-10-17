/* HSTMATCH module=hstp_trans_main.prx start=0x0018ab80 end=0x0018abf0 symbol=__dt__10D_0018ab80Fv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_0018ab80 { int v; ~Elem_0018ab80() {} };
class V_0018ab80 {
public:
    Elem_0018ab80 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_0018ab80() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_0018ab80 : public V_0018ab80 { public: ~D_0018ab80(); };
D_0018ab80::~D_0018ab80() { size = 0; }
