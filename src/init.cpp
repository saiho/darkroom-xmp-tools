#include <napi.h>

#include <iostream>
#include <string>

#include "blend.h"
#include "sharpen.h"
#include "expose.h"
#include "clipping.h"
#include "masks.h"

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  // sharpen
  exports.Set(
      Napi::String::New(env, "decodeSharpenParams"),
      Napi::Function::New(env, decode_sharpen_params));

  exports.Set(
      Napi::String::New(env, "encodeSharpenParams"),
      Napi::Function::New(env, encode_sharpen_params));

  // expose
  exports.Set(
      Napi::String::New(env, "decodeExposeParams"),
      Napi::Function::New(env, decode_expose_params));

  exports.Set(
      Napi::String::New(env, "encodeExposeParams"),
      Napi::Function::New(env, encode_expose_params));

  // blend
  exports.Set(
      Napi::String::New(env, "decodeBlendParams"),
      Napi::Function::New(env, decode_blend_params));

  exports.Set(
      Napi::String::New(env, "encodeBlendParams"),
      Napi::Function::New(env, encode_blend_params));

  // clipping
  exports.Set(
      Napi::String::New(env, "decodeClippingParams"),
      Napi::Function::New(env, decode_clipping_params));

  exports.Set(
      Napi::String::New(env, "encodeClippingParams"),
      Napi::Function::New(env, encode_clipping_params));

  // mask
  exports.Set(
      Napi::String::New(env, "decodeMaskPoints"),
      Napi::Function::New(env, decode_mask_points));

  exports.Set(
      Napi::String::New(env, "encodeMaskPoints"),
      Napi::Function::New(env, encode_mask_points));

  return exports;
};

NODE_API_MODULE(init, Init);
