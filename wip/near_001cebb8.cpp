/* HSTMATCH module=EBOOT.BIN start=0x001cebb8 end=0x001cee14 symbol=FUN_001cebb8 lang=c++ */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

struct Vec4 { float x; float y; float z; float w; };

extern "C" {
extern float DAT_002ea2e4;
extern float DAT_002ea2e8;
extern float fabsf(float);
extern Vec4 * FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
extern float FUN_000224d8(const Vec4 *, const Vec4 *);
extern Vec4 * FUN_00022518(Vec4 *, const Vec4 *);
extern int * FUN_00288af0(void *);
extern int * FUN_00288b2c(void *);
extern bool FUN_0028bd5c(undefined4, void *);
}

struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual int state(); };
struct VC_1 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual Vec4 * vector(); };
struct VC_2 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual int state(); };
struct VC_3 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual Vec4 * vector(); };
struct VC_4 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual Vec4 * vector(); };

extern "C" int FUN_001cebb8(char *param_1, void *param_2)
{
  int result = 0;
  float delta_y4;
  Vec4 dot_vec;
  Vec4 norm_input;
  Vec4 normalized;
  Vec4 diff_state5;
  Vec4 diff_state4;
  Vec4 diff_state4b;

  if (param_2 != 0) {
    if (*((unsigned char *)param_2 + 84) != 0) {
      VC_0 *state_obj = (VC_0 *)param_2;
      if (state_obj->state() == 5) {
        int *obj = FUN_00288b2c(param_2);
        unsigned char flag = *((unsigned char *)obj + 0xec);
        result = flag ? 0 : 1;
        if (result) {
          VC_1 *vector_obj = (VC_1 *)param_2;
          FUN_00022434(&diff_state5, (const Vec4 *)(param_1 + 0x30), vector_obj->vector());
          result = (diff_state5.x * diff_state5.x + diff_state5.z * diff_state5.z < DAT_002ea2e4 * DAT_002ea2e4 &&
              fabsf(diff_state5.y) < DAT_002ea2e8) ? 1 : 0;
        }
      } else {
        VC_2 *state_obj2 = (VC_2 *)param_2;
        if (state_obj2->state() == 4) {
          VC_3 *vector_obj = (VC_3 *)param_2;
          FUN_00022434(&diff_state4, (const Vec4 *)(param_1 + 0x30), vector_obj->vector());
            delta_y4 = diff_state4.y;
            bool near;
            if (diff_state4.x * diff_state4.x + diff_state4.z * diff_state4.z < DAT_002ea2e4 * DAT_002ea2e4) {
              if (fabsf(delta_y4) < DAT_002ea2e8) near = true;
              else near = false;
            } else {
              near = false;
            }
            char allowed = '\0';
            if (near) allowed = FUN_0028bd5c(*(undefined4 *)(param_1 + 0x40), param_2);
          result = 0;
            if (allowed != '\0') {
            VC_4 *vector_obj2 = (VC_4 *)param_2;
            FUN_00022434(&diff_state4b, vector_obj2->vector(), (const Vec4 *)(param_1 + 0x30));
            norm_input = diff_state4b;
            FUN_00022518(&normalized, &norm_input);
            normalized.w = 0.0f;
            dot_vec.x = normalized.x;
            dot_vec.y = normalized.y;
            dot_vec.z = normalized.z;
            dot_vec.w = 0.0f;
            int *obj = FUN_00288af0(param_2);
            Vec4 *direction = *(Vec4 **)((char *)obj + 0x70);
            float dot = FUN_000224d8((const Vec4 *)((char *)direction + 0x50), &dot_vec);
            if (!(dot >= 0.0f)) {
              result = 1;
            } else {
              result = 0;
            }
          }
        }
      }
    }
  }
  return result;
}
// NEAR: 150/151 words, 109 differ. The typed vtable returns, float globals, Vec4 helper prototypes, six stack vectors, and 112-byte frame align with retail.
// Remaining differences are control-flow and register scheduling in the state-5/state-4 predicates, plus the dot-sign tail. Tried direct and materialized byte gates, &&/nested/ternary forms, typed and float temporaries, and several >= / negated compare forms.
// near miss from lane km4 (unreviewed)
