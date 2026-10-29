/* HSTMATCH module=EBOOT.BIN start=0x00289e84 end=0x00289f84 symbol=FUN_00289e84 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/scene_res.h"

template <class T> struct It {
  T *p_;
  It(T *p) : p_(p) {}
  T &operator*() const { return *p_; }
  It &operator++() { ++p_; return *this; }
};
template <class T> inline bool operator==(const It<T> &a, const It<T> &b) { return a.p_ == b.p_; }
template <class T> inline bool operator!=(const It<T> &a, const It<T> &b) { return !(a == b); }

struct Alloc {};
template <class T> struct Vec {
  T *data_;
  unsigned size_;
  It<T> begin() const { return It<T>(data_); }
  It<T> end() { return It<T>(data_ + size_); }
  void shrink(int n, Alloc) { size_ -= n; }
};

extern "C" int FUN_00055e48(void *, int);
extern "C" int FUN_00053718(SceneModel *, int);
extern "C" void FUN_00000a00(void *);

/* Destroy every owned resource set (motion, break model, collision, model), free it, then empty the vector. */
extern "C" void FUN_00289e84(Vec<SceneResSet *> *v)
{
  for (It<SceneResSet *> it = v->begin(); it != v->end(); ++it) {
    SceneResSet *set = *it;
    if (set != 0) {
      if (set->motion != 0) { FUN_00055e48(set->motion, 1); set->motion = 0; }
      if (set->breakModel != 0) { FUN_00053718(set->breakModel, 1); set->breakModel = 0; }
      if (set->collision != 0) { FUN_00053718(set->collision, 1); set->collision = 0; }
      if (set->model != 0) { FUN_00053718(set->model, 1); set->model = 0; }
      if (set != 0) FUN_00000a00(set);
    }
  }
  int n = v->size_;
  v->shrink(n, Alloc());
}
