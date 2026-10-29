/* Route object of the avatar's route following: spline basis, current position and point lists. */
#ifndef HST_AVATAR_ROUTE_H
#define HST_AVATAR_ROUTE_H

#include "hst/types.h"

/* Number of elements reserved up front in each point list. */
#define ROUTE_INITIAL_CAPACITY 10

typedef struct RouteVec4 {
  float x, y, z, w;
#ifdef __cplusplus
  RouteVec4() {}
  RouteVec4(const RouteVec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
#endif
} __attribute__((aligned(16))) RouteVec4;

typedef struct RouteMat4 {
  RouteVec4 r[4];
} RouteMat4;

/* Growable array of vectors: data, number in use, capacity. */
typedef struct RouteVecBuf {
  RouteVec4 *data;      /* 0x00 */
  int size;             /* 0x04 */
  unsigned capacity;    /* 0x08 */
} RouteVecBuf;

typedef struct Route {
  RouteMat4 basis;      /* 0x00 spline basis of the current segment */
  const void *unk40;    /* 0x40 */
  char pad44[0xc];
  float t;              /* 0x50 progress along the current segment, 0..1 */
  char pad54[0xc];
  RouteVec4 pos;        /* 0x60 current position */
  RouteVecBuf pts;      /* 0x70 route points */
  unsigned count;       /* 0x7c number of route points */
  unsigned idx;         /* 0x80 next route point */
  RouteVecBuf tangents; /* 0x84 per-point tangents */
  float speed;          /* 0x90 */
  unsigned char flag;   /* 0x94 non-zero: follow the spline, zero: walk straight to the next point */
} Route;

#endif
