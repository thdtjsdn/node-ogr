
#ifndef __OGR_COMMON_H__
#define __OGR_COMMON_H__

#include <v8.h>
#include <boost/shared_ptr.hpp>

#define TOSTR(obj) (*String::Utf8Value((obj)->ToString()))

#define NODE_ARG_INT(num, name, var)                                                                           \
  if (args.Length() < num + 1) {                                                                               \
    return ThrowException(Exception::Error(String::New((std::string(name) + " must be given").c_str())));      \
  }                                                                                                            \
  if (!args[num]->IsNumber()) {                                                                                \
    return ThrowException(Exception::Error(String::New((std::string(name) + " must be an integer").c_str()))); \
  }                                                                                                            \
  var = static_cast<int>(args[num]->IntegerValue());


#define NODE_ARG_ENUM(num, name, enum_type, var)                                                                                       \
  if (args.Length() < num + 1) {                                                                                                       \
    return ThrowException(Exception::Error(String::New((std::string(name) + " must be given").c_str())));                              \
  }                                                                                                                                    \
  if (!args[num]->IsInt32()) {                                                                                                         \
    return ThrowException(Exception::Error(String::New((std::string(name) + " must be of type " + std::string(#enum_type)).c_str()))); \
  }                                                                                                                                    \
  var = enum_type(args[num]->IntegerValue());


#define NODE_ARG_BOOL(num, name, var)                                                                          \
  if (args.Length() < num + 1) {                                                                               \
    return ThrowException(Exception::Error(String::New((std::string(name) + " must be given").c_str())));      \
  }                                                                                                            \
  if (!args[num]->IsBoolean()) {                                                                               \
    return ThrowException(Exception::Error(String::New((std::string(name) + " must be an boolean").c_str()))); \
  }                                                                                                            \
  var = static_cast<bool>(args[num]->BooleanValue());


#define NODE_ARG_DOUBLE(num, name, var)                                                                      \
  if (args.Length() < num + 1) {                                                                             \
    return ThrowException(Exception::Error(String::New((std::string(name) + " must be given").c_str())));    \
  }                                                                                                          \
  if (!args[num]->IsNumber()) {                                                                              \
    return ThrowException(Exception::Error(String::New((std::string(name) + " must be a number").c_str()))); \
  }                                                                                                          \
  var = static_cast<double>(args[num]->NumberValue());


#define NODE_ARG_ARRAY(num, name, var)                                                                       \
  if (args.Length() < num + 1) {                                                                             \
    return ThrowException(Exception::Error(String::New((std::string(name) + " must be given").c_str())));    \
  }                                                                                                          \
  if (!args[num]->IsArray()) {                                                                               \
    return ThrowException(Exception::Error(String::New((std::string(name) + " must be an array").c_str()))); \
  }                                                                                                          \
  var = Handle<Array>::Cast(args[num]);


#define NODE_ARG_OBJECT(num, name, var)                                                                       \
  if (args.Length() < num + 1) {                                                                              \
    return ThrowException(Exception::Error(String::New((std::string(name) + " must be given").c_str())));     \
  }                                                                                                           \
  if (!args[num]->IsObject()) {                                                                               \
    return ThrowException(Exception::Error(String::New((std::string(name) + " must be an object").c_str()))); \
  }                                                                                                           \
  var = Handle<Object>::Cast(args[num]);


#define NODE_ARG_WRAPPED(num, name, type, var)                                                                                           \
  if (args.Length() < num + 1) {                                                                                                         \
    return ThrowException(Exception::Error(String::New((std::string(name) + " must be given").c_str())));                                \
  }                                                                                                                                      \
  Local<Object> obj = args[num]->ToObject();                                                                                             \
  if (obj->IsNull() || obj->IsUndefined() || !type::constructor->HasInstance(obj)) {                                                     \
    return ThrowException(Exception::Error(String::New((std::string(name) + " must be an instance of " + std::string(#name)).c_str()))); \
  }                                                                                                                                      \
  var = ObjectWrap::Unwrap<type>(obj);


#define NODE_ARG_STR(num, name, var)                                                                          \
  if (args.Length() < num + 1) {                                                                              \
    return ThrowException(Exception::Error(String::New((std::string(name) + " must be given").c_str())));     \
  }                                                                                                           \
  if (!args[num]->IsString()) {                                                                               \
    return ThrowException(Exception::Error(String::New((std::string(name) + " must be an string").c_str()))); \
  }                                                                                                           \
  var = (*String::Utf8Value((args[num])->ToString()))


#define NODE_ARG_INT_OPT(num, name, var)                                                                         \
  if (args.Length() > num) {                                                                                     \
    if (args[num]->IsInt32()) {                                                                                  \
      var = static_cast<int>(args[num]->IntegerValue());                                                         \
    } else {                                                                                                     \
      return ThrowException(Exception::Error(String::New((std::string(name) + " must be an integer").c_str()))); \
    }                                                                                                            \
  }


#define NODE_ARG_ENUM_OPT(num, name, enum_type, var)                                                             \
  if (args.Length() > num) {                                                                                     \
    if (args[num]->IsInt32()) {                                                                                  \
      var = static_cast<enum_type>(args[num]->IntegerValue());                                                   \
    } else {                                                                                                     \
      return ThrowException(Exception::Error(String::New((std::string(name) + " must be an integer").c_str()))); \
    }                                                                                                            \
  }


#define NODE_ARG_BOOL_OPT(num, name, var)                                                                        \
  if (args.Length() > num) {                                                                                     \
    if (args[num]->IsBoolean()) {                                                                                \
      var = static_cast<bool>(args[num]->BooleanValue());                                                        \
    } else {                                                                                                     \
      return ThrowException(Exception::Error(String::New((std::string(name) + " must be an boolean").c_str()))); \
    }                                                                                                            \
  }


#define NODE_ARG_OPT_STR(num, name, var)                                                                        \
  if (args.Length() > num) {                                                                                    \
    if (args[num]->IsString()) {                                                                                \
      var = TOSTR(args[num]);                                                                                   \
    } else {                                                                                                    \
      return ThrowException(Exception::Error(String::New((std::string(name) + " must be an string").c_str()))); \
    }                                                                                                           \
  }


#define NODE_ARG_DOUBLE_OPT(num, name, var)                                                                    \
  if (args.Length() > num) {                                                                                   \
    if (args[num]->IsNumber()) {                                                                               \
      var = static_cast<double>(args[num]->NumberValue());                                                     \
    } else {                                                                                                   \
      return ThrowException(Exception::Error(String::New((std::string(name) + " must be a number").c_str()))); \
    }                                                                                                          \
  }


#define NODE_ARG_WRAPPED_OPT(num, name, type, var)                                                                                         \
  if (args.Length() > num) {                                                                                                               \
    Local<Object> obj = args[num]->ToObject();                                                                                             \
    if (obj->IsNull() || obj->IsUndefined() || !type::constructor->HasInstance(obj)) {                                                     \
      return ThrowException(Exception::Error(String::New((std::string(name) + " must be an instance of " + std::string(#name)).c_str()))); \
    }                                                                                                                                      \
    var = ObjectWrap::Unwrap<type>(obj);                                                                                                   \
  }


#define NODE_ARG_ARRAY_OPT(num, name, var)                                                                     \
  if (args.Length() > num) {                                                                                   \
    if (args[num]->IsArray()) {                                                                                \
      var = Handle<Array>::Cast(args[num]);                                                                    \
    } else {                                                                                                   \
      return ThrowException(Exception::Error(String::New((std::string(name) + " must be an array").c_str()))); \
    }                                                                                                          \
  }


#define NODE_WRAPPED_METHOD_WITH_RESULT(klass, method, result_type, wrapped_method)                               \
Handle<Value> klass::method(const Arguments& args)                                                                \
{                                                                                                                 \
  return HandleScope().Close(result_type::New(ObjectWrap::Unwrap<klass>(args.This())->this_->wrapped_method()));  \
}


#define NODE_WRAPPED_METHOD_WITH_RESULT_1_WRAPPED_PARAM(klass, method, result_type, wrapped_method, param_type, param_name) \
Handle<Value> klass::method(const Arguments& args)                                                                          \
{                                                                                                                           \
  HandleScope scope;                                                                                                        \
  param_type *param;                                                                                                        \
  NODE_ARG_WRAPPED(0, #param_name, param_type, param);                                                                      \
  return scope.Close(result_type::New(ObjectWrap::Unwrap<klass>(args.This())->this_->wrapped_method(param->get())));        \
}


#define NODE_WRAPPED_METHOD_WITH_RESULT_1_STRING_PARAM(klass, method, result_type, wrapped_method, param_name)        \
Handle<Value> klass::method(const Arguments& args)                                                                    \
{                                                                                                                     \
  HandleScope scope;                                                                                                  \
  std::string param;                                                                                                  \
  NODE_ARG_STR(0, #param_name, param);                                                                                \
  return scope.Close(result_type::New(ObjectWrap::Unwrap<klass>(args.This())->this_->wrapped_method(param.c_str()))); \
}


#define NODE_WRAPPED_METHOD_WITH_RESULT_1_INTEGER_PARAM(klass, method, result_type, wrapped_method, param_name) \
Handle<Value> klass::method(const Arguments& args)                                                              \
{                                                                                                               \
  HandleScope scope;                                                                                            \
  int param;                                                                                                    \
  NODE_ARG_INT(0, #param_name, param);                                                                          \
  return scope.Close(result_type::New(ObjectWrap::Unwrap<klass>(args.This())->this_->wrapped_method(param)));   \
}


#define NODE_WRAPPED_METHOD_WITH_RESULT_1_DOUBLE_PARAM(klass, method, result_type, wrapped_method, param_name) \
Handle<Value> klass::method(const Arguments& args)                                                             \
{                                                                                                              \
  HandleScope scope;                                                                                           \
  double param;                                                                                                \
  NODE_ARG_DOUBLE(0, #param_name, param);                                                                      \
  return scope.Close(result_type::New(ObjectWrap::Unwrap<klass>(args.This())->this_->wrapped_method(param)));  \
}


#define NODE_WRAPPED_METHOD(klass, method, wrapped_method)           \
Handle<Value> klass::method(const Arguments& args)                   \
{                                                                    \
  HandleScope scope;                                                 \
  ObjectWrap::Unwrap<klass>(args.This())->this_->wrapped_method();   \
  return Undefined();                                                \
}


#define NODE_WRAPPED_METHOD_WITH_1_WRAPPED_PARAM(klass, method, wrapped_method, param_type, param_name) \
Handle<Value> klass::method(const Arguments& args)                                                      \
{                                                                                                       \
  HandleScope scope;                                                                                    \
  param_type *param;                                                                                    \
  NODE_ARG_WRAPPED(0, #param_name, param_type, param);                                                  \
  ObjectWrap::Unwrap<klass>(args.This())->this_->wrapped_method(param->get());                          \
  return Undefined();                                                                                   \
}


#define NODE_WRAPPED_METHOD_WITH_1_INTEGER_PARAM(klass, method, wrapped_method, param_name) \
Handle<Value> klass::method(const Arguments& args)                                          \
{                                                                                           \
  HandleScope scope;                                                                        \
  int param;                                                                                \
  NODE_ARG_INT(0, #param_name, param);                                                      \
  ObjectWrap::Unwrap<klass>(args.This())->this_->wrapped_method(param);                     \
  return Undefined();                                                                       \
}


#define NODE_WRAPPED_METHOD_WITH_1_DOUBLE_PARAM(klass, method, wrapped_method, param_name)  \
Handle<Value> klass::method(const Arguments& args)                                          \
{                                                                                           \
  HandleScope scope;                                                                        \
  double param;                                                                             \
  NODE_ARG_DOUBLE(0, #param_name, param);                                                   \
  ObjectWrap::Unwrap<klass>(args.This())->this_->wrapped_method(param);                     \
  return Undefined();                                                                       \
}


#define NODE_WRAPPED_METHOD_WITH_1_BOOLEAN_PARAM(klass, method, wrapped_method, param_name) \
Handle<Value> klass::method(const Arguments& args)                                          \
{                                                                                           \
  HandleScope scope;                                                                        \
  bool param;                                                                               \
  NODE_ARG_BOOL(0, #param_name, param);                                                     \
  ObjectWrap::Unwrap<klass>(args.This())->this_->wrapped_method(param);                     \
  return Undefined();                                                                       \
}


#define NODE_WRAPPED_METHOD_WITH_1_ENUM_PARAM(klass, method, wrapped_method, enum_type, param_name) \
Handle<Value> klass::method(const Arguments& args)                                                  \
{                                                                                                   \
  HandleScope scope;                                                                                \
  enum_type param;                                                                                  \
  NODE_ARG_ENUM(0, #param_name, enum_type, param);                                                  \
  ObjectWrap::Unwrap<klass>(args.This())->this_->wrapped_method(param);                             \
  return Undefined();                                                                               \
}


#define NODE_WRAPPED_METHOD_WITH_1_STRING_PARAM(klass, method, wrapped_method, param_name)  \
Handle<Value> klass::method(const Arguments& args)                                          \
{                                                                                           \
  HandleScope scope;                                                                        \
  std::string param;                                                                        \
  NODE_ARG_STR(0, #param_name, param);                                                      \
  ObjectWrap::Unwrap<klass>(args.This())->this_->wrapped_method(param.c_str());             \
  return Undefined();                                                                       \
}


#define NODE_THROW(msg) ThrowException(Exception::Error(String::New(msg)));

template <typename T, typename K>
class ClosedPtr {
public:
  static v8::Handle<v8::Value> Closed(K *raw) {
    v8::HandleScope scope;
    T *wrapped = new T(raw);
    v8::Handle<v8::Value> ext = v8::External::New(wrapped);
    v8::Handle<v8::Object> obj = T::constructor->GetFunction()->NewInstance(1, &ext);
    return scope.Close(obj);
  }
};

#endif
