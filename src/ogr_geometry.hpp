#ifndef __NODE_OGR_GEOMETRY_H__
#define __NODE_OGR_GEOMETRY_H__

#include <v8.h>
#include <node.h>
#include <node_object_wrap.h>

// ogr
#include <ogrsf_frmts.h>

// boost
#include <boost/shared_ptr.hpp>

using namespace v8;
using namespace node;

class Geometry: public node::ObjectWrap {
  public:
    static Persistent<FunctionTemplate> constructor;
    static void Initialize(Handle<Object> target);
    static Handle<Value> New(const Arguments &args);
    static Handle<Value> New(OGRGeometry *geom);
    static Handle<Value> New(OGRGeometry *geom, bool owned);
    static Handle<Value> toString(const Arguments &args);
    static Handle<Value> getDimension(const Arguments &args);
    static Handle<Value> getCoordinateDimension(const Arguments &args);
    static Handle<Value> isEmpty(const Arguments &args);
    static Handle<Value> isValid(const Arguments &args);
    static Handle<Value> isSimple(const Arguments &args);
    static Handle<Value> isRing(const Arguments &args);
    static Handle<Value> clone(const Arguments &args);
    static Handle<Value> empty(const Arguments &args);
    static Handle<Value> wkbSize(const Arguments &args);
    static Handle<Value> getGeometryType(const Arguments &args);
    static Handle<Value> getGeometryName(const Arguments &args);
    static Handle<Value> exportToKML(const Arguments &args);
    static Handle<Value> exportToGML(const Arguments &args);
    static Handle<Value> exportToJSON(const Arguments &args);
    static Handle<Value> closeRings(const Arguments &args);
    static Handle<Value> segmentize(const Arguments &args);
    static Handle<Value> intersects(const Arguments &args);
    static Handle<Value> equals(const Arguments &args);
    static Handle<Value> disjoint(const Arguments &args);
    static Handle<Value> touches(const Arguments &args);
    static Handle<Value> crosses(const Arguments &args);
    static Handle<Value> within(const Arguments &args);
    static Handle<Value> contains(const Arguments &args);
    static Handle<Value> overlaps(const Arguments &args);
    static Handle<Value> boundary(const Arguments &args);
    static Handle<Value> distance(const Arguments &args);
    static Handle<Value> convexHull(const Arguments &args);
    static Handle<Value> buffer(const Arguments &args);
    static Handle<Value> intersection(const Arguments &args);
    static Handle<Value> unionGeometry(const Arguments &args);
    static Handle<Value> unionCascaded(const Arguments &args);
    static Handle<Value> difference(const Arguments &args);
    static Handle<Value> symDifference(const Arguments &args);
    static Handle<Value> centroid(const Arguments &args);
    static Handle<Value> simplify(const Arguments &args);
    static Handle<Value> simplifyPreserveTopology(const Arguments &args);
    static Handle<Value> polygonize(const Arguments &args);
    static Handle<Value> swapXY(const Arguments &args);

    Geometry();
    Geometry(OGRGeometry *geom);
    inline OGRGeometry *get() { return this_; }

  private:
    ~Geometry();
    OGRGeometry *this_;
    bool owned_;
    int size_;
};

#endif


