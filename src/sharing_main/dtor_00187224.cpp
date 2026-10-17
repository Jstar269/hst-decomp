/* HSTMATCH module=hstp_trans_main.prx start=0x00187224 end=0x00187294 symbol=__dt__10D_00187224Fv */
/* Clone of src/eboot/dtor_00054cbc.cpp (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
/* Derived container destructor: the body clears size; the inline base destructor shrinks by a local
   copy of size with an empty allocator class passed by value (32-byte frame), then deletes the element
   block. Names provisional. */
struct Alloc {};
struct Elem_00187224 { int v; ~Elem_00187224() {} };
class V_00187224 {
public:
    Elem_00187224 *data;
    int size;
    void shrink(int n, Alloc) { size -= n; }
    ~V_00187224() { int n = size; shrink(n, Alloc()); delete data; }
};
class D_00187224 : public V_00187224 { public: ~D_00187224(); };
D_00187224::~D_00187224() { size = 0; }
