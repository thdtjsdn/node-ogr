#ifndef __NODE_OGR_DRIVER_H__
#define __NODE_OGR_DRIVER_H__

#include <v8.h>
#include <node.h>
#include <node_object_wrap.h>

// ogr
#include <ogrsf_frmts.h>

// boost
#include <boost/shared_ptr.hpp>

using namespace v8;
using namespace node;

class Driver: public node::ObjectWrap {
  public:
    static Persistent<FunctionTemplate> constructor;
    static void Initialize(Handle<Object> target);
    static Handle<Value> New(const Arguments &args);
    static Handle<Value> New(OGRSFDriver *driver);
    static Handle<Value> toString(const Arguments &args);
    static Handle<Value> getName(const Arguments &args);
    static Handle<Value> open(const Arguments &args);
    static Handle<Value> testCapability(const Arguments &args);
    static Handle<Value> createDataSource(const Arguments &args);
    static Handle<Value> deleteDataSource(const Arguments &args);
    static Handle<Value> copyDataSource(const Arguments &args);

    Driver();
    Driver(OGRSFDriver *ds);
    inline OGRSFDriver *get() { return this_; }

  private:
    ~Driver();
    OGRSFDriver *this_;
};

#endif
