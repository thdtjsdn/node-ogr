#ifndef __NODE_OGR_FEATURE_H__
#define __NODE_OGR_FEATURE_H__

#include <v8.h>
#include <node.h>
#include <node_object_wrap.h>

// ogr
#include <ogrsf_frmts.h>

// boost
#include <boost/shared_ptr.hpp>

using namespace v8;
using namespace node;

class Feature: public node::ObjectWrap {
  public:
    static Persistent<FunctionTemplate> constructor;
    static void Initialize(Handle<Object> target);
    static Handle<Value> New(const Arguments &args);
    static Handle<Value> New(OGRFeature *feature);
    static Handle<Value> toString(const Arguments &args);
    static Handle<Value> getGeometry(const Arguments& args);
    static Handle<Value> setGeometryDirectly(const Arguments& args);
    static Handle<Value> setGeometry(const Arguments& args);
    static Handle<Value> stealGeometry(const Arguments& args);
    static Handle<Value> clone(const Arguments& args);
    static Handle<Value> equal(const Arguments& args);
    static Handle<Value> getFieldCount(const Arguments& args);
    static Handle<Value> getFieldDefn(const Arguments& args);
    static Handle<Value> getFieldIndex(const Arguments& args);
    static Handle<Value> isFieldSet(const Arguments& args);
    static Handle<Value> unsetField(const Arguments& args);
    static Handle<Value> getRawField(const Arguments& args);
    static Handle<Value> getFieldAsInteger(const Arguments& args);
    static Handle<Value> getFieldAsDouble(const Arguments& args);
    static Handle<Value> getFieldAsString(const Arguments& args);
    static Handle<Value> getFieldAsIntegerList(const Arguments& args);
    static Handle<Value> getFieldAsDoubleList(const Arguments& args);
    static Handle<Value> getFieldAsStringList(const Arguments& args);
    static Handle<Value> getFieldAsBinary(const Arguments& args);
    static Handle<Value> getFieldAsDateTime(const Arguments& args);
    static Handle<Value> setField(const Arguments& args);
    static Handle<Value> getFID(const Arguments& args);
    static Handle<Value> setFID(const Arguments& args);
    static Handle<Value> setFrom(const Arguments& args);

    Feature();
    Feature(OGRFeature *geom);
    inline OGRFeature *get() { return this_; }

  private:
    ~Feature();
    OGRFeature *this_;
};

#endif



