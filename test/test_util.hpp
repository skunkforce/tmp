#pragma once
#include <osf/tmp/call.hpp>
#include <osf/tmp/sequence/make_sequence.hpp>
#include <osf/tmp/sequence/push_front.hpp>
#include <osf/tmp/sequence/tee.hpp>

using namespace osf::tmp;
template <typename T>
using make_algo = tee_<always_<T>, identity_, call_f_<>>;

using extent = uint_<50>;
