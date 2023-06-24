#ifndef TYPES_H
#define TYPES_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef union {
  void* ptr;
  char c;
  int i;
  float f;
  double d;
  int8_t i8;
  uint8_t u8;
  int16_t i16;
  uint16_t u16;
  int32_t i32;
  uint32_t u32;
  int64_t i64;
  uint64_t u64;
  size_t st;
  bool b;
} variant_t;

typedef int (*comparator_t)(variant_t, variant_t);

#define to_v(m,v) ((variant_t){.m=(v)})
#define v_to(m,v) ((v).m)

#define p_to_v(p) to_v(ptr,p)
#define c_to_v(cv) to_v(c,cv)
#define i_to_v(iv) to_v(i,iv)
#define f_to_v(fv) to_v(f,fv)
#define d_to_v(dv) to_v(d,dv)
#define i8_to_v(i) to_v(i8,i)
#define u8_to_v(u) to_v(u8,u)
#define i16_to_v(u) to_v(i16,u)
#define u16_to_v(u) to_v(u16,u)
#define i32_to_v(u) to_v(i32,u)
#define u32_to_v(u) to_v(u32,u)
#define i64_to_v(u) to_v(i64,u)
#define u64_to_v(u) to_v(u64,u)
#define st_to_v(u) to_v(st,u)
#define b_to_v(u) to_v(b,u)

#define v_to_p(v) v_to(ptr,v)
#define v_to_c(v) v_to(c,v)
#define v_to_i(v) v_to(i,v)
#define v_to_f(v) v_to(f,v)
#define v_to_d(v) v_to(d,v)
#define v_to_i8(v) v_to(i8,v)
#define v_to_u8(v) v_to(u8,v)
#define v_to_i16(v) v_to(i16,v)
#define v_to_u16(v) v_to(u16,v)
#define v_to_i32(v) v_to(i32,v)
#define v_to_u32(v) v_to(u32,v)
#define v_to_i64(v) v_to(i64,v)
#define v_to_u64(v) v_to(u64,v)
#define v_to_st(v) v_to(st,v)
#define v_to_b(v) v_to(b,v)

#endif
