
#ifndef _NNDEPLOY_OP_OP_UNARY_H_
#define _NNDEPLOY_OP_OP_UNARY_H_

#include "nndeploy/ir/ir.h"
#include "nndeploy/op/op.h"

namespace nndeploy {
namespace op {

class OpUnary : public Op {
 public:
  OpUnary() : Op() { is_inplace_ = true; }
  virtual ~OpUnary() {}

  virtual base::Status inferShape();
};

}  // namespace op
}  // namespace nndeploy

#endif
