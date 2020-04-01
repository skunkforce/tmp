#pragma once
#include "tmp/call.hpp"
#include "tmp/sequence/make_sequence.hpp"
#include "tmp/sequence/push_front.hpp"
#include "tmp/sequence/tee.hpp"

using namespace osf::tmp;
template <typename T>
using make_algo = tee_<always_<T>, identity_, call_f_<>>;

using extent = uint_<50>;
