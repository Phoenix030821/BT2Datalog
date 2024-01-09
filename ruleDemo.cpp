#define __EMBEDDED_SOUFFLE__
#define SOUFFLE_GENERATOR_VERSION "UNKNOWN"
#include "souffle/CompiledSouffle.h"
#include "souffle/SignalHandler.h"
#include "souffle/SouffleInterface.h"
#include "souffle/datastructure/BTree.h"
#include "souffle/datastructure/Nullaries.h"
#include "souffle/io/IOSystem.h"
#include <any>
namespace functors {
extern "C" {
}
} //namespace functors
namespace souffle::t_btree_iii__0_1_2__110__111 {
using namespace souffle;
struct Type {
static constexpr Relation::arity_type Arity = 3;
using t_tuple = Tuple<RamDomain, 3>;
struct t_comparator_0{
 int operator()(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0])) ? -1 : (ramBitCast<RamSigned>(a[0]) > ramBitCast<RamSigned>(b[0])) ? 1 :((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1])) ? -1 : (ramBitCast<RamSigned>(a[1]) > ramBitCast<RamSigned>(b[1])) ? 1 :((ramBitCast<RamSigned>(a[2]) < ramBitCast<RamSigned>(b[2])) ? -1 : (ramBitCast<RamSigned>(a[2]) > ramBitCast<RamSigned>(b[2])) ? 1 :(0)));
 }
bool less(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0]))|| ((ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0])) && ((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1]))|| ((ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1])) && ((ramBitCast<RamSigned>(a[2]) < ramBitCast<RamSigned>(b[2]))))));
 }
bool equal(const t_tuple& a, const t_tuple& b) const {
return (ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0]))&&(ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1]))&&(ramBitCast<RamSigned>(a[2]) == ramBitCast<RamSigned>(b[2]));
 }
};
using t_ind_0 = btree_set<t_tuple,t_comparator_0>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0_lower;
t_ind_0::operation_hints hints_0_upper;
};
context createContext() { return context(); }
bool insert(const t_tuple& t);
bool insert(const t_tuple& t, context& h);
bool insert(const RamDomain* ramDomain);
bool insert(RamDomain a0,RamDomain a1,RamDomain a2);
bool contains(const t_tuple& t, context& h) const;
bool contains(const t_tuple& t) const;
std::size_t size() const;
iterator find(const t_tuple& t, context& h) const;
iterator find(const t_tuple& t) const;
range<iterator> lowerUpperRange_000(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const;
range<iterator> lowerUpperRange_000(const t_tuple& /* lower */, const t_tuple& /* upper */) const;
range<t_ind_0::iterator> lowerUpperRange_110(const t_tuple& lower, const t_tuple& upper, context& h) const;
range<t_ind_0::iterator> lowerUpperRange_110(const t_tuple& lower, const t_tuple& upper) const;
range<t_ind_0::iterator> lowerUpperRange_111(const t_tuple& lower, const t_tuple& upper, context& h) const;
range<t_ind_0::iterator> lowerUpperRange_111(const t_tuple& lower, const t_tuple& upper) const;
bool empty() const;
std::vector<range<iterator>> partition() const;
void purge();
iterator begin() const;
iterator end() const;
void printStatistics(std::ostream& o) const;
};
} // namespace souffle::t_btree_iii__0_1_2__110__111 
namespace souffle::t_btree_iii__0_1_2__110__111 {
using namespace souffle;
using t_ind_0 = Type::t_ind_0;
using iterator = Type::iterator;
using context = Type::context;
bool Type::insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool Type::insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0_lower)) {
return true;
} else return false;
}
bool Type::insert(const RamDomain* ramDomain) {
RamDomain data[3];
std::copy(ramDomain, ramDomain + 3, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool Type::insert(RamDomain a0,RamDomain a1,RamDomain a2) {
RamDomain data[3] = {a0,a1,a2};
return insert(data);
}
bool Type::contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0_lower);
}
bool Type::contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t Type::size() const {
return ind_0.size();
}
iterator Type::find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0_lower);
}
iterator Type::find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> Type::lowerUpperRange_000(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> Type::lowerUpperRange_000(const t_tuple& /* lower */, const t_tuple& /* upper */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> Type::lowerUpperRange_110(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_0 comparator;
int cmp = comparator(lower, upper);
if (cmp > 0) {
    return make_range(ind_0.end(), ind_0.end());
}
return make_range(ind_0.lower_bound(lower, h.hints_0_lower), ind_0.upper_bound(upper, h.hints_0_upper));
}
range<t_ind_0::iterator> Type::lowerUpperRange_110(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_110(lower,upper,h);
}
range<t_ind_0::iterator> Type::lowerUpperRange_111(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_0 comparator;
int cmp = comparator(lower, upper);
if (cmp == 0) {
    auto pos = ind_0.find(lower, h.hints_0_lower);
    auto fin = ind_0.end();
    if (pos != fin) {fin = pos; ++fin;}
    return make_range(pos, fin);
}
if (cmp > 0) {
    return make_range(ind_0.end(), ind_0.end());
}
return make_range(ind_0.lower_bound(lower, h.hints_0_lower), ind_0.upper_bound(upper, h.hints_0_upper));
}
range<t_ind_0::iterator> Type::lowerUpperRange_111(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_111(lower,upper,h);
}
bool Type::empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> Type::partition() const {
return ind_0.getChunks(400);
}
void Type::purge() {
ind_0.clear();
}
iterator Type::begin() const {
return ind_0.begin();
}
iterator Type::end() const {
return ind_0.end();
}
void Type::printStatistics(std::ostream& o) const {
o << " arity 3 direct b-tree index 0 lex-order [0,1,2]\n";
ind_0.printStats(o);
}
} // namespace souffle::t_btree_iii__0_1_2__110__111 
namespace souffle::t_btree_ii__0_1__11 {
using namespace souffle;
struct Type {
static constexpr Relation::arity_type Arity = 2;
using t_tuple = Tuple<RamDomain, 2>;
struct t_comparator_0{
 int operator()(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0])) ? -1 : (ramBitCast<RamSigned>(a[0]) > ramBitCast<RamSigned>(b[0])) ? 1 :((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1])) ? -1 : (ramBitCast<RamSigned>(a[1]) > ramBitCast<RamSigned>(b[1])) ? 1 :(0));
 }
bool less(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0]))|| ((ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0])) && ((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1]))));
 }
bool equal(const t_tuple& a, const t_tuple& b) const {
return (ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0]))&&(ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1]));
 }
};
using t_ind_0 = btree_set<t_tuple,t_comparator_0>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0_lower;
t_ind_0::operation_hints hints_0_upper;
};
context createContext() { return context(); }
bool insert(const t_tuple& t);
bool insert(const t_tuple& t, context& h);
bool insert(const RamDomain* ramDomain);
bool insert(RamDomain a0,RamDomain a1);
bool contains(const t_tuple& t, context& h) const;
bool contains(const t_tuple& t) const;
std::size_t size() const;
iterator find(const t_tuple& t, context& h) const;
iterator find(const t_tuple& t) const;
range<iterator> lowerUpperRange_00(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const;
range<iterator> lowerUpperRange_00(const t_tuple& /* lower */, const t_tuple& /* upper */) const;
range<t_ind_0::iterator> lowerUpperRange_11(const t_tuple& lower, const t_tuple& upper, context& h) const;
range<t_ind_0::iterator> lowerUpperRange_11(const t_tuple& lower, const t_tuple& upper) const;
bool empty() const;
std::vector<range<iterator>> partition() const;
void purge();
iterator begin() const;
iterator end() const;
void printStatistics(std::ostream& o) const;
};
} // namespace souffle::t_btree_ii__0_1__11 
namespace souffle::t_btree_ii__0_1__11 {
using namespace souffle;
using t_ind_0 = Type::t_ind_0;
using iterator = Type::iterator;
using context = Type::context;
bool Type::insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool Type::insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0_lower)) {
return true;
} else return false;
}
bool Type::insert(const RamDomain* ramDomain) {
RamDomain data[2];
std::copy(ramDomain, ramDomain + 2, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool Type::insert(RamDomain a0,RamDomain a1) {
RamDomain data[2] = {a0,a1};
return insert(data);
}
bool Type::contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0_lower);
}
bool Type::contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t Type::size() const {
return ind_0.size();
}
iterator Type::find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0_lower);
}
iterator Type::find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> Type::lowerUpperRange_00(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> Type::lowerUpperRange_00(const t_tuple& /* lower */, const t_tuple& /* upper */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> Type::lowerUpperRange_11(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_0 comparator;
int cmp = comparator(lower, upper);
if (cmp == 0) {
    auto pos = ind_0.find(lower, h.hints_0_lower);
    auto fin = ind_0.end();
    if (pos != fin) {fin = pos; ++fin;}
    return make_range(pos, fin);
}
if (cmp > 0) {
    return make_range(ind_0.end(), ind_0.end());
}
return make_range(ind_0.lower_bound(lower, h.hints_0_lower), ind_0.upper_bound(upper, h.hints_0_upper));
}
range<t_ind_0::iterator> Type::lowerUpperRange_11(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_11(lower,upper,h);
}
bool Type::empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> Type::partition() const {
return ind_0.getChunks(400);
}
void Type::purge() {
ind_0.clear();
}
iterator Type::begin() const {
return ind_0.begin();
}
iterator Type::end() const {
return ind_0.end();
}
void Type::printStatistics(std::ostream& o) const {
o << " arity 2 direct b-tree index 0 lex-order [0,1]\n";
ind_0.printStats(o);
}
} // namespace souffle::t_btree_ii__0_1__11 
namespace souffle::t_btree_iii__0_1_2__111 {
using namespace souffle;
struct Type {
static constexpr Relation::arity_type Arity = 3;
using t_tuple = Tuple<RamDomain, 3>;
struct t_comparator_0{
 int operator()(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0])) ? -1 : (ramBitCast<RamSigned>(a[0]) > ramBitCast<RamSigned>(b[0])) ? 1 :((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1])) ? -1 : (ramBitCast<RamSigned>(a[1]) > ramBitCast<RamSigned>(b[1])) ? 1 :((ramBitCast<RamSigned>(a[2]) < ramBitCast<RamSigned>(b[2])) ? -1 : (ramBitCast<RamSigned>(a[2]) > ramBitCast<RamSigned>(b[2])) ? 1 :(0)));
 }
bool less(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0]))|| ((ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0])) && ((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1]))|| ((ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1])) && ((ramBitCast<RamSigned>(a[2]) < ramBitCast<RamSigned>(b[2]))))));
 }
bool equal(const t_tuple& a, const t_tuple& b) const {
return (ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0]))&&(ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1]))&&(ramBitCast<RamSigned>(a[2]) == ramBitCast<RamSigned>(b[2]));
 }
};
using t_ind_0 = btree_set<t_tuple,t_comparator_0>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0_lower;
t_ind_0::operation_hints hints_0_upper;
};
context createContext() { return context(); }
bool insert(const t_tuple& t);
bool insert(const t_tuple& t, context& h);
bool insert(const RamDomain* ramDomain);
bool insert(RamDomain a0,RamDomain a1,RamDomain a2);
bool contains(const t_tuple& t, context& h) const;
bool contains(const t_tuple& t) const;
std::size_t size() const;
iterator find(const t_tuple& t, context& h) const;
iterator find(const t_tuple& t) const;
range<iterator> lowerUpperRange_000(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const;
range<iterator> lowerUpperRange_000(const t_tuple& /* lower */, const t_tuple& /* upper */) const;
range<t_ind_0::iterator> lowerUpperRange_111(const t_tuple& lower, const t_tuple& upper, context& h) const;
range<t_ind_0::iterator> lowerUpperRange_111(const t_tuple& lower, const t_tuple& upper) const;
bool empty() const;
std::vector<range<iterator>> partition() const;
void purge();
iterator begin() const;
iterator end() const;
void printStatistics(std::ostream& o) const;
};
} // namespace souffle::t_btree_iii__0_1_2__111 
namespace souffle::t_btree_iii__0_1_2__111 {
using namespace souffle;
using t_ind_0 = Type::t_ind_0;
using iterator = Type::iterator;
using context = Type::context;
bool Type::insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool Type::insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0_lower)) {
return true;
} else return false;
}
bool Type::insert(const RamDomain* ramDomain) {
RamDomain data[3];
std::copy(ramDomain, ramDomain + 3, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool Type::insert(RamDomain a0,RamDomain a1,RamDomain a2) {
RamDomain data[3] = {a0,a1,a2};
return insert(data);
}
bool Type::contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0_lower);
}
bool Type::contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t Type::size() const {
return ind_0.size();
}
iterator Type::find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0_lower);
}
iterator Type::find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> Type::lowerUpperRange_000(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> Type::lowerUpperRange_000(const t_tuple& /* lower */, const t_tuple& /* upper */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> Type::lowerUpperRange_111(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_0 comparator;
int cmp = comparator(lower, upper);
if (cmp == 0) {
    auto pos = ind_0.find(lower, h.hints_0_lower);
    auto fin = ind_0.end();
    if (pos != fin) {fin = pos; ++fin;}
    return make_range(pos, fin);
}
if (cmp > 0) {
    return make_range(ind_0.end(), ind_0.end());
}
return make_range(ind_0.lower_bound(lower, h.hints_0_lower), ind_0.upper_bound(upper, h.hints_0_upper));
}
range<t_ind_0::iterator> Type::lowerUpperRange_111(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_111(lower,upper,h);
}
bool Type::empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> Type::partition() const {
return ind_0.getChunks(400);
}
void Type::purge() {
ind_0.clear();
}
iterator Type::begin() const {
return ind_0.begin();
}
iterator Type::end() const {
return ind_0.end();
}
void Type::printStatistics(std::ostream& o) const {
o << " arity 3 direct b-tree index 0 lex-order [0,1,2]\n";
ind_0.printStats(o);
}
} // namespace souffle::t_btree_iii__0_1_2__111 
namespace souffle::t_btree_iii__0_2_1__101__111 {
using namespace souffle;
struct Type {
static constexpr Relation::arity_type Arity = 3;
using t_tuple = Tuple<RamDomain, 3>;
struct t_comparator_0{
 int operator()(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0])) ? -1 : (ramBitCast<RamSigned>(a[0]) > ramBitCast<RamSigned>(b[0])) ? 1 :((ramBitCast<RamSigned>(a[2]) < ramBitCast<RamSigned>(b[2])) ? -1 : (ramBitCast<RamSigned>(a[2]) > ramBitCast<RamSigned>(b[2])) ? 1 :((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1])) ? -1 : (ramBitCast<RamSigned>(a[1]) > ramBitCast<RamSigned>(b[1])) ? 1 :(0)));
 }
bool less(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0]))|| ((ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0])) && ((ramBitCast<RamSigned>(a[2]) < ramBitCast<RamSigned>(b[2]))|| ((ramBitCast<RamSigned>(a[2]) == ramBitCast<RamSigned>(b[2])) && ((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1]))))));
 }
bool equal(const t_tuple& a, const t_tuple& b) const {
return (ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0]))&&(ramBitCast<RamSigned>(a[2]) == ramBitCast<RamSigned>(b[2]))&&(ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1]));
 }
};
using t_ind_0 = btree_set<t_tuple,t_comparator_0>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0_lower;
t_ind_0::operation_hints hints_0_upper;
};
context createContext() { return context(); }
bool insert(const t_tuple& t);
bool insert(const t_tuple& t, context& h);
bool insert(const RamDomain* ramDomain);
bool insert(RamDomain a0,RamDomain a1,RamDomain a2);
bool contains(const t_tuple& t, context& h) const;
bool contains(const t_tuple& t) const;
std::size_t size() const;
iterator find(const t_tuple& t, context& h) const;
iterator find(const t_tuple& t) const;
range<iterator> lowerUpperRange_000(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const;
range<iterator> lowerUpperRange_000(const t_tuple& /* lower */, const t_tuple& /* upper */) const;
range<t_ind_0::iterator> lowerUpperRange_101(const t_tuple& lower, const t_tuple& upper, context& h) const;
range<t_ind_0::iterator> lowerUpperRange_101(const t_tuple& lower, const t_tuple& upper) const;
range<t_ind_0::iterator> lowerUpperRange_111(const t_tuple& lower, const t_tuple& upper, context& h) const;
range<t_ind_0::iterator> lowerUpperRange_111(const t_tuple& lower, const t_tuple& upper) const;
bool empty() const;
std::vector<range<iterator>> partition() const;
void purge();
iterator begin() const;
iterator end() const;
void printStatistics(std::ostream& o) const;
};
} // namespace souffle::t_btree_iii__0_2_1__101__111 
namespace souffle::t_btree_iii__0_2_1__101__111 {
using namespace souffle;
using t_ind_0 = Type::t_ind_0;
using iterator = Type::iterator;
using context = Type::context;
bool Type::insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool Type::insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0_lower)) {
return true;
} else return false;
}
bool Type::insert(const RamDomain* ramDomain) {
RamDomain data[3];
std::copy(ramDomain, ramDomain + 3, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool Type::insert(RamDomain a0,RamDomain a1,RamDomain a2) {
RamDomain data[3] = {a0,a1,a2};
return insert(data);
}
bool Type::contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0_lower);
}
bool Type::contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t Type::size() const {
return ind_0.size();
}
iterator Type::find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0_lower);
}
iterator Type::find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> Type::lowerUpperRange_000(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> Type::lowerUpperRange_000(const t_tuple& /* lower */, const t_tuple& /* upper */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> Type::lowerUpperRange_101(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_0 comparator;
int cmp = comparator(lower, upper);
if (cmp > 0) {
    return make_range(ind_0.end(), ind_0.end());
}
return make_range(ind_0.lower_bound(lower, h.hints_0_lower), ind_0.upper_bound(upper, h.hints_0_upper));
}
range<t_ind_0::iterator> Type::lowerUpperRange_101(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_101(lower,upper,h);
}
range<t_ind_0::iterator> Type::lowerUpperRange_111(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_0 comparator;
int cmp = comparator(lower, upper);
if (cmp == 0) {
    auto pos = ind_0.find(lower, h.hints_0_lower);
    auto fin = ind_0.end();
    if (pos != fin) {fin = pos; ++fin;}
    return make_range(pos, fin);
}
if (cmp > 0) {
    return make_range(ind_0.end(), ind_0.end());
}
return make_range(ind_0.lower_bound(lower, h.hints_0_lower), ind_0.upper_bound(upper, h.hints_0_upper));
}
range<t_ind_0::iterator> Type::lowerUpperRange_111(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_111(lower,upper,h);
}
bool Type::empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> Type::partition() const {
return ind_0.getChunks(400);
}
void Type::purge() {
ind_0.clear();
}
iterator Type::begin() const {
return ind_0.begin();
}
iterator Type::end() const {
return ind_0.end();
}
void Type::printStatistics(std::ostream& o) const {
o << " arity 3 direct b-tree index 0 lex-order [0,2,1]\n";
ind_0.printStats(o);
}
} // namespace souffle::t_btree_iii__0_2_1__101__111 
namespace souffle::t_btree_iiii__0_1_2_3__1111 {
using namespace souffle;
struct Type {
static constexpr Relation::arity_type Arity = 4;
using t_tuple = Tuple<RamDomain, 4>;
struct t_comparator_0{
 int operator()(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0])) ? -1 : (ramBitCast<RamSigned>(a[0]) > ramBitCast<RamSigned>(b[0])) ? 1 :((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1])) ? -1 : (ramBitCast<RamSigned>(a[1]) > ramBitCast<RamSigned>(b[1])) ? 1 :((ramBitCast<RamSigned>(a[2]) < ramBitCast<RamSigned>(b[2])) ? -1 : (ramBitCast<RamSigned>(a[2]) > ramBitCast<RamSigned>(b[2])) ? 1 :((ramBitCast<RamSigned>(a[3]) < ramBitCast<RamSigned>(b[3])) ? -1 : (ramBitCast<RamSigned>(a[3]) > ramBitCast<RamSigned>(b[3])) ? 1 :(0))));
 }
bool less(const t_tuple& a, const t_tuple& b) const {
  return (ramBitCast<RamSigned>(a[0]) < ramBitCast<RamSigned>(b[0]))|| ((ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0])) && ((ramBitCast<RamSigned>(a[1]) < ramBitCast<RamSigned>(b[1]))|| ((ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1])) && ((ramBitCast<RamSigned>(a[2]) < ramBitCast<RamSigned>(b[2]))|| ((ramBitCast<RamSigned>(a[2]) == ramBitCast<RamSigned>(b[2])) && ((ramBitCast<RamSigned>(a[3]) < ramBitCast<RamSigned>(b[3]))))))));
 }
bool equal(const t_tuple& a, const t_tuple& b) const {
return (ramBitCast<RamSigned>(a[0]) == ramBitCast<RamSigned>(b[0]))&&(ramBitCast<RamSigned>(a[1]) == ramBitCast<RamSigned>(b[1]))&&(ramBitCast<RamSigned>(a[2]) == ramBitCast<RamSigned>(b[2]))&&(ramBitCast<RamSigned>(a[3]) == ramBitCast<RamSigned>(b[3]));
 }
};
using t_ind_0 = btree_set<t_tuple,t_comparator_0>;
t_ind_0 ind_0;
using iterator = t_ind_0::iterator;
struct context {
t_ind_0::operation_hints hints_0_lower;
t_ind_0::operation_hints hints_0_upper;
};
context createContext() { return context(); }
bool insert(const t_tuple& t);
bool insert(const t_tuple& t, context& h);
bool insert(const RamDomain* ramDomain);
bool insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3);
bool contains(const t_tuple& t, context& h) const;
bool contains(const t_tuple& t) const;
std::size_t size() const;
iterator find(const t_tuple& t, context& h) const;
iterator find(const t_tuple& t) const;
range<iterator> lowerUpperRange_0000(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const;
range<iterator> lowerUpperRange_0000(const t_tuple& /* lower */, const t_tuple& /* upper */) const;
range<t_ind_0::iterator> lowerUpperRange_1111(const t_tuple& lower, const t_tuple& upper, context& h) const;
range<t_ind_0::iterator> lowerUpperRange_1111(const t_tuple& lower, const t_tuple& upper) const;
bool empty() const;
std::vector<range<iterator>> partition() const;
void purge();
iterator begin() const;
iterator end() const;
void printStatistics(std::ostream& o) const;
};
} // namespace souffle::t_btree_iiii__0_1_2_3__1111 
namespace souffle::t_btree_iiii__0_1_2_3__1111 {
using namespace souffle;
using t_ind_0 = Type::t_ind_0;
using iterator = Type::iterator;
using context = Type::context;
bool Type::insert(const t_tuple& t) {
context h;
return insert(t, h);
}
bool Type::insert(const t_tuple& t, context& h) {
if (ind_0.insert(t, h.hints_0_lower)) {
return true;
} else return false;
}
bool Type::insert(const RamDomain* ramDomain) {
RamDomain data[4];
std::copy(ramDomain, ramDomain + 4, data);
const t_tuple& tuple = reinterpret_cast<const t_tuple&>(data);
context h;
return insert(tuple, h);
}
bool Type::insert(RamDomain a0,RamDomain a1,RamDomain a2,RamDomain a3) {
RamDomain data[4] = {a0,a1,a2,a3};
return insert(data);
}
bool Type::contains(const t_tuple& t, context& h) const {
return ind_0.contains(t, h.hints_0_lower);
}
bool Type::contains(const t_tuple& t) const {
context h;
return contains(t, h);
}
std::size_t Type::size() const {
return ind_0.size();
}
iterator Type::find(const t_tuple& t, context& h) const {
return ind_0.find(t, h.hints_0_lower);
}
iterator Type::find(const t_tuple& t) const {
context h;
return find(t, h);
}
range<iterator> Type::lowerUpperRange_0000(const t_tuple& /* lower */, const t_tuple& /* upper */, context& /* h */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<iterator> Type::lowerUpperRange_0000(const t_tuple& /* lower */, const t_tuple& /* upper */) const {
return range<iterator>(ind_0.begin(),ind_0.end());
}
range<t_ind_0::iterator> Type::lowerUpperRange_1111(const t_tuple& lower, const t_tuple& upper, context& h) const {
t_comparator_0 comparator;
int cmp = comparator(lower, upper);
if (cmp == 0) {
    auto pos = ind_0.find(lower, h.hints_0_lower);
    auto fin = ind_0.end();
    if (pos != fin) {fin = pos; ++fin;}
    return make_range(pos, fin);
}
if (cmp > 0) {
    return make_range(ind_0.end(), ind_0.end());
}
return make_range(ind_0.lower_bound(lower, h.hints_0_lower), ind_0.upper_bound(upper, h.hints_0_upper));
}
range<t_ind_0::iterator> Type::lowerUpperRange_1111(const t_tuple& lower, const t_tuple& upper) const {
context h;
return lowerUpperRange_1111(lower,upper,h);
}
bool Type::empty() const {
return ind_0.empty();
}
std::vector<range<iterator>> Type::partition() const {
return ind_0.getChunks(400);
}
void Type::purge() {
ind_0.clear();
}
iterator Type::begin() const {
return ind_0.begin();
}
iterator Type::end() const {
return ind_0.end();
}
void Type::printStatistics(std::ostream& o) const {
o << " arity 4 direct b-tree index 0 lex-order [0,1,2,3]\n";
ind_0.printStats(o);
}
} // namespace souffle::t_btree_iiii__0_1_2_3__1111 
namespace  souffle {
using namespace souffle;
class Stratum_disconnected0_92d53886cb6eda8a {
public:
 Stratum_disconnected0_92d53886cb6eda8a(SymbolTable& symTable,RecordTable& recordTable,ConcurrentCache<std::string,std::regex>& regexCache,bool& pruneImdtRels,bool& performIO,SignalHandler*& signalHandler,std::atomic<std::size_t>& iter,std::atomic<RamDomain>& ctr,std::string& inputDirectory,std::string& outputDirectory,t_nullaries& rel_disconnected0_615a847368b8df77,t_nullaries& rel_disconnected1_615a837368b8ddc4,t_nullaries& rel_disconnected2_615a867368b8e2dd,t_nullaries& rel_delta_disconnected0_3b2fbdedaad9411a,t_nullaries& rel_delta_disconnected1_3b2fbeedaad942cd,t_nullaries& rel_delta_disconnected2_3b2fbbedaad93db4,t_btree_ii__0_1__11::Type& rel_delta_AgentInitComplete_851d2e5f48d18d54,t_btree_iii__0_2_1__101__111::Type& rel_delta_Finish_a44c45a10dcdc5f7,t_btree_iiii__0_1_2_3__1111::Type& rel_delta_IntAttrInstance_b8fdf596d9aeece1,t_btree_ii__0_1__11::Type& rel_delta_Start_4a3bb0b3286f88b4,t_nullaries& rel_new_disconnected0_811c6a653f6f04c2,t_nullaries& rel_new_disconnected1_811c6b653f6f0675,t_nullaries& rel_new_disconnected2_811c68653f6f015c,t_btree_ii__0_1__11::Type& rel_new_AgentInitComplete_5e2c310bdba794cc,t_btree_iii__0_2_1__101__111::Type& rel_new_Finish_669fdb18649c352f,t_btree_iiii__0_1_2_3__1111::Type& rel_new_IntAttrInstance_46c3e1da2b668339,t_btree_ii__0_1__11::Type& rel_new_Start_8d183a7aef9127dc,t_btree_ii__0_1__11::Type& rel_ActionComplete_274fcea6d3a4990c,t_btree_ii__0_1__11::Type& rel_AgentInitComplete_bc76db663593fd33,t_btree_iii__0_1_2__111::Type& rel_Finish_ad59707375956ad2,t_btree_iii__0_1_2__111::Type& rel_IntAttr_9edc9675b07c35fd,t_btree_iiii__0_1_2_3__1111::Type& rel_IntAttrInstance_b534d52673393a7a,t_btree_iii__0_1_2__110__111::Type& rel_Parent_4eb514ebcb80553d,t_btree_iii__0_1_2__111::Type& rel_Precede_3d173237b8f1e4e1,t_btree_ii__0_1__11::Type& rel_Start_ae1c7f13b7c0c47f);
void run([[maybe_unused]] const std::vector<RamDomain>& args,[[maybe_unused]] std::vector<RamDomain>& ret);
private:
SymbolTable& symTable;
RecordTable& recordTable;
ConcurrentCache<std::string,std::regex>& regexCache;
bool& pruneImdtRels;
bool& performIO;
SignalHandler*& signalHandler;
std::atomic<std::size_t>& iter;
std::atomic<RamDomain>& ctr;
std::string& inputDirectory;
std::string& outputDirectory;
t_nullaries* rel_disconnected0_615a847368b8df77;
t_nullaries* rel_disconnected1_615a837368b8ddc4;
t_nullaries* rel_disconnected2_615a867368b8e2dd;
t_nullaries* rel_delta_disconnected0_3b2fbdedaad9411a;
t_nullaries* rel_delta_disconnected1_3b2fbeedaad942cd;
t_nullaries* rel_delta_disconnected2_3b2fbbedaad93db4;
t_btree_ii__0_1__11::Type* rel_delta_AgentInitComplete_851d2e5f48d18d54;
t_btree_iii__0_2_1__101__111::Type* rel_delta_Finish_a44c45a10dcdc5f7;
t_btree_iiii__0_1_2_3__1111::Type* rel_delta_IntAttrInstance_b8fdf596d9aeece1;
t_btree_ii__0_1__11::Type* rel_delta_Start_4a3bb0b3286f88b4;
t_nullaries* rel_new_disconnected0_811c6a653f6f04c2;
t_nullaries* rel_new_disconnected1_811c6b653f6f0675;
t_nullaries* rel_new_disconnected2_811c68653f6f015c;
t_btree_ii__0_1__11::Type* rel_new_AgentInitComplete_5e2c310bdba794cc;
t_btree_iii__0_2_1__101__111::Type* rel_new_Finish_669fdb18649c352f;
t_btree_iiii__0_1_2_3__1111::Type* rel_new_IntAttrInstance_46c3e1da2b668339;
t_btree_ii__0_1__11::Type* rel_new_Start_8d183a7aef9127dc;
t_btree_ii__0_1__11::Type* rel_ActionComplete_274fcea6d3a4990c;
t_btree_ii__0_1__11::Type* rel_AgentInitComplete_bc76db663593fd33;
t_btree_iii__0_1_2__111::Type* rel_Finish_ad59707375956ad2;
t_btree_iii__0_1_2__111::Type* rel_IntAttr_9edc9675b07c35fd;
t_btree_iiii__0_1_2_3__1111::Type* rel_IntAttrInstance_b534d52673393a7a;
t_btree_iii__0_1_2__110__111::Type* rel_Parent_4eb514ebcb80553d;
t_btree_iii__0_1_2__111::Type* rel_Precede_3d173237b8f1e4e1;
t_btree_ii__0_1__11::Type* rel_Start_ae1c7f13b7c0c47f;
};
} // namespace  souffle
namespace  souffle {
using namespace souffle;
 Stratum_disconnected0_92d53886cb6eda8a::Stratum_disconnected0_92d53886cb6eda8a(SymbolTable& symTable,RecordTable& recordTable,ConcurrentCache<std::string,std::regex>& regexCache,bool& pruneImdtRels,bool& performIO,SignalHandler*& signalHandler,std::atomic<std::size_t>& iter,std::atomic<RamDomain>& ctr,std::string& inputDirectory,std::string& outputDirectory,t_nullaries& rel_disconnected0_615a847368b8df77,t_nullaries& rel_disconnected1_615a837368b8ddc4,t_nullaries& rel_disconnected2_615a867368b8e2dd,t_nullaries& rel_delta_disconnected0_3b2fbdedaad9411a,t_nullaries& rel_delta_disconnected1_3b2fbeedaad942cd,t_nullaries& rel_delta_disconnected2_3b2fbbedaad93db4,t_btree_ii__0_1__11::Type& rel_delta_AgentInitComplete_851d2e5f48d18d54,t_btree_iii__0_2_1__101__111::Type& rel_delta_Finish_a44c45a10dcdc5f7,t_btree_iiii__0_1_2_3__1111::Type& rel_delta_IntAttrInstance_b8fdf596d9aeece1,t_btree_ii__0_1__11::Type& rel_delta_Start_4a3bb0b3286f88b4,t_nullaries& rel_new_disconnected0_811c6a653f6f04c2,t_nullaries& rel_new_disconnected1_811c6b653f6f0675,t_nullaries& rel_new_disconnected2_811c68653f6f015c,t_btree_ii__0_1__11::Type& rel_new_AgentInitComplete_5e2c310bdba794cc,t_btree_iii__0_2_1__101__111::Type& rel_new_Finish_669fdb18649c352f,t_btree_iiii__0_1_2_3__1111::Type& rel_new_IntAttrInstance_46c3e1da2b668339,t_btree_ii__0_1__11::Type& rel_new_Start_8d183a7aef9127dc,t_btree_ii__0_1__11::Type& rel_ActionComplete_274fcea6d3a4990c,t_btree_ii__0_1__11::Type& rel_AgentInitComplete_bc76db663593fd33,t_btree_iii__0_1_2__111::Type& rel_Finish_ad59707375956ad2,t_btree_iii__0_1_2__111::Type& rel_IntAttr_9edc9675b07c35fd,t_btree_iiii__0_1_2_3__1111::Type& rel_IntAttrInstance_b534d52673393a7a,t_btree_iii__0_1_2__110__111::Type& rel_Parent_4eb514ebcb80553d,t_btree_iii__0_1_2__111::Type& rel_Precede_3d173237b8f1e4e1,t_btree_ii__0_1__11::Type& rel_Start_ae1c7f13b7c0c47f):
symTable(symTable),
recordTable(recordTable),
regexCache(regexCache),
pruneImdtRels(pruneImdtRels),
performIO(performIO),
signalHandler(signalHandler),
iter(iter),
ctr(ctr),
inputDirectory(inputDirectory),
outputDirectory(outputDirectory),
rel_disconnected0_615a847368b8df77(&rel_disconnected0_615a847368b8df77),
rel_disconnected1_615a837368b8ddc4(&rel_disconnected1_615a837368b8ddc4),
rel_disconnected2_615a867368b8e2dd(&rel_disconnected2_615a867368b8e2dd),
rel_delta_disconnected0_3b2fbdedaad9411a(&rel_delta_disconnected0_3b2fbdedaad9411a),
rel_delta_disconnected1_3b2fbeedaad942cd(&rel_delta_disconnected1_3b2fbeedaad942cd),
rel_delta_disconnected2_3b2fbbedaad93db4(&rel_delta_disconnected2_3b2fbbedaad93db4),
rel_delta_AgentInitComplete_851d2e5f48d18d54(&rel_delta_AgentInitComplete_851d2e5f48d18d54),
rel_delta_Finish_a44c45a10dcdc5f7(&rel_delta_Finish_a44c45a10dcdc5f7),
rel_delta_IntAttrInstance_b8fdf596d9aeece1(&rel_delta_IntAttrInstance_b8fdf596d9aeece1),
rel_delta_Start_4a3bb0b3286f88b4(&rel_delta_Start_4a3bb0b3286f88b4),
rel_new_disconnected0_811c6a653f6f04c2(&rel_new_disconnected0_811c6a653f6f04c2),
rel_new_disconnected1_811c6b653f6f0675(&rel_new_disconnected1_811c6b653f6f0675),
rel_new_disconnected2_811c68653f6f015c(&rel_new_disconnected2_811c68653f6f015c),
rel_new_AgentInitComplete_5e2c310bdba794cc(&rel_new_AgentInitComplete_5e2c310bdba794cc),
rel_new_Finish_669fdb18649c352f(&rel_new_Finish_669fdb18649c352f),
rel_new_IntAttrInstance_46c3e1da2b668339(&rel_new_IntAttrInstance_46c3e1da2b668339),
rel_new_Start_8d183a7aef9127dc(&rel_new_Start_8d183a7aef9127dc),
rel_ActionComplete_274fcea6d3a4990c(&rel_ActionComplete_274fcea6d3a4990c),
rel_AgentInitComplete_bc76db663593fd33(&rel_AgentInitComplete_bc76db663593fd33),
rel_Finish_ad59707375956ad2(&rel_Finish_ad59707375956ad2),
rel_IntAttr_9edc9675b07c35fd(&rel_IntAttr_9edc9675b07c35fd),
rel_IntAttrInstance_b534d52673393a7a(&rel_IntAttrInstance_b534d52673393a7a),
rel_Parent_4eb514ebcb80553d(&rel_Parent_4eb514ebcb80553d),
rel_Precede_3d173237b8f1e4e1(&rel_Precede_3d173237b8f1e4e1),
rel_Start_ae1c7f13b7c0c47f(&rel_Start_ae1c7f13b7c0c47f){
}

void Stratum_disconnected0_92d53886cb6eda8a::run([[maybe_unused]] const std::vector<RamDomain>& args,[[maybe_unused]] std::vector<RamDomain>& ret){
if(!(rel_disconnected0_615a847368b8df77->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_delta_disconnected0_3b2fbdedaad9411a_op_ctxt,rel_delta_disconnected0_3b2fbdedaad9411a->createContext());
Tuple<RamDomain,0> tuple{{}};
rel_delta_disconnected0_3b2fbdedaad9411a->insert(tuple,READ_OP_CONTEXT(rel_delta_disconnected0_3b2fbdedaad9411a_op_ctxt));
}
();}
if(!(rel_disconnected1_615a837368b8ddc4->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_delta_disconnected1_3b2fbeedaad942cd_op_ctxt,rel_delta_disconnected1_3b2fbeedaad942cd->createContext());
Tuple<RamDomain,0> tuple{{}};
rel_delta_disconnected1_3b2fbeedaad942cd->insert(tuple,READ_OP_CONTEXT(rel_delta_disconnected1_3b2fbeedaad942cd_op_ctxt));
}
();}
if(!(rel_disconnected2_615a867368b8e2dd->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_delta_disconnected2_3b2fbbedaad93db4_op_ctxt,rel_delta_disconnected2_3b2fbbedaad93db4->createContext());
Tuple<RamDomain,0> tuple{{}};
rel_delta_disconnected2_3b2fbbedaad93db4->insert(tuple,READ_OP_CONTEXT(rel_delta_disconnected2_3b2fbbedaad93db4_op_ctxt));
}
();}
[&](){
CREATE_OP_CONTEXT(rel_delta_AgentInitComplete_851d2e5f48d18d54_op_ctxt,rel_delta_AgentInitComplete_851d2e5f48d18d54->createContext());
CREATE_OP_CONTEXT(rel_AgentInitComplete_bc76db663593fd33_op_ctxt,rel_AgentInitComplete_bc76db663593fd33->createContext());
for(const auto& env0 : *rel_AgentInitComplete_bc76db663593fd33) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(env0[1])}};
rel_delta_AgentInitComplete_851d2e5f48d18d54->insert(tuple,READ_OP_CONTEXT(rel_delta_AgentInitComplete_851d2e5f48d18d54_op_ctxt));
}
}
();[&](){
CREATE_OP_CONTEXT(rel_delta_Finish_a44c45a10dcdc5f7_op_ctxt,rel_delta_Finish_a44c45a10dcdc5f7->createContext());
CREATE_OP_CONTEXT(rel_Finish_ad59707375956ad2_op_ctxt,rel_Finish_ad59707375956ad2->createContext());
for(const auto& env0 : *rel_Finish_ad59707375956ad2) {
Tuple<RamDomain,3> tuple{{ramBitCast(env0[0]),ramBitCast(env0[1]),ramBitCast(env0[2])}};
rel_delta_Finish_a44c45a10dcdc5f7->insert(tuple,READ_OP_CONTEXT(rel_delta_Finish_a44c45a10dcdc5f7_op_ctxt));
}
}
();[&](){
CREATE_OP_CONTEXT(rel_delta_IntAttrInstance_b8fdf596d9aeece1_op_ctxt,rel_delta_IntAttrInstance_b8fdf596d9aeece1->createContext());
CREATE_OP_CONTEXT(rel_IntAttrInstance_b534d52673393a7a_op_ctxt,rel_IntAttrInstance_b534d52673393a7a->createContext());
for(const auto& env0 : *rel_IntAttrInstance_b534d52673393a7a) {
Tuple<RamDomain,4> tuple{{ramBitCast(env0[0]),ramBitCast(env0[1]),ramBitCast(env0[2]),ramBitCast(env0[3])}};
rel_delta_IntAttrInstance_b8fdf596d9aeece1->insert(tuple,READ_OP_CONTEXT(rel_delta_IntAttrInstance_b8fdf596d9aeece1_op_ctxt));
}
}
();[&](){
CREATE_OP_CONTEXT(rel_delta_Start_4a3bb0b3286f88b4_op_ctxt,rel_delta_Start_4a3bb0b3286f88b4->createContext());
CREATE_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt,rel_Start_ae1c7f13b7c0c47f->createContext());
for(const auto& env0 : *rel_Start_ae1c7f13b7c0c47f) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(env0[1])}};
rel_delta_Start_4a3bb0b3286f88b4->insert(tuple,READ_OP_CONTEXT(rel_delta_Start_4a3bb0b3286f88b4_op_ctxt));
}
}
();auto loop_counter = RamUnsigned(1);
iter = 0;
for(;;) {
signalHandler->setMsg(R"_(+disconnected0() :- 
   Parent("ruleDemo",0,node2),
   Finish("ruleDemo",node2,1).
in file bttest.dl [45:1-46:60])_");
if(!(rel_Parent_4eb514ebcb80553d->empty()) && !(rel_delta_Finish_a44c45a10dcdc5f7->empty()) && rel_new_disconnected0_811c6a653f6f04c2->empty() && rel_disconnected0_615a847368b8df77->empty()) {
[&](){
CREATE_OP_CONTEXT(rel_delta_Finish_a44c45a10dcdc5f7_op_ctxt,rel_delta_Finish_a44c45a10dcdc5f7->createContext());
CREATE_OP_CONTEXT(rel_new_disconnected0_811c6a653f6f04c2_op_ctxt,rel_new_disconnected0_811c6a653f6f04c2->createContext());
CREATE_OP_CONTEXT(rel_Parent_4eb514ebcb80553d_op_ctxt,rel_Parent_4eb514ebcb80553d->createContext());
auto range = rel_Parent_4eb514ebcb80553d->lowerUpperRange_110(Tuple<RamDomain,3>{{ramBitCast(RamSigned(0)), ramBitCast(RamSigned(0)), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,3>{{ramBitCast(RamSigned(0)), ramBitCast(RamSigned(0)), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_Parent_4eb514ebcb80553d_op_ctxt));
for(const auto& env0 : range) {
if( !(rel_new_disconnected0_811c6a653f6f04c2->empty())) break;
if( rel_delta_Finish_a44c45a10dcdc5f7->contains(Tuple<RamDomain,3>{{ramBitCast(RamSigned(0)),ramBitCast(env0[2]),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_delta_Finish_a44c45a10dcdc5f7_op_ctxt))) {
Tuple<RamDomain,0> tuple{{}};
rel_new_disconnected0_811c6a653f6f04c2->insert(tuple,READ_OP_CONTEXT(rel_new_disconnected0_811c6a653f6f04c2_op_ctxt));
}
}
}
();}
signalHandler->setMsg(R"_(+disconnected1() :- 
   Parent("ruleDemo",1,node2),
   Finish("ruleDemo",node2,1).
in file bttest.dl [54:1-55:60])_");
if(!(rel_Parent_4eb514ebcb80553d->empty()) && !(rel_delta_Finish_a44c45a10dcdc5f7->empty()) && rel_new_disconnected1_811c6b653f6f0675->empty() && rel_disconnected1_615a837368b8ddc4->empty()) {
[&](){
CREATE_OP_CONTEXT(rel_delta_Finish_a44c45a10dcdc5f7_op_ctxt,rel_delta_Finish_a44c45a10dcdc5f7->createContext());
CREATE_OP_CONTEXT(rel_new_disconnected1_811c6b653f6f0675_op_ctxt,rel_new_disconnected1_811c6b653f6f0675->createContext());
CREATE_OP_CONTEXT(rel_Parent_4eb514ebcb80553d_op_ctxt,rel_Parent_4eb514ebcb80553d->createContext());
auto range = rel_Parent_4eb514ebcb80553d->lowerUpperRange_110(Tuple<RamDomain,3>{{ramBitCast(RamSigned(0)), ramBitCast(RamSigned(1)), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,3>{{ramBitCast(RamSigned(0)), ramBitCast(RamSigned(1)), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_Parent_4eb514ebcb80553d_op_ctxt));
for(const auto& env0 : range) {
if( !(rel_new_disconnected1_811c6b653f6f0675->empty())) break;
if( rel_delta_Finish_a44c45a10dcdc5f7->contains(Tuple<RamDomain,3>{{ramBitCast(RamSigned(0)),ramBitCast(env0[2]),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_delta_Finish_a44c45a10dcdc5f7_op_ctxt))) {
Tuple<RamDomain,0> tuple{{}};
rel_new_disconnected1_811c6b653f6f0675->insert(tuple,READ_OP_CONTEXT(rel_new_disconnected1_811c6b653f6f0675_op_ctxt));
}
}
}
();}
signalHandler->setMsg(R"_(+disconnected2() :- 
   Finish("ruleDemo",node,1),
   Precede("ruleDemo",node,0).
in file bttest.dl [48:1-49:59])_");
if(!(rel_delta_Finish_a44c45a10dcdc5f7->empty()) && !(rel_Precede_3d173237b8f1e4e1->empty()) && rel_new_disconnected2_811c68653f6f015c->empty() && rel_disconnected2_615a867368b8e2dd->empty()) {
[&](){
CREATE_OP_CONTEXT(rel_delta_Finish_a44c45a10dcdc5f7_op_ctxt,rel_delta_Finish_a44c45a10dcdc5f7->createContext());
CREATE_OP_CONTEXT(rel_new_disconnected2_811c68653f6f015c_op_ctxt,rel_new_disconnected2_811c68653f6f015c->createContext());
CREATE_OP_CONTEXT(rel_Precede_3d173237b8f1e4e1_op_ctxt,rel_Precede_3d173237b8f1e4e1->createContext());
auto range = rel_delta_Finish_a44c45a10dcdc5f7->lowerUpperRange_101(Tuple<RamDomain,3>{{ramBitCast(RamSigned(0)), ramBitCast<RamDomain>(MIN_RAM_SIGNED), ramBitCast(RamSigned(1))}},Tuple<RamDomain,3>{{ramBitCast(RamSigned(0)), ramBitCast<RamDomain>(MAX_RAM_SIGNED), ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_delta_Finish_a44c45a10dcdc5f7_op_ctxt));
for(const auto& env0 : range) {
if( !(rel_new_disconnected2_811c68653f6f015c->empty())) break;
if( rel_Precede_3d173237b8f1e4e1->contains(Tuple<RamDomain,3>{{ramBitCast(RamSigned(0)),ramBitCast(env0[1]),ramBitCast(RamSigned(0))}},READ_OP_CONTEXT(rel_Precede_3d173237b8f1e4e1_op_ctxt))) {
Tuple<RamDomain,0> tuple{{}};
rel_new_disconnected2_811c68653f6f015c->insert(tuple,READ_OP_CONTEXT(rel_new_disconnected2_811c68653f6f015c_op_ctxt));
}
}
}
();}
signalHandler->setMsg(R"_(AgentInitComplete("ruleDemo","TestAgent") :- 
   IntAttrInstance("ruleDemo","TestAgent","statisticAccuracy",0).
in file bttest.dl [36:1-37:66])_");
if(!(rel_delta_IntAttrInstance_b8fdf596d9aeece1->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_delta_IntAttrInstance_b8fdf596d9aeece1_op_ctxt,rel_delta_IntAttrInstance_b8fdf596d9aeece1->createContext());
CREATE_OP_CONTEXT(rel_new_AgentInitComplete_5e2c310bdba794cc_op_ctxt,rel_new_AgentInitComplete_5e2c310bdba794cc->createContext());
CREATE_OP_CONTEXT(rel_AgentInitComplete_bc76db663593fd33_op_ctxt,rel_AgentInitComplete_bc76db663593fd33->createContext());
if(!(rel_AgentInitComplete_bc76db663593fd33->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_AgentInitComplete_bc76db663593fd33_op_ctxt))) && rel_delta_IntAttrInstance_b8fdf596d9aeece1->contains(Tuple<RamDomain,4>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1)),ramBitCast(RamSigned(2)),ramBitCast(RamSigned(0))}},READ_OP_CONTEXT(rel_delta_IntAttrInstance_b8fdf596d9aeece1_op_ctxt))) {
Tuple<RamDomain,2> tuple{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1))}};
rel_new_AgentInitComplete_5e2c310bdba794cc->insert(tuple,READ_OP_CONTEXT(rel_new_AgentInitComplete_5e2c310bdba794cc_op_ctxt));
}
}
();}
signalHandler->setMsg(R"_(Finish("ruleDemo",-2,1) :- 
   Start("ruleDemo",-1),
   AgentInitComplete("ruleDemo","TestAgent").
in file bttest.dl [39:1-40:67])_");
if(!(rel_delta_Start_4a3bb0b3286f88b4->empty()) && !(rel_AgentInitComplete_bc76db663593fd33->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_delta_AgentInitComplete_851d2e5f48d18d54_op_ctxt,rel_delta_AgentInitComplete_851d2e5f48d18d54->createContext());
CREATE_OP_CONTEXT(rel_delta_Start_4a3bb0b3286f88b4_op_ctxt,rel_delta_Start_4a3bb0b3286f88b4->createContext());
CREATE_OP_CONTEXT(rel_new_Finish_669fdb18649c352f_op_ctxt,rel_new_Finish_669fdb18649c352f->createContext());
CREATE_OP_CONTEXT(rel_AgentInitComplete_bc76db663593fd33_op_ctxt,rel_AgentInitComplete_bc76db663593fd33->createContext());
CREATE_OP_CONTEXT(rel_Finish_ad59707375956ad2_op_ctxt,rel_Finish_ad59707375956ad2->createContext());
if(!(rel_delta_AgentInitComplete_851d2e5f48d18d54->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_delta_AgentInitComplete_851d2e5f48d18d54_op_ctxt))) && rel_AgentInitComplete_bc76db663593fd33->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_AgentInitComplete_bc76db663593fd33_op_ctxt)) && !(rel_Finish_ad59707375956ad2->contains(Tuple<RamDomain,3>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(-2)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_Finish_ad59707375956ad2_op_ctxt))) && rel_delta_Start_4a3bb0b3286f88b4->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(-1))}},READ_OP_CONTEXT(rel_delta_Start_4a3bb0b3286f88b4_op_ctxt))) {
Tuple<RamDomain,3> tuple{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(-2)),ramBitCast(RamSigned(1))}};
rel_new_Finish_669fdb18649c352f->insert(tuple,READ_OP_CONTEXT(rel_new_Finish_669fdb18649c352f_op_ctxt));
}
}
();}
signalHandler->setMsg(R"_(Finish("ruleDemo",-2,1) :- 
   Start("ruleDemo",-1),
   AgentInitComplete("ruleDemo","TestAgent").
in file bttest.dl [39:1-40:67])_");
if(!(rel_Start_ae1c7f13b7c0c47f->empty()) && !(rel_delta_AgentInitComplete_851d2e5f48d18d54->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_delta_AgentInitComplete_851d2e5f48d18d54_op_ctxt,rel_delta_AgentInitComplete_851d2e5f48d18d54->createContext());
CREATE_OP_CONTEXT(rel_new_Finish_669fdb18649c352f_op_ctxt,rel_new_Finish_669fdb18649c352f->createContext());
CREATE_OP_CONTEXT(rel_Finish_ad59707375956ad2_op_ctxt,rel_Finish_ad59707375956ad2->createContext());
CREATE_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt,rel_Start_ae1c7f13b7c0c47f->createContext());
if(!(rel_Finish_ad59707375956ad2->contains(Tuple<RamDomain,3>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(-2)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_Finish_ad59707375956ad2_op_ctxt))) && rel_delta_AgentInitComplete_851d2e5f48d18d54->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_delta_AgentInitComplete_851d2e5f48d18d54_op_ctxt)) && rel_Start_ae1c7f13b7c0c47f->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(-1))}},READ_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt))) {
Tuple<RamDomain,3> tuple{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(-2)),ramBitCast(RamSigned(1))}};
rel_new_Finish_669fdb18649c352f->insert(tuple,READ_OP_CONTEXT(rel_new_Finish_669fdb18649c352f_op_ctxt));
}
}
();}
signalHandler->setMsg(R"_(Finish("ruleDemo",-1,1) :- 
   Start("ruleDemo",-1),
   Finish("ruleDemo",0,1).
in file bttest.dl [42:1-43:49])_");
if(!(rel_delta_Start_4a3bb0b3286f88b4->empty()) && !(rel_Finish_ad59707375956ad2->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_delta_Finish_a44c45a10dcdc5f7_op_ctxt,rel_delta_Finish_a44c45a10dcdc5f7->createContext());
CREATE_OP_CONTEXT(rel_delta_Start_4a3bb0b3286f88b4_op_ctxt,rel_delta_Start_4a3bb0b3286f88b4->createContext());
CREATE_OP_CONTEXT(rel_new_Finish_669fdb18649c352f_op_ctxt,rel_new_Finish_669fdb18649c352f->createContext());
CREATE_OP_CONTEXT(rel_Finish_ad59707375956ad2_op_ctxt,rel_Finish_ad59707375956ad2->createContext());
if(!(rel_delta_Finish_a44c45a10dcdc5f7->contains(Tuple<RamDomain,3>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_delta_Finish_a44c45a10dcdc5f7_op_ctxt))) && rel_Finish_ad59707375956ad2->contains(Tuple<RamDomain,3>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_Finish_ad59707375956ad2_op_ctxt)) && !(rel_Finish_ad59707375956ad2->contains(Tuple<RamDomain,3>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(-1)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_Finish_ad59707375956ad2_op_ctxt))) && rel_delta_Start_4a3bb0b3286f88b4->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(-1))}},READ_OP_CONTEXT(rel_delta_Start_4a3bb0b3286f88b4_op_ctxt))) {
Tuple<RamDomain,3> tuple{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(-1)),ramBitCast(RamSigned(1))}};
rel_new_Finish_669fdb18649c352f->insert(tuple,READ_OP_CONTEXT(rel_new_Finish_669fdb18649c352f_op_ctxt));
}
}
();}
signalHandler->setMsg(R"_(Finish("ruleDemo",-1,1) :- 
   Start("ruleDemo",-1),
   Finish("ruleDemo",0,1).
in file bttest.dl [42:1-43:49])_");
if(!(rel_Start_ae1c7f13b7c0c47f->empty()) && !(rel_delta_Finish_a44c45a10dcdc5f7->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_delta_Finish_a44c45a10dcdc5f7_op_ctxt,rel_delta_Finish_a44c45a10dcdc5f7->createContext());
CREATE_OP_CONTEXT(rel_new_Finish_669fdb18649c352f_op_ctxt,rel_new_Finish_669fdb18649c352f->createContext());
CREATE_OP_CONTEXT(rel_Finish_ad59707375956ad2_op_ctxt,rel_Finish_ad59707375956ad2->createContext());
CREATE_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt,rel_Start_ae1c7f13b7c0c47f->createContext());
if(!(rel_Finish_ad59707375956ad2->contains(Tuple<RamDomain,3>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(-1)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_Finish_ad59707375956ad2_op_ctxt))) && rel_delta_Finish_a44c45a10dcdc5f7->contains(Tuple<RamDomain,3>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_delta_Finish_a44c45a10dcdc5f7_op_ctxt)) && rel_Start_ae1c7f13b7c0c47f->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(-1))}},READ_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt))) {
Tuple<RamDomain,3> tuple{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(-1)),ramBitCast(RamSigned(1))}};
rel_new_Finish_669fdb18649c352f->insert(tuple,READ_OP_CONTEXT(rel_new_Finish_669fdb18649c352f_op_ctxt));
}
}
();}
signalHandler->setMsg(R"_(Finish("ruleDemo",3,1) :- 
   Start("ruleDemo",3),
   ActionComplete("ruleDemo",3).
in file bttest.dl [69:1-70:53])_");
if(!(rel_delta_Start_4a3bb0b3286f88b4->empty()) && !(rel_ActionComplete_274fcea6d3a4990c->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_delta_Start_4a3bb0b3286f88b4_op_ctxt,rel_delta_Start_4a3bb0b3286f88b4->createContext());
CREATE_OP_CONTEXT(rel_new_Finish_669fdb18649c352f_op_ctxt,rel_new_Finish_669fdb18649c352f->createContext());
CREATE_OP_CONTEXT(rel_ActionComplete_274fcea6d3a4990c_op_ctxt,rel_ActionComplete_274fcea6d3a4990c->createContext());
CREATE_OP_CONTEXT(rel_Finish_ad59707375956ad2_op_ctxt,rel_Finish_ad59707375956ad2->createContext());
if(!(rel_Finish_ad59707375956ad2->contains(Tuple<RamDomain,3>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(3)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_Finish_ad59707375956ad2_op_ctxt))) && rel_ActionComplete_274fcea6d3a4990c->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(3))}},READ_OP_CONTEXT(rel_ActionComplete_274fcea6d3a4990c_op_ctxt)) && rel_delta_Start_4a3bb0b3286f88b4->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(3))}},READ_OP_CONTEXT(rel_delta_Start_4a3bb0b3286f88b4_op_ctxt))) {
Tuple<RamDomain,3> tuple{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(3)),ramBitCast(RamSigned(1))}};
rel_new_Finish_669fdb18649c352f->insert(tuple,READ_OP_CONTEXT(rel_new_Finish_669fdb18649c352f_op_ctxt));
}
}
();}
signalHandler->setMsg(R"_(Finish("ruleDemo",4,1) :- 
   Start("ruleDemo",4),
   ActionComplete("ruleDemo",4).
in file bttest.dl [72:1-73:53])_");
if(!(rel_delta_Start_4a3bb0b3286f88b4->empty()) && !(rel_ActionComplete_274fcea6d3a4990c->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_delta_Start_4a3bb0b3286f88b4_op_ctxt,rel_delta_Start_4a3bb0b3286f88b4->createContext());
CREATE_OP_CONTEXT(rel_new_Finish_669fdb18649c352f_op_ctxt,rel_new_Finish_669fdb18649c352f->createContext());
CREATE_OP_CONTEXT(rel_ActionComplete_274fcea6d3a4990c_op_ctxt,rel_ActionComplete_274fcea6d3a4990c->createContext());
CREATE_OP_CONTEXT(rel_Finish_ad59707375956ad2_op_ctxt,rel_Finish_ad59707375956ad2->createContext());
if(!(rel_Finish_ad59707375956ad2->contains(Tuple<RamDomain,3>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(4)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_Finish_ad59707375956ad2_op_ctxt))) && rel_ActionComplete_274fcea6d3a4990c->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(4))}},READ_OP_CONTEXT(rel_ActionComplete_274fcea6d3a4990c_op_ctxt)) && rel_delta_Start_4a3bb0b3286f88b4->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(4))}},READ_OP_CONTEXT(rel_delta_Start_4a3bb0b3286f88b4_op_ctxt))) {
Tuple<RamDomain,3> tuple{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(4)),ramBitCast(RamSigned(1))}};
rel_new_Finish_669fdb18649c352f->insert(tuple,READ_OP_CONTEXT(rel_new_Finish_669fdb18649c352f_op_ctxt));
}
}
();}
signalHandler->setMsg(R"_(Finish("ruleDemo",2,1) :- 
   Start("ruleDemo",2),
   ActionComplete("ruleDemo",2).
in file bttest.dl [75:1-76:53])_");
if(!(rel_delta_Start_4a3bb0b3286f88b4->empty()) && !(rel_ActionComplete_274fcea6d3a4990c->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_delta_Start_4a3bb0b3286f88b4_op_ctxt,rel_delta_Start_4a3bb0b3286f88b4->createContext());
CREATE_OP_CONTEXT(rel_new_Finish_669fdb18649c352f_op_ctxt,rel_new_Finish_669fdb18649c352f->createContext());
CREATE_OP_CONTEXT(rel_ActionComplete_274fcea6d3a4990c_op_ctxt,rel_ActionComplete_274fcea6d3a4990c->createContext());
CREATE_OP_CONTEXT(rel_Finish_ad59707375956ad2_op_ctxt,rel_Finish_ad59707375956ad2->createContext());
if(!(rel_Finish_ad59707375956ad2->contains(Tuple<RamDomain,3>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(2)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_Finish_ad59707375956ad2_op_ctxt))) && rel_ActionComplete_274fcea6d3a4990c->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(2))}},READ_OP_CONTEXT(rel_ActionComplete_274fcea6d3a4990c_op_ctxt)) && rel_delta_Start_4a3bb0b3286f88b4->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(2))}},READ_OP_CONTEXT(rel_delta_Start_4a3bb0b3286f88b4_op_ctxt))) {
Tuple<RamDomain,3> tuple{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(2)),ramBitCast(RamSigned(1))}};
rel_new_Finish_669fdb18649c352f->insert(tuple,READ_OP_CONTEXT(rel_new_Finish_669fdb18649c352f_op_ctxt));
}
}
();}
signalHandler->setMsg(R"_(Finish("ruleDemo",0,1) :- 
   +disconnected0().
in file bttest.dl [45:1-46:60])_");
if(!(rel_delta_disconnected0_3b2fbdedaad9411a->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_new_Finish_669fdb18649c352f_op_ctxt,rel_new_Finish_669fdb18649c352f->createContext());
CREATE_OP_CONTEXT(rel_Finish_ad59707375956ad2_op_ctxt,rel_Finish_ad59707375956ad2->createContext());
if(!(rel_Finish_ad59707375956ad2->contains(Tuple<RamDomain,3>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_Finish_ad59707375956ad2_op_ctxt)))) {
Tuple<RamDomain,3> tuple{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1))}};
rel_new_Finish_669fdb18649c352f->insert(tuple,READ_OP_CONTEXT(rel_new_Finish_669fdb18649c352f_op_ctxt));
}
}
();}
signalHandler->setMsg(R"_(Finish("ruleDemo",1,1) :- 
   +disconnected1().
in file bttest.dl [54:1-55:60])_");
if(!(rel_delta_disconnected1_3b2fbeedaad942cd->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_new_Finish_669fdb18649c352f_op_ctxt,rel_new_Finish_669fdb18649c352f->createContext());
CREATE_OP_CONTEXT(rel_Finish_ad59707375956ad2_op_ctxt,rel_Finish_ad59707375956ad2->createContext());
if(!(rel_Finish_ad59707375956ad2->contains(Tuple<RamDomain,3>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_Finish_ad59707375956ad2_op_ctxt)))) {
Tuple<RamDomain,3> tuple{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1)),ramBitCast(RamSigned(1))}};
rel_new_Finish_669fdb18649c352f->insert(tuple,READ_OP_CONTEXT(rel_new_Finish_669fdb18649c352f_op_ctxt));
}
}
();}
signalHandler->setMsg(R"_(IntAttrInstance("ruleDemo","TestAgent","statisticAccuracy",0) :- 
   Start("ruleDemo",-1),
   IntAttr("TestAgent","statisticAccuracy",0).
in file bttest.dl [33:1-34:69])_");
if(!(rel_delta_Start_4a3bb0b3286f88b4->empty()) && !(rel_IntAttr_9edc9675b07c35fd->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_delta_Start_4a3bb0b3286f88b4_op_ctxt,rel_delta_Start_4a3bb0b3286f88b4->createContext());
CREATE_OP_CONTEXT(rel_new_IntAttrInstance_46c3e1da2b668339_op_ctxt,rel_new_IntAttrInstance_46c3e1da2b668339->createContext());
CREATE_OP_CONTEXT(rel_IntAttr_9edc9675b07c35fd_op_ctxt,rel_IntAttr_9edc9675b07c35fd->createContext());
CREATE_OP_CONTEXT(rel_IntAttrInstance_b534d52673393a7a_op_ctxt,rel_IntAttrInstance_b534d52673393a7a->createContext());
if(!(rel_IntAttrInstance_b534d52673393a7a->contains(Tuple<RamDomain,4>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1)),ramBitCast(RamSigned(2)),ramBitCast(RamSigned(0))}},READ_OP_CONTEXT(rel_IntAttrInstance_b534d52673393a7a_op_ctxt))) && rel_IntAttr_9edc9675b07c35fd->contains(Tuple<RamDomain,3>{{ramBitCast(RamSigned(1)),ramBitCast(RamSigned(2)),ramBitCast(RamSigned(0))}},READ_OP_CONTEXT(rel_IntAttr_9edc9675b07c35fd_op_ctxt)) && rel_delta_Start_4a3bb0b3286f88b4->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(-1))}},READ_OP_CONTEXT(rel_delta_Start_4a3bb0b3286f88b4_op_ctxt))) {
Tuple<RamDomain,4> tuple{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1)),ramBitCast(RamSigned(2)),ramBitCast(RamSigned(0))}};
rel_new_IntAttrInstance_46c3e1da2b668339->insert(tuple,READ_OP_CONTEXT(rel_new_IntAttrInstance_46c3e1da2b668339_op_ctxt));
}
}
();}
signalHandler->setMsg(R"_(Start("ruleDemo",1) :- 
   Start("ruleDemo",0),
   IntAttrInstance("ruleDemo","TestAgent","statisticAccuracy",1).
in file bttest.dl [51:1-52:88])_");
if(!(rel_delta_Start_4a3bb0b3286f88b4->empty()) && !(rel_IntAttrInstance_b534d52673393a7a->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_delta_IntAttrInstance_b8fdf596d9aeece1_op_ctxt,rel_delta_IntAttrInstance_b8fdf596d9aeece1->createContext());
CREATE_OP_CONTEXT(rel_delta_Start_4a3bb0b3286f88b4_op_ctxt,rel_delta_Start_4a3bb0b3286f88b4->createContext());
CREATE_OP_CONTEXT(rel_new_Start_8d183a7aef9127dc_op_ctxt,rel_new_Start_8d183a7aef9127dc->createContext());
CREATE_OP_CONTEXT(rel_IntAttrInstance_b534d52673393a7a_op_ctxt,rel_IntAttrInstance_b534d52673393a7a->createContext());
CREATE_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt,rel_Start_ae1c7f13b7c0c47f->createContext());
if(!(rel_delta_IntAttrInstance_b8fdf596d9aeece1->contains(Tuple<RamDomain,4>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1)),ramBitCast(RamSigned(2)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_delta_IntAttrInstance_b8fdf596d9aeece1_op_ctxt))) && rel_IntAttrInstance_b534d52673393a7a->contains(Tuple<RamDomain,4>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1)),ramBitCast(RamSigned(2)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_IntAttrInstance_b534d52673393a7a_op_ctxt)) && !(rel_Start_ae1c7f13b7c0c47f->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt))) && rel_delta_Start_4a3bb0b3286f88b4->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(0))}},READ_OP_CONTEXT(rel_delta_Start_4a3bb0b3286f88b4_op_ctxt))) {
Tuple<RamDomain,2> tuple{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1))}};
rel_new_Start_8d183a7aef9127dc->insert(tuple,READ_OP_CONTEXT(rel_new_Start_8d183a7aef9127dc_op_ctxt));
}
}
();}
signalHandler->setMsg(R"_(Start("ruleDemo",1) :- 
   Start("ruleDemo",0),
   IntAttrInstance("ruleDemo","TestAgent","statisticAccuracy",1).
in file bttest.dl [51:1-52:88])_");
if(!(rel_Start_ae1c7f13b7c0c47f->empty()) && !(rel_delta_IntAttrInstance_b8fdf596d9aeece1->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_delta_IntAttrInstance_b8fdf596d9aeece1_op_ctxt,rel_delta_IntAttrInstance_b8fdf596d9aeece1->createContext());
CREATE_OP_CONTEXT(rel_new_Start_8d183a7aef9127dc_op_ctxt,rel_new_Start_8d183a7aef9127dc->createContext());
CREATE_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt,rel_Start_ae1c7f13b7c0c47f->createContext());
if(!(rel_Start_ae1c7f13b7c0c47f->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt))) && rel_delta_IntAttrInstance_b8fdf596d9aeece1->contains(Tuple<RamDomain,4>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1)),ramBitCast(RamSigned(2)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_delta_IntAttrInstance_b8fdf596d9aeece1_op_ctxt)) && rel_Start_ae1c7f13b7c0c47f->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(0))}},READ_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt))) {
Tuple<RamDomain,2> tuple{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1))}};
rel_new_Start_8d183a7aef9127dc->insert(tuple,READ_OP_CONTEXT(rel_new_Start_8d183a7aef9127dc_op_ctxt));
}
}
();}
signalHandler->setMsg(R"_(Start("ruleDemo",3) :- 
   Start("ruleDemo",1),
   IntAttrInstance("ruleDemo","TestAgent","planeNum",1).
in file bttest.dl [57:1-58:79])_");
if(!(rel_delta_Start_4a3bb0b3286f88b4->empty()) && !(rel_IntAttrInstance_b534d52673393a7a->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_delta_IntAttrInstance_b8fdf596d9aeece1_op_ctxt,rel_delta_IntAttrInstance_b8fdf596d9aeece1->createContext());
CREATE_OP_CONTEXT(rel_delta_Start_4a3bb0b3286f88b4_op_ctxt,rel_delta_Start_4a3bb0b3286f88b4->createContext());
CREATE_OP_CONTEXT(rel_new_Start_8d183a7aef9127dc_op_ctxt,rel_new_Start_8d183a7aef9127dc->createContext());
CREATE_OP_CONTEXT(rel_IntAttrInstance_b534d52673393a7a_op_ctxt,rel_IntAttrInstance_b534d52673393a7a->createContext());
CREATE_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt,rel_Start_ae1c7f13b7c0c47f->createContext());
if(!(rel_delta_IntAttrInstance_b8fdf596d9aeece1->contains(Tuple<RamDomain,4>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1)),ramBitCast(RamSigned(3)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_delta_IntAttrInstance_b8fdf596d9aeece1_op_ctxt))) && rel_IntAttrInstance_b534d52673393a7a->contains(Tuple<RamDomain,4>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1)),ramBitCast(RamSigned(3)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_IntAttrInstance_b534d52673393a7a_op_ctxt)) && !(rel_Start_ae1c7f13b7c0c47f->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(3))}},READ_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt))) && rel_delta_Start_4a3bb0b3286f88b4->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_delta_Start_4a3bb0b3286f88b4_op_ctxt))) {
Tuple<RamDomain,2> tuple{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(3))}};
rel_new_Start_8d183a7aef9127dc->insert(tuple,READ_OP_CONTEXT(rel_new_Start_8d183a7aef9127dc_op_ctxt));
}
}
();}
signalHandler->setMsg(R"_(Start("ruleDemo",3) :- 
   Start("ruleDemo",1),
   IntAttrInstance("ruleDemo","TestAgent","planeNum",1).
in file bttest.dl [57:1-58:79])_");
if(!(rel_Start_ae1c7f13b7c0c47f->empty()) && !(rel_delta_IntAttrInstance_b8fdf596d9aeece1->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_delta_IntAttrInstance_b8fdf596d9aeece1_op_ctxt,rel_delta_IntAttrInstance_b8fdf596d9aeece1->createContext());
CREATE_OP_CONTEXT(rel_new_Start_8d183a7aef9127dc_op_ctxt,rel_new_Start_8d183a7aef9127dc->createContext());
CREATE_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt,rel_Start_ae1c7f13b7c0c47f->createContext());
if(!(rel_Start_ae1c7f13b7c0c47f->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(3))}},READ_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt))) && rel_delta_IntAttrInstance_b8fdf596d9aeece1->contains(Tuple<RamDomain,4>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1)),ramBitCast(RamSigned(3)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_delta_IntAttrInstance_b8fdf596d9aeece1_op_ctxt)) && rel_Start_ae1c7f13b7c0c47f->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt))) {
Tuple<RamDomain,2> tuple{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(3))}};
rel_new_Start_8d183a7aef9127dc->insert(tuple,READ_OP_CONTEXT(rel_new_Start_8d183a7aef9127dc_op_ctxt));
}
}
();}
signalHandler->setMsg(R"_(Start("ruleDemo",4) :- 
   Start("ruleDemo",1),
   IntAttrInstance("ruleDemo","TestAgent","planeNum",2).
in file bttest.dl [60:1-61:79])_");
if(!(rel_delta_Start_4a3bb0b3286f88b4->empty()) && !(rel_IntAttrInstance_b534d52673393a7a->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_delta_IntAttrInstance_b8fdf596d9aeece1_op_ctxt,rel_delta_IntAttrInstance_b8fdf596d9aeece1->createContext());
CREATE_OP_CONTEXT(rel_delta_Start_4a3bb0b3286f88b4_op_ctxt,rel_delta_Start_4a3bb0b3286f88b4->createContext());
CREATE_OP_CONTEXT(rel_new_Start_8d183a7aef9127dc_op_ctxt,rel_new_Start_8d183a7aef9127dc->createContext());
CREATE_OP_CONTEXT(rel_IntAttrInstance_b534d52673393a7a_op_ctxt,rel_IntAttrInstance_b534d52673393a7a->createContext());
CREATE_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt,rel_Start_ae1c7f13b7c0c47f->createContext());
if(!(rel_delta_IntAttrInstance_b8fdf596d9aeece1->contains(Tuple<RamDomain,4>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1)),ramBitCast(RamSigned(3)),ramBitCast(RamSigned(2))}},READ_OP_CONTEXT(rel_delta_IntAttrInstance_b8fdf596d9aeece1_op_ctxt))) && rel_IntAttrInstance_b534d52673393a7a->contains(Tuple<RamDomain,4>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1)),ramBitCast(RamSigned(3)),ramBitCast(RamSigned(2))}},READ_OP_CONTEXT(rel_IntAttrInstance_b534d52673393a7a_op_ctxt)) && !(rel_Start_ae1c7f13b7c0c47f->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(4))}},READ_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt))) && rel_delta_Start_4a3bb0b3286f88b4->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_delta_Start_4a3bb0b3286f88b4_op_ctxt))) {
Tuple<RamDomain,2> tuple{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(4))}};
rel_new_Start_8d183a7aef9127dc->insert(tuple,READ_OP_CONTEXT(rel_new_Start_8d183a7aef9127dc_op_ctxt));
}
}
();}
signalHandler->setMsg(R"_(Start("ruleDemo",4) :- 
   Start("ruleDemo",1),
   IntAttrInstance("ruleDemo","TestAgent","planeNum",2).
in file bttest.dl [60:1-61:79])_");
if(!(rel_Start_ae1c7f13b7c0c47f->empty()) && !(rel_delta_IntAttrInstance_b8fdf596d9aeece1->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_delta_IntAttrInstance_b8fdf596d9aeece1_op_ctxt,rel_delta_IntAttrInstance_b8fdf596d9aeece1->createContext());
CREATE_OP_CONTEXT(rel_new_Start_8d183a7aef9127dc_op_ctxt,rel_new_Start_8d183a7aef9127dc->createContext());
CREATE_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt,rel_Start_ae1c7f13b7c0c47f->createContext());
if(!(rel_Start_ae1c7f13b7c0c47f->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(4))}},READ_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt))) && rel_delta_IntAttrInstance_b8fdf596d9aeece1->contains(Tuple<RamDomain,4>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1)),ramBitCast(RamSigned(3)),ramBitCast(RamSigned(2))}},READ_OP_CONTEXT(rel_delta_IntAttrInstance_b8fdf596d9aeece1_op_ctxt)) && rel_Start_ae1c7f13b7c0c47f->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1))}},READ_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt))) {
Tuple<RamDomain,2> tuple{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(4))}};
rel_new_Start_8d183a7aef9127dc->insert(tuple,READ_OP_CONTEXT(rel_new_Start_8d183a7aef9127dc_op_ctxt));
}
}
();}
signalHandler->setMsg(R"_(Start("ruleDemo",2) :- 
   Start("ruleDemo",0),
   IntAttrInstance("ruleDemo","TestAgent","statisticAccuracy",2).
in file bttest.dl [63:1-64:88])_");
if(!(rel_delta_Start_4a3bb0b3286f88b4->empty()) && !(rel_IntAttrInstance_b534d52673393a7a->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_delta_IntAttrInstance_b8fdf596d9aeece1_op_ctxt,rel_delta_IntAttrInstance_b8fdf596d9aeece1->createContext());
CREATE_OP_CONTEXT(rel_delta_Start_4a3bb0b3286f88b4_op_ctxt,rel_delta_Start_4a3bb0b3286f88b4->createContext());
CREATE_OP_CONTEXT(rel_new_Start_8d183a7aef9127dc_op_ctxt,rel_new_Start_8d183a7aef9127dc->createContext());
CREATE_OP_CONTEXT(rel_IntAttrInstance_b534d52673393a7a_op_ctxt,rel_IntAttrInstance_b534d52673393a7a->createContext());
CREATE_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt,rel_Start_ae1c7f13b7c0c47f->createContext());
if(!(rel_delta_IntAttrInstance_b8fdf596d9aeece1->contains(Tuple<RamDomain,4>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1)),ramBitCast(RamSigned(2)),ramBitCast(RamSigned(2))}},READ_OP_CONTEXT(rel_delta_IntAttrInstance_b8fdf596d9aeece1_op_ctxt))) && rel_IntAttrInstance_b534d52673393a7a->contains(Tuple<RamDomain,4>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1)),ramBitCast(RamSigned(2)),ramBitCast(RamSigned(2))}},READ_OP_CONTEXT(rel_IntAttrInstance_b534d52673393a7a_op_ctxt)) && !(rel_Start_ae1c7f13b7c0c47f->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(2))}},READ_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt))) && rel_delta_Start_4a3bb0b3286f88b4->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(0))}},READ_OP_CONTEXT(rel_delta_Start_4a3bb0b3286f88b4_op_ctxt))) {
Tuple<RamDomain,2> tuple{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(2))}};
rel_new_Start_8d183a7aef9127dc->insert(tuple,READ_OP_CONTEXT(rel_new_Start_8d183a7aef9127dc_op_ctxt));
}
}
();}
signalHandler->setMsg(R"_(Start("ruleDemo",2) :- 
   Start("ruleDemo",0),
   IntAttrInstance("ruleDemo","TestAgent","statisticAccuracy",2).
in file bttest.dl [63:1-64:88])_");
if(!(rel_Start_ae1c7f13b7c0c47f->empty()) && !(rel_delta_IntAttrInstance_b8fdf596d9aeece1->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_delta_IntAttrInstance_b8fdf596d9aeece1_op_ctxt,rel_delta_IntAttrInstance_b8fdf596d9aeece1->createContext());
CREATE_OP_CONTEXT(rel_new_Start_8d183a7aef9127dc_op_ctxt,rel_new_Start_8d183a7aef9127dc->createContext());
CREATE_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt,rel_Start_ae1c7f13b7c0c47f->createContext());
if(!(rel_Start_ae1c7f13b7c0c47f->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(2))}},READ_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt))) && rel_delta_IntAttrInstance_b8fdf596d9aeece1->contains(Tuple<RamDomain,4>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(1)),ramBitCast(RamSigned(2)),ramBitCast(RamSigned(2))}},READ_OP_CONTEXT(rel_delta_IntAttrInstance_b8fdf596d9aeece1_op_ctxt)) && rel_Start_ae1c7f13b7c0c47f->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(0))}},READ_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt))) {
Tuple<RamDomain,2> tuple{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(2))}};
rel_new_Start_8d183a7aef9127dc->insert(tuple,READ_OP_CONTEXT(rel_new_Start_8d183a7aef9127dc_op_ctxt));
}
}
();}
signalHandler->setMsg(R"_(Start("ruleDemo",0) :- 
   +disconnected2().
in file bttest.dl [48:1-49:59])_");
if(!(rel_delta_disconnected2_3b2fbbedaad93db4->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_new_Start_8d183a7aef9127dc_op_ctxt,rel_new_Start_8d183a7aef9127dc->createContext());
CREATE_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt,rel_Start_ae1c7f13b7c0c47f->createContext());
if(!(rel_Start_ae1c7f13b7c0c47f->contains(Tuple<RamDomain,2>{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(0))}},READ_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt)))) {
Tuple<RamDomain,2> tuple{{ramBitCast(RamSigned(0)),ramBitCast(RamSigned(0))}};
rel_new_Start_8d183a7aef9127dc->insert(tuple,READ_OP_CONTEXT(rel_new_Start_8d183a7aef9127dc_op_ctxt));
}
}
();}
if(rel_new_disconnected0_811c6a653f6f04c2->empty() && rel_new_disconnected1_811c6b653f6f0675->empty() && rel_new_disconnected2_811c68653f6f015c->empty() && rel_new_AgentInitComplete_5e2c310bdba794cc->empty() && rel_new_Finish_669fdb18649c352f->empty() && rel_new_IntAttrInstance_46c3e1da2b668339->empty() && rel_new_Start_8d183a7aef9127dc->empty()) break;
if(!(rel_new_disconnected0_811c6a653f6f04c2->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_disconnected0_615a847368b8df77_op_ctxt,rel_disconnected0_615a847368b8df77->createContext());
Tuple<RamDomain,0> tuple{{}};
rel_disconnected0_615a847368b8df77->insert(tuple,READ_OP_CONTEXT(rel_disconnected0_615a847368b8df77_op_ctxt));
}
();}
std::swap(rel_delta_disconnected0_3b2fbdedaad9411a, rel_new_disconnected0_811c6a653f6f04c2);
rel_new_disconnected0_811c6a653f6f04c2->purge();
if(!(rel_new_disconnected1_811c6b653f6f0675->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_disconnected1_615a837368b8ddc4_op_ctxt,rel_disconnected1_615a837368b8ddc4->createContext());
Tuple<RamDomain,0> tuple{{}};
rel_disconnected1_615a837368b8ddc4->insert(tuple,READ_OP_CONTEXT(rel_disconnected1_615a837368b8ddc4_op_ctxt));
}
();}
std::swap(rel_delta_disconnected1_3b2fbeedaad942cd, rel_new_disconnected1_811c6b653f6f0675);
rel_new_disconnected1_811c6b653f6f0675->purge();
if(!(rel_new_disconnected2_811c68653f6f015c->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_disconnected2_615a867368b8e2dd_op_ctxt,rel_disconnected2_615a867368b8e2dd->createContext());
Tuple<RamDomain,0> tuple{{}};
rel_disconnected2_615a867368b8e2dd->insert(tuple,READ_OP_CONTEXT(rel_disconnected2_615a867368b8e2dd_op_ctxt));
}
();}
std::swap(rel_delta_disconnected2_3b2fbbedaad93db4, rel_new_disconnected2_811c68653f6f015c);
rel_new_disconnected2_811c68653f6f015c->purge();
[&](){
CREATE_OP_CONTEXT(rel_new_AgentInitComplete_5e2c310bdba794cc_op_ctxt,rel_new_AgentInitComplete_5e2c310bdba794cc->createContext());
CREATE_OP_CONTEXT(rel_AgentInitComplete_bc76db663593fd33_op_ctxt,rel_AgentInitComplete_bc76db663593fd33->createContext());
for(const auto& env0 : *rel_new_AgentInitComplete_5e2c310bdba794cc) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(env0[1])}};
rel_AgentInitComplete_bc76db663593fd33->insert(tuple,READ_OP_CONTEXT(rel_AgentInitComplete_bc76db663593fd33_op_ctxt));
}
}
();std::swap(rel_delta_AgentInitComplete_851d2e5f48d18d54, rel_new_AgentInitComplete_5e2c310bdba794cc);
rel_new_AgentInitComplete_5e2c310bdba794cc->purge();
[&](){
CREATE_OP_CONTEXT(rel_new_Finish_669fdb18649c352f_op_ctxt,rel_new_Finish_669fdb18649c352f->createContext());
CREATE_OP_CONTEXT(rel_Finish_ad59707375956ad2_op_ctxt,rel_Finish_ad59707375956ad2->createContext());
for(const auto& env0 : *rel_new_Finish_669fdb18649c352f) {
Tuple<RamDomain,3> tuple{{ramBitCast(env0[0]),ramBitCast(env0[1]),ramBitCast(env0[2])}};
rel_Finish_ad59707375956ad2->insert(tuple,READ_OP_CONTEXT(rel_Finish_ad59707375956ad2_op_ctxt));
}
}
();std::swap(rel_delta_Finish_a44c45a10dcdc5f7, rel_new_Finish_669fdb18649c352f);
rel_new_Finish_669fdb18649c352f->purge();
[&](){
CREATE_OP_CONTEXT(rel_new_IntAttrInstance_46c3e1da2b668339_op_ctxt,rel_new_IntAttrInstance_46c3e1da2b668339->createContext());
CREATE_OP_CONTEXT(rel_IntAttrInstance_b534d52673393a7a_op_ctxt,rel_IntAttrInstance_b534d52673393a7a->createContext());
for(const auto& env0 : *rel_new_IntAttrInstance_46c3e1da2b668339) {
Tuple<RamDomain,4> tuple{{ramBitCast(env0[0]),ramBitCast(env0[1]),ramBitCast(env0[2]),ramBitCast(env0[3])}};
rel_IntAttrInstance_b534d52673393a7a->insert(tuple,READ_OP_CONTEXT(rel_IntAttrInstance_b534d52673393a7a_op_ctxt));
}
}
();std::swap(rel_delta_IntAttrInstance_b8fdf596d9aeece1, rel_new_IntAttrInstance_46c3e1da2b668339);
rel_new_IntAttrInstance_46c3e1da2b668339->purge();
[&](){
CREATE_OP_CONTEXT(rel_new_Start_8d183a7aef9127dc_op_ctxt,rel_new_Start_8d183a7aef9127dc->createContext());
CREATE_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt,rel_Start_ae1c7f13b7c0c47f->createContext());
for(const auto& env0 : *rel_new_Start_8d183a7aef9127dc) {
Tuple<RamDomain,2> tuple{{ramBitCast(env0[0]),ramBitCast(env0[1])}};
rel_Start_ae1c7f13b7c0c47f->insert(tuple,READ_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt));
}
}
();std::swap(rel_delta_Start_4a3bb0b3286f88b4, rel_new_Start_8d183a7aef9127dc);
rel_new_Start_8d183a7aef9127dc->purge();
loop_counter = (ramBitCast<RamUnsigned>(loop_counter) + ramBitCast<RamUnsigned>(RamUnsigned(1)));
iter++;
}
iter = 0;
rel_delta_disconnected0_3b2fbdedaad9411a->purge();
rel_new_disconnected0_811c6a653f6f04c2->purge();
rel_delta_disconnected1_3b2fbeedaad942cd->purge();
rel_new_disconnected1_811c6b653f6f0675->purge();
rel_delta_disconnected2_3b2fbbedaad93db4->purge();
rel_new_disconnected2_811c68653f6f015c->purge();
rel_delta_AgentInitComplete_851d2e5f48d18d54->purge();
rel_new_AgentInitComplete_5e2c310bdba794cc->purge();
rel_delta_Finish_a44c45a10dcdc5f7->purge();
rel_new_Finish_669fdb18649c352f->purge();
rel_delta_IntAttrInstance_b8fdf596d9aeece1->purge();
rel_new_IntAttrInstance_46c3e1da2b668339->purge();
rel_delta_Start_4a3bb0b3286f88b4->purge();
rel_new_Start_8d183a7aef9127dc->purge();
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","tree\tnode\tflag"},{"auxArity","0"},{"name","Finish"},{"operation","output"},{"output-dir","."},{"params","{\"records\": {}, \"relation\": {\"arity\": 3, \"params\": [\"tree\", \"node\", \"flag\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 3, \"types\": [\"s:String\", \"i:number\", \"i:number\"]}}"}});
if (outputDirectory == "-"){directiveMap["IO"] = "stdout"; directiveMap["headers"] = "true";}
else if (!outputDirectory.empty()) {directiveMap["output-dir"] = outputDirectory;}
IOSystem::getInstance().getWriter(directiveMap, symTable, recordTable)->writeAll(*rel_Finish_ad59707375956ad2);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","tree\tagent\tattr\tvalue"},{"auxArity","0"},{"name","IntAttrInstance"},{"operation","output"},{"output-dir","."},{"params","{\"records\": {}, \"relation\": {\"arity\": 4, \"params\": [\"tree\", \"agent\", \"attr\", \"value\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 4, \"types\": [\"s:String\", \"s:String\", \"s:String\", \"i:number\"]}}"}});
if (outputDirectory == "-"){directiveMap["IO"] = "stdout"; directiveMap["headers"] = "true";}
else if (!outputDirectory.empty()) {directiveMap["output-dir"] = outputDirectory;}
IOSystem::getInstance().getWriter(directiveMap, symTable, recordTable)->writeAll(*rel_IntAttrInstance_b534d52673393a7a);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","tree\tnode"},{"auxArity","0"},{"name","Start"},{"operation","output"},{"output-dir","."},{"params","{\"records\": {}, \"relation\": {\"arity\": 2, \"params\": [\"tree\", \"node\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 2, \"types\": [\"s:String\", \"i:number\"]}}"}});
if (outputDirectory == "-"){directiveMap["IO"] = "stdout"; directiveMap["headers"] = "true";}
else if (!outputDirectory.empty()) {directiveMap["output-dir"] = outputDirectory;}
IOSystem::getInstance().getWriter(directiveMap, symTable, recordTable)->writeAll(*rel_Start_ae1c7f13b7c0c47f);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
if (pruneImdtRels) rel_disconnected0_615a847368b8df77->purge();
if (pruneImdtRels) rel_disconnected1_615a837368b8ddc4->purge();
if (pruneImdtRels) rel_disconnected2_615a867368b8e2dd->purge();
if (pruneImdtRels) rel_ActionComplete_274fcea6d3a4990c->purge();
if (pruneImdtRels) rel_AgentInitComplete_bc76db663593fd33->purge();
if (pruneImdtRels) rel_IntAttr_9edc9675b07c35fd->purge();
if (pruneImdtRels) rel_Parent_4eb514ebcb80553d->purge();
if (pruneImdtRels) rel_Precede_3d173237b8f1e4e1->purge();
}

} // namespace  souffle

namespace  souffle {
using namespace souffle;
class Stratum_Action_d2917628c2eff402 {
public:
 Stratum_Action_d2917628c2eff402(SymbolTable& symTable,RecordTable& recordTable,ConcurrentCache<std::string,std::regex>& regexCache,bool& pruneImdtRels,bool& performIO,SignalHandler*& signalHandler,std::atomic<std::size_t>& iter,std::atomic<RamDomain>& ctr,std::string& inputDirectory,std::string& outputDirectory,t_btree_iii__0_1_2__110__111::Type& rel_Action_a442044b586ec8bf);
void run([[maybe_unused]] const std::vector<RamDomain>& args,[[maybe_unused]] std::vector<RamDomain>& ret);
private:
SymbolTable& symTable;
RecordTable& recordTable;
ConcurrentCache<std::string,std::regex>& regexCache;
bool& pruneImdtRels;
bool& performIO;
SignalHandler*& signalHandler;
std::atomic<std::size_t>& iter;
std::atomic<RamDomain>& ctr;
std::string& inputDirectory;
std::string& outputDirectory;
t_btree_iii__0_1_2__110__111::Type* rel_Action_a442044b586ec8bf;
};
} // namespace  souffle
namespace  souffle {
using namespace souffle;
 Stratum_Action_d2917628c2eff402::Stratum_Action_d2917628c2eff402(SymbolTable& symTable,RecordTable& recordTable,ConcurrentCache<std::string,std::regex>& regexCache,bool& pruneImdtRels,bool& performIO,SignalHandler*& signalHandler,std::atomic<std::size_t>& iter,std::atomic<RamDomain>& ctr,std::string& inputDirectory,std::string& outputDirectory,t_btree_iii__0_1_2__110__111::Type& rel_Action_a442044b586ec8bf):
symTable(symTable),
recordTable(recordTable),
regexCache(regexCache),
pruneImdtRels(pruneImdtRels),
performIO(performIO),
signalHandler(signalHandler),
iter(iter),
ctr(ctr),
inputDirectory(inputDirectory),
outputDirectory(outputDirectory),
rel_Action_a442044b586ec8bf(&rel_Action_a442044b586ec8bf){
}

void Stratum_Action_d2917628c2eff402::run([[maybe_unused]] const std::vector<RamDomain>& args,[[maybe_unused]] std::vector<RamDomain>& ret){
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","tree\tnode\taction"},{"auxArity","0"},{"fact-dir","."},{"name","Action"},{"operation","input"},{"params","{\"records\": {}, \"relation\": {\"arity\": 3, \"params\": [\"tree\", \"node\", \"action\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 3, \"types\": [\"s:String\", \"i:number\", \"s:String\"]}}"}});
if (!inputDirectory.empty()) {directiveMap["fact-dir"] = inputDirectory;}
IOSystem::getInstance().getReader(directiveMap, symTable, recordTable)->readAll(*rel_Action_a442044b586ec8bf);
} catch (std::exception& e) {std::cerr << "Error loading Action data: " << e.what() << '\n';
exit(1);
}
}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","tree\tnode\taction"},{"auxArity","0"},{"name","Action"},{"operation","output"},{"output-dir","."},{"params","{\"records\": {}, \"relation\": {\"arity\": 3, \"params\": [\"tree\", \"node\", \"action\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 3, \"types\": [\"s:String\", \"i:number\", \"s:String\"]}}"}});
if (outputDirectory == "-"){directiveMap["IO"] = "stdout"; directiveMap["headers"] = "true";}
else if (!outputDirectory.empty()) {directiveMap["output-dir"] = outputDirectory;}
IOSystem::getInstance().getWriter(directiveMap, symTable, recordTable)->writeAll(*rel_Action_a442044b586ec8bf);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}

} // namespace  souffle

namespace  souffle {
using namespace souffle;
class Stratum_ActionBegin_9a76756886f2e247 {
public:
 Stratum_ActionBegin_9a76756886f2e247(SymbolTable& symTable,RecordTable& recordTable,ConcurrentCache<std::string,std::regex>& regexCache,bool& pruneImdtRels,bool& performIO,SignalHandler*& signalHandler,std::atomic<std::size_t>& iter,std::atomic<RamDomain>& ctr,std::string& inputDirectory,std::string& outputDirectory,t_btree_iii__0_1_2__110__111::Type& rel_Action_a442044b586ec8bf,t_btree_iii__0_1_2__111::Type& rel_ActionBegin_a6d9444aaed87d80,t_btree_ii__0_1__11::Type& rel_Start_ae1c7f13b7c0c47f);
void run([[maybe_unused]] const std::vector<RamDomain>& args,[[maybe_unused]] std::vector<RamDomain>& ret);
private:
SymbolTable& symTable;
RecordTable& recordTable;
ConcurrentCache<std::string,std::regex>& regexCache;
bool& pruneImdtRels;
bool& performIO;
SignalHandler*& signalHandler;
std::atomic<std::size_t>& iter;
std::atomic<RamDomain>& ctr;
std::string& inputDirectory;
std::string& outputDirectory;
t_btree_iii__0_1_2__110__111::Type* rel_Action_a442044b586ec8bf;
t_btree_iii__0_1_2__111::Type* rel_ActionBegin_a6d9444aaed87d80;
t_btree_ii__0_1__11::Type* rel_Start_ae1c7f13b7c0c47f;
};
} // namespace  souffle
namespace  souffle {
using namespace souffle;
 Stratum_ActionBegin_9a76756886f2e247::Stratum_ActionBegin_9a76756886f2e247(SymbolTable& symTable,RecordTable& recordTable,ConcurrentCache<std::string,std::regex>& regexCache,bool& pruneImdtRels,bool& performIO,SignalHandler*& signalHandler,std::atomic<std::size_t>& iter,std::atomic<RamDomain>& ctr,std::string& inputDirectory,std::string& outputDirectory,t_btree_iii__0_1_2__110__111::Type& rel_Action_a442044b586ec8bf,t_btree_iii__0_1_2__111::Type& rel_ActionBegin_a6d9444aaed87d80,t_btree_ii__0_1__11::Type& rel_Start_ae1c7f13b7c0c47f):
symTable(symTable),
recordTable(recordTable),
regexCache(regexCache),
pruneImdtRels(pruneImdtRels),
performIO(performIO),
signalHandler(signalHandler),
iter(iter),
ctr(ctr),
inputDirectory(inputDirectory),
outputDirectory(outputDirectory),
rel_Action_a442044b586ec8bf(&rel_Action_a442044b586ec8bf),
rel_ActionBegin_a6d9444aaed87d80(&rel_ActionBegin_a6d9444aaed87d80),
rel_Start_ae1c7f13b7c0c47f(&rel_Start_ae1c7f13b7c0c47f){
}

void Stratum_ActionBegin_9a76756886f2e247::run([[maybe_unused]] const std::vector<RamDomain>& args,[[maybe_unused]] std::vector<RamDomain>& ret){
signalHandler->setMsg(R"_(ActionBegin(tree,node,action) :- 
   Start(tree,node),
   Action(tree,node,action).
in file bttest.dl [66:1-67:47])_");
if(!(rel_Start_ae1c7f13b7c0c47f->empty()) && !(rel_Action_a442044b586ec8bf->empty())) {
[&](){
CREATE_OP_CONTEXT(rel_Action_a442044b586ec8bf_op_ctxt,rel_Action_a442044b586ec8bf->createContext());
CREATE_OP_CONTEXT(rel_ActionBegin_a6d9444aaed87d80_op_ctxt,rel_ActionBegin_a6d9444aaed87d80->createContext());
CREATE_OP_CONTEXT(rel_Start_ae1c7f13b7c0c47f_op_ctxt,rel_Start_ae1c7f13b7c0c47f->createContext());
for(const auto& env0 : *rel_Start_ae1c7f13b7c0c47f) {
auto range = rel_Action_a442044b586ec8bf->lowerUpperRange_110(Tuple<RamDomain,3>{{ramBitCast(env0[0]), ramBitCast(env0[1]), ramBitCast<RamDomain>(MIN_RAM_SIGNED)}},Tuple<RamDomain,3>{{ramBitCast(env0[0]), ramBitCast(env0[1]), ramBitCast<RamDomain>(MAX_RAM_SIGNED)}},READ_OP_CONTEXT(rel_Action_a442044b586ec8bf_op_ctxt));
for(const auto& env1 : range) {
Tuple<RamDomain,3> tuple{{ramBitCast(env0[0]),ramBitCast(env0[1]),ramBitCast(env1[2])}};
rel_ActionBegin_a6d9444aaed87d80->insert(tuple,READ_OP_CONTEXT(rel_ActionBegin_a6d9444aaed87d80_op_ctxt));
}
}
}
();}
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","tree\tnode\taction"},{"auxArity","0"},{"name","ActionBegin"},{"operation","output"},{"output-dir","."},{"params","{\"records\": {}, \"relation\": {\"arity\": 3, \"params\": [\"tree\", \"node\", \"action\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 3, \"types\": [\"s:String\", \"i:number\", \"s:String\"]}}"}});
if (outputDirectory == "-"){directiveMap["IO"] = "stdout"; directiveMap["headers"] = "true";}
else if (!outputDirectory.empty()) {directiveMap["output-dir"] = outputDirectory;}
IOSystem::getInstance().getWriter(directiveMap, symTable, recordTable)->writeAll(*rel_ActionBegin_a6d9444aaed87d80);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}
}

} // namespace  souffle

namespace  souffle {
using namespace souffle;
class Stratum_ActionComplete_f92ff52a133401a9 {
public:
 Stratum_ActionComplete_f92ff52a133401a9(SymbolTable& symTable,RecordTable& recordTable,ConcurrentCache<std::string,std::regex>& regexCache,bool& pruneImdtRels,bool& performIO,SignalHandler*& signalHandler,std::atomic<std::size_t>& iter,std::atomic<RamDomain>& ctr,std::string& inputDirectory,std::string& outputDirectory,t_btree_ii__0_1__11::Type& rel_ActionComplete_274fcea6d3a4990c);
void run([[maybe_unused]] const std::vector<RamDomain>& args,[[maybe_unused]] std::vector<RamDomain>& ret);
private:
SymbolTable& symTable;
RecordTable& recordTable;
ConcurrentCache<std::string,std::regex>& regexCache;
bool& pruneImdtRels;
bool& performIO;
SignalHandler*& signalHandler;
std::atomic<std::size_t>& iter;
std::atomic<RamDomain>& ctr;
std::string& inputDirectory;
std::string& outputDirectory;
t_btree_ii__0_1__11::Type* rel_ActionComplete_274fcea6d3a4990c;
};
} // namespace  souffle
namespace  souffle {
using namespace souffle;
 Stratum_ActionComplete_f92ff52a133401a9::Stratum_ActionComplete_f92ff52a133401a9(SymbolTable& symTable,RecordTable& recordTable,ConcurrentCache<std::string,std::regex>& regexCache,bool& pruneImdtRels,bool& performIO,SignalHandler*& signalHandler,std::atomic<std::size_t>& iter,std::atomic<RamDomain>& ctr,std::string& inputDirectory,std::string& outputDirectory,t_btree_ii__0_1__11::Type& rel_ActionComplete_274fcea6d3a4990c):
symTable(symTable),
recordTable(recordTable),
regexCache(regexCache),
pruneImdtRels(pruneImdtRels),
performIO(performIO),
signalHandler(signalHandler),
iter(iter),
ctr(ctr),
inputDirectory(inputDirectory),
outputDirectory(outputDirectory),
rel_ActionComplete_274fcea6d3a4990c(&rel_ActionComplete_274fcea6d3a4990c){
}

void Stratum_ActionComplete_f92ff52a133401a9::run([[maybe_unused]] const std::vector<RamDomain>& args,[[maybe_unused]] std::vector<RamDomain>& ret){
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","tree\tnode"},{"auxArity","0"},{"fact-dir","."},{"name","ActionComplete"},{"operation","input"},{"params","{\"records\": {}, \"relation\": {\"arity\": 2, \"params\": [\"tree\", \"node\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 2, \"types\": [\"s:String\", \"i:number\"]}}"}});
if (!inputDirectory.empty()) {directiveMap["fact-dir"] = inputDirectory;}
IOSystem::getInstance().getReader(directiveMap, symTable, recordTable)->readAll(*rel_ActionComplete_274fcea6d3a4990c);
} catch (std::exception& e) {std::cerr << "Error loading ActionComplete data: " << e.what() << '\n';
exit(1);
}
}
}

} // namespace  souffle

namespace  souffle {
using namespace souffle;
class Stratum_IntAttr_b200839a2cdb6eb6 {
public:
 Stratum_IntAttr_b200839a2cdb6eb6(SymbolTable& symTable,RecordTable& recordTable,ConcurrentCache<std::string,std::regex>& regexCache,bool& pruneImdtRels,bool& performIO,SignalHandler*& signalHandler,std::atomic<std::size_t>& iter,std::atomic<RamDomain>& ctr,std::string& inputDirectory,std::string& outputDirectory,t_btree_iii__0_1_2__111::Type& rel_IntAttr_9edc9675b07c35fd);
void run([[maybe_unused]] const std::vector<RamDomain>& args,[[maybe_unused]] std::vector<RamDomain>& ret);
private:
SymbolTable& symTable;
RecordTable& recordTable;
ConcurrentCache<std::string,std::regex>& regexCache;
bool& pruneImdtRels;
bool& performIO;
SignalHandler*& signalHandler;
std::atomic<std::size_t>& iter;
std::atomic<RamDomain>& ctr;
std::string& inputDirectory;
std::string& outputDirectory;
t_btree_iii__0_1_2__111::Type* rel_IntAttr_9edc9675b07c35fd;
};
} // namespace  souffle
namespace  souffle {
using namespace souffle;
 Stratum_IntAttr_b200839a2cdb6eb6::Stratum_IntAttr_b200839a2cdb6eb6(SymbolTable& symTable,RecordTable& recordTable,ConcurrentCache<std::string,std::regex>& regexCache,bool& pruneImdtRels,bool& performIO,SignalHandler*& signalHandler,std::atomic<std::size_t>& iter,std::atomic<RamDomain>& ctr,std::string& inputDirectory,std::string& outputDirectory,t_btree_iii__0_1_2__111::Type& rel_IntAttr_9edc9675b07c35fd):
symTable(symTable),
recordTable(recordTable),
regexCache(regexCache),
pruneImdtRels(pruneImdtRels),
performIO(performIO),
signalHandler(signalHandler),
iter(iter),
ctr(ctr),
inputDirectory(inputDirectory),
outputDirectory(outputDirectory),
rel_IntAttr_9edc9675b07c35fd(&rel_IntAttr_9edc9675b07c35fd){
}

void Stratum_IntAttr_b200839a2cdb6eb6::run([[maybe_unused]] const std::vector<RamDomain>& args,[[maybe_unused]] std::vector<RamDomain>& ret){
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","agent\tattr\tvalue"},{"auxArity","0"},{"fact-dir","."},{"name","IntAttr"},{"operation","input"},{"params","{\"records\": {}, \"relation\": {\"arity\": 3, \"params\": [\"agent\", \"attr\", \"value\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 3, \"types\": [\"s:String\", \"s:String\", \"i:number\"]}}"}});
if (!inputDirectory.empty()) {directiveMap["fact-dir"] = inputDirectory;}
IOSystem::getInstance().getReader(directiveMap, symTable, recordTable)->readAll(*rel_IntAttr_9edc9675b07c35fd);
} catch (std::exception& e) {std::cerr << "Error loading IntAttr data: " << e.what() << '\n';
exit(1);
}
}
}

} // namespace  souffle

namespace  souffle {
using namespace souffle;
class Stratum_Parent_3da6edbfc8a43628 {
public:
 Stratum_Parent_3da6edbfc8a43628(SymbolTable& symTable,RecordTable& recordTable,ConcurrentCache<std::string,std::regex>& regexCache,bool& pruneImdtRels,bool& performIO,SignalHandler*& signalHandler,std::atomic<std::size_t>& iter,std::atomic<RamDomain>& ctr,std::string& inputDirectory,std::string& outputDirectory,t_btree_iii__0_1_2__110__111::Type& rel_Parent_4eb514ebcb80553d);
void run([[maybe_unused]] const std::vector<RamDomain>& args,[[maybe_unused]] std::vector<RamDomain>& ret);
private:
SymbolTable& symTable;
RecordTable& recordTable;
ConcurrentCache<std::string,std::regex>& regexCache;
bool& pruneImdtRels;
bool& performIO;
SignalHandler*& signalHandler;
std::atomic<std::size_t>& iter;
std::atomic<RamDomain>& ctr;
std::string& inputDirectory;
std::string& outputDirectory;
t_btree_iii__0_1_2__110__111::Type* rel_Parent_4eb514ebcb80553d;
};
} // namespace  souffle
namespace  souffle {
using namespace souffle;
 Stratum_Parent_3da6edbfc8a43628::Stratum_Parent_3da6edbfc8a43628(SymbolTable& symTable,RecordTable& recordTable,ConcurrentCache<std::string,std::regex>& regexCache,bool& pruneImdtRels,bool& performIO,SignalHandler*& signalHandler,std::atomic<std::size_t>& iter,std::atomic<RamDomain>& ctr,std::string& inputDirectory,std::string& outputDirectory,t_btree_iii__0_1_2__110__111::Type& rel_Parent_4eb514ebcb80553d):
symTable(symTable),
recordTable(recordTable),
regexCache(regexCache),
pruneImdtRels(pruneImdtRels),
performIO(performIO),
signalHandler(signalHandler),
iter(iter),
ctr(ctr),
inputDirectory(inputDirectory),
outputDirectory(outputDirectory),
rel_Parent_4eb514ebcb80553d(&rel_Parent_4eb514ebcb80553d){
}

void Stratum_Parent_3da6edbfc8a43628::run([[maybe_unused]] const std::vector<RamDomain>& args,[[maybe_unused]] std::vector<RamDomain>& ret){
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","tree\tnode1\tnode2"},{"auxArity","0"},{"fact-dir","."},{"name","Parent"},{"operation","input"},{"params","{\"records\": {}, \"relation\": {\"arity\": 3, \"params\": [\"tree\", \"node1\", \"node2\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 3, \"types\": [\"s:String\", \"i:number\", \"i:number\"]}}"}});
if (!inputDirectory.empty()) {directiveMap["fact-dir"] = inputDirectory;}
IOSystem::getInstance().getReader(directiveMap, symTable, recordTable)->readAll(*rel_Parent_4eb514ebcb80553d);
} catch (std::exception& e) {std::cerr << "Error loading Parent data: " << e.what() << '\n';
exit(1);
}
}
}

} // namespace  souffle

namespace  souffle {
using namespace souffle;
class Stratum_Precede_684a173f9e4a6d26 {
public:
 Stratum_Precede_684a173f9e4a6d26(SymbolTable& symTable,RecordTable& recordTable,ConcurrentCache<std::string,std::regex>& regexCache,bool& pruneImdtRels,bool& performIO,SignalHandler*& signalHandler,std::atomic<std::size_t>& iter,std::atomic<RamDomain>& ctr,std::string& inputDirectory,std::string& outputDirectory,t_btree_iii__0_1_2__111::Type& rel_Precede_3d173237b8f1e4e1);
void run([[maybe_unused]] const std::vector<RamDomain>& args,[[maybe_unused]] std::vector<RamDomain>& ret);
private:
SymbolTable& symTable;
RecordTable& recordTable;
ConcurrentCache<std::string,std::regex>& regexCache;
bool& pruneImdtRels;
bool& performIO;
SignalHandler*& signalHandler;
std::atomic<std::size_t>& iter;
std::atomic<RamDomain>& ctr;
std::string& inputDirectory;
std::string& outputDirectory;
t_btree_iii__0_1_2__111::Type* rel_Precede_3d173237b8f1e4e1;
};
} // namespace  souffle
namespace  souffle {
using namespace souffle;
 Stratum_Precede_684a173f9e4a6d26::Stratum_Precede_684a173f9e4a6d26(SymbolTable& symTable,RecordTable& recordTable,ConcurrentCache<std::string,std::regex>& regexCache,bool& pruneImdtRels,bool& performIO,SignalHandler*& signalHandler,std::atomic<std::size_t>& iter,std::atomic<RamDomain>& ctr,std::string& inputDirectory,std::string& outputDirectory,t_btree_iii__0_1_2__111::Type& rel_Precede_3d173237b8f1e4e1):
symTable(symTable),
recordTable(recordTable),
regexCache(regexCache),
pruneImdtRels(pruneImdtRels),
performIO(performIO),
signalHandler(signalHandler),
iter(iter),
ctr(ctr),
inputDirectory(inputDirectory),
outputDirectory(outputDirectory),
rel_Precede_3d173237b8f1e4e1(&rel_Precede_3d173237b8f1e4e1){
}

void Stratum_Precede_684a173f9e4a6d26::run([[maybe_unused]] const std::vector<RamDomain>& args,[[maybe_unused]] std::vector<RamDomain>& ret){
if (performIO) {
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","tree\tnode1\tnode2"},{"auxArity","0"},{"fact-dir","."},{"name","Precede"},{"operation","input"},{"params","{\"records\": {}, \"relation\": {\"arity\": 3, \"params\": [\"tree\", \"node1\", \"node2\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 3, \"types\": [\"s:String\", \"i:number\", \"i:number\"]}}"}});
if (!inputDirectory.empty()) {directiveMap["fact-dir"] = inputDirectory;}
IOSystem::getInstance().getReader(directiveMap, symTable, recordTable)->readAll(*rel_Precede_3d173237b8f1e4e1);
} catch (std::exception& e) {std::cerr << "Error loading Precede data: " << e.what() << '\n';
exit(1);
}
}
}

} // namespace  souffle

namespace  souffle {
using namespace souffle;
class Sf_ruleDemo: public SouffleProgram {
public:
 Sf_ruleDemo();
 ~Sf_ruleDemo();
void run();
void runAll(std::string inputDirectoryArg = "",std::string outputDirectoryArg = "",bool performIOArg = true,bool pruneImdtRelsArg = true);
void printAll([[maybe_unused]] std::string outputDirectoryArg = "");
void loadAll([[maybe_unused]] std::string inputDirectoryArg = "");
void dumpInputs();
void dumpOutputs();
SymbolTable& getSymbolTable();
RecordTable& getRecordTable();
void setNumThreads(std::size_t numThreadsValue);
void executeSubroutine(std::string name,const std::vector<RamDomain>& args,std::vector<RamDomain>& ret);
private:
void runFunction(std::string inputDirectoryArg,std::string outputDirectoryArg,bool performIOArg,bool pruneImdtRelsArg);
SymbolTableImpl symTable;
SpecializedRecordTable<0> recordTable;
ConcurrentCache<std::string,std::regex> regexCache;
Own<t_btree_iii__0_1_2__110__111::Type> rel_Parent_4eb514ebcb80553d;
souffle::RelationWrapper<t_btree_iii__0_1_2__110__111::Type> wrapper_rel_Parent_4eb514ebcb80553d;
Own<t_btree_ii__0_1__11::Type> rel_ActionComplete_274fcea6d3a4990c;
souffle::RelationWrapper<t_btree_ii__0_1__11::Type> wrapper_rel_ActionComplete_274fcea6d3a4990c;
Own<t_btree_iii__0_1_2__111::Type> rel_IntAttr_9edc9675b07c35fd;
souffle::RelationWrapper<t_btree_iii__0_1_2__111::Type> wrapper_rel_IntAttr_9edc9675b07c35fd;
Own<t_btree_iii__0_1_2__111::Type> rel_Precede_3d173237b8f1e4e1;
souffle::RelationWrapper<t_btree_iii__0_1_2__111::Type> wrapper_rel_Precede_3d173237b8f1e4e1;
Own<t_nullaries> rel_disconnected0_615a847368b8df77;
souffle::RelationWrapper<t_nullaries> wrapper_rel_disconnected0_615a847368b8df77;
Own<t_nullaries> rel_delta_disconnected0_3b2fbdedaad9411a;
Own<t_nullaries> rel_new_disconnected0_811c6a653f6f04c2;
Own<t_nullaries> rel_disconnected1_615a837368b8ddc4;
souffle::RelationWrapper<t_nullaries> wrapper_rel_disconnected1_615a837368b8ddc4;
Own<t_nullaries> rel_delta_disconnected1_3b2fbeedaad942cd;
Own<t_nullaries> rel_new_disconnected1_811c6b653f6f0675;
Own<t_nullaries> rel_disconnected2_615a867368b8e2dd;
souffle::RelationWrapper<t_nullaries> wrapper_rel_disconnected2_615a867368b8e2dd;
Own<t_nullaries> rel_delta_disconnected2_3b2fbbedaad93db4;
Own<t_nullaries> rel_new_disconnected2_811c68653f6f015c;
Own<t_btree_ii__0_1__11::Type> rel_AgentInitComplete_bc76db663593fd33;
souffle::RelationWrapper<t_btree_ii__0_1__11::Type> wrapper_rel_AgentInitComplete_bc76db663593fd33;
Own<t_btree_ii__0_1__11::Type> rel_delta_AgentInitComplete_851d2e5f48d18d54;
Own<t_btree_ii__0_1__11::Type> rel_new_AgentInitComplete_5e2c310bdba794cc;
Own<t_btree_iii__0_1_2__111::Type> rel_Finish_ad59707375956ad2;
souffle::RelationWrapper<t_btree_iii__0_1_2__111::Type> wrapper_rel_Finish_ad59707375956ad2;
Own<t_btree_iii__0_2_1__101__111::Type> rel_delta_Finish_a44c45a10dcdc5f7;
Own<t_btree_iii__0_2_1__101__111::Type> rel_new_Finish_669fdb18649c352f;
Own<t_btree_iiii__0_1_2_3__1111::Type> rel_IntAttrInstance_b534d52673393a7a;
souffle::RelationWrapper<t_btree_iiii__0_1_2_3__1111::Type> wrapper_rel_IntAttrInstance_b534d52673393a7a;
Own<t_btree_iiii__0_1_2_3__1111::Type> rel_delta_IntAttrInstance_b8fdf596d9aeece1;
Own<t_btree_iiii__0_1_2_3__1111::Type> rel_new_IntAttrInstance_46c3e1da2b668339;
Own<t_btree_ii__0_1__11::Type> rel_Start_ae1c7f13b7c0c47f;
souffle::RelationWrapper<t_btree_ii__0_1__11::Type> wrapper_rel_Start_ae1c7f13b7c0c47f;
Own<t_btree_ii__0_1__11::Type> rel_delta_Start_4a3bb0b3286f88b4;
Own<t_btree_ii__0_1__11::Type> rel_new_Start_8d183a7aef9127dc;
Own<t_btree_iii__0_1_2__110__111::Type> rel_Action_a442044b586ec8bf;
souffle::RelationWrapper<t_btree_iii__0_1_2__110__111::Type> wrapper_rel_Action_a442044b586ec8bf;
Own<t_btree_iii__0_1_2__111::Type> rel_ActionBegin_a6d9444aaed87d80;
souffle::RelationWrapper<t_btree_iii__0_1_2__111::Type> wrapper_rel_ActionBegin_a6d9444aaed87d80;
Stratum_disconnected0_92d53886cb6eda8a stratum_disconnected0_ec65f654607345ea;
Stratum_Action_d2917628c2eff402 stratum_Action_cfcf50feab8c4aa2;
Stratum_ActionBegin_9a76756886f2e247 stratum_ActionBegin_75af5f53dacea827;
Stratum_ActionComplete_f92ff52a133401a9 stratum_ActionComplete_bfd78f8c2bfdb409;
Stratum_IntAttr_b200839a2cdb6eb6 stratum_IntAttr_9b2e94aa39f85a96;
Stratum_Parent_3da6edbfc8a43628 stratum_Parent_4038c03f7b83fbc8;
Stratum_Precede_684a173f9e4a6d26 stratum_Precede_fc5d2637a8882446;
std::string inputDirectory;
std::string outputDirectory;
SignalHandler* signalHandler{SignalHandler::instance()};
std::atomic<RamDomain> ctr{};
std::atomic<std::size_t> iter{};
};
} // namespace  souffle
namespace  souffle {
using namespace souffle;
 Sf_ruleDemo::Sf_ruleDemo():
symTable({
	R"_(ruleDemo)_",
	R"_(TestAgent)_",
	R"_(statisticAccuracy)_",
	R"_(planeNum)_",
}),
recordTable(),
regexCache(),
rel_Parent_4eb514ebcb80553d(mk<t_btree_iii__0_1_2__110__111::Type>()),
wrapper_rel_Parent_4eb514ebcb80553d(0, *rel_Parent_4eb514ebcb80553d, *this, "Parent", std::array<const char *,3>{{"s:String","i:number","i:number"}}, std::array<const char *,3>{{"tree","node1","node2"}}, 0),
rel_ActionComplete_274fcea6d3a4990c(mk<t_btree_ii__0_1__11::Type>()),
wrapper_rel_ActionComplete_274fcea6d3a4990c(1, *rel_ActionComplete_274fcea6d3a4990c, *this, "ActionComplete", std::array<const char *,2>{{"s:String","i:number"}}, std::array<const char *,2>{{"tree","node"}}, 0),
rel_IntAttr_9edc9675b07c35fd(mk<t_btree_iii__0_1_2__111::Type>()),
wrapper_rel_IntAttr_9edc9675b07c35fd(2, *rel_IntAttr_9edc9675b07c35fd, *this, "IntAttr", std::array<const char *,3>{{"s:String","s:String","i:number"}}, std::array<const char *,3>{{"agent","attr","value"}}, 0),
rel_Precede_3d173237b8f1e4e1(mk<t_btree_iii__0_1_2__111::Type>()),
wrapper_rel_Precede_3d173237b8f1e4e1(3, *rel_Precede_3d173237b8f1e4e1, *this, "Precede", std::array<const char *,3>{{"s:String","i:number","i:number"}}, std::array<const char *,3>{{"tree","node1","node2"}}, 0),
rel_disconnected0_615a847368b8df77(mk<t_nullaries>()),
wrapper_rel_disconnected0_615a847368b8df77(4, *rel_disconnected0_615a847368b8df77, *this, "+disconnected0", std::array<const char *,0>{{}}, std::array<const char *,0>{{}}, 0),
rel_delta_disconnected0_3b2fbdedaad9411a(mk<t_nullaries>()),
rel_new_disconnected0_811c6a653f6f04c2(mk<t_nullaries>()),
rel_disconnected1_615a837368b8ddc4(mk<t_nullaries>()),
wrapper_rel_disconnected1_615a837368b8ddc4(5, *rel_disconnected1_615a837368b8ddc4, *this, "+disconnected1", std::array<const char *,0>{{}}, std::array<const char *,0>{{}}, 0),
rel_delta_disconnected1_3b2fbeedaad942cd(mk<t_nullaries>()),
rel_new_disconnected1_811c6b653f6f0675(mk<t_nullaries>()),
rel_disconnected2_615a867368b8e2dd(mk<t_nullaries>()),
wrapper_rel_disconnected2_615a867368b8e2dd(6, *rel_disconnected2_615a867368b8e2dd, *this, "+disconnected2", std::array<const char *,0>{{}}, std::array<const char *,0>{{}}, 0),
rel_delta_disconnected2_3b2fbbedaad93db4(mk<t_nullaries>()),
rel_new_disconnected2_811c68653f6f015c(mk<t_nullaries>()),
rel_AgentInitComplete_bc76db663593fd33(mk<t_btree_ii__0_1__11::Type>()),
wrapper_rel_AgentInitComplete_bc76db663593fd33(7, *rel_AgentInitComplete_bc76db663593fd33, *this, "AgentInitComplete", std::array<const char *,2>{{"s:String","s:String"}}, std::array<const char *,2>{{"tree","agent"}}, 0),
rel_delta_AgentInitComplete_851d2e5f48d18d54(mk<t_btree_ii__0_1__11::Type>()),
rel_new_AgentInitComplete_5e2c310bdba794cc(mk<t_btree_ii__0_1__11::Type>()),
rel_Finish_ad59707375956ad2(mk<t_btree_iii__0_1_2__111::Type>()),
wrapper_rel_Finish_ad59707375956ad2(8, *rel_Finish_ad59707375956ad2, *this, "Finish", std::array<const char *,3>{{"s:String","i:number","i:number"}}, std::array<const char *,3>{{"tree","node","flag"}}, 0),
rel_delta_Finish_a44c45a10dcdc5f7(mk<t_btree_iii__0_2_1__101__111::Type>()),
rel_new_Finish_669fdb18649c352f(mk<t_btree_iii__0_2_1__101__111::Type>()),
rel_IntAttrInstance_b534d52673393a7a(mk<t_btree_iiii__0_1_2_3__1111::Type>()),
wrapper_rel_IntAttrInstance_b534d52673393a7a(9, *rel_IntAttrInstance_b534d52673393a7a, *this, "IntAttrInstance", std::array<const char *,4>{{"s:String","s:String","s:String","i:number"}}, std::array<const char *,4>{{"tree","agent","attr","value"}}, 0),
rel_delta_IntAttrInstance_b8fdf596d9aeece1(mk<t_btree_iiii__0_1_2_3__1111::Type>()),
rel_new_IntAttrInstance_46c3e1da2b668339(mk<t_btree_iiii__0_1_2_3__1111::Type>()),
rel_Start_ae1c7f13b7c0c47f(mk<t_btree_ii__0_1__11::Type>()),
wrapper_rel_Start_ae1c7f13b7c0c47f(10, *rel_Start_ae1c7f13b7c0c47f, *this, "Start", std::array<const char *,2>{{"s:String","i:number"}}, std::array<const char *,2>{{"tree","node"}}, 0),
rel_delta_Start_4a3bb0b3286f88b4(mk<t_btree_ii__0_1__11::Type>()),
rel_new_Start_8d183a7aef9127dc(mk<t_btree_ii__0_1__11::Type>()),
rel_Action_a442044b586ec8bf(mk<t_btree_iii__0_1_2__110__111::Type>()),
wrapper_rel_Action_a442044b586ec8bf(11, *rel_Action_a442044b586ec8bf, *this, "Action", std::array<const char *,3>{{"s:String","i:number","s:String"}}, std::array<const char *,3>{{"tree","node","action"}}, 0),
rel_ActionBegin_a6d9444aaed87d80(mk<t_btree_iii__0_1_2__111::Type>()),
wrapper_rel_ActionBegin_a6d9444aaed87d80(12, *rel_ActionBegin_a6d9444aaed87d80, *this, "ActionBegin", std::array<const char *,3>{{"s:String","i:number","s:String"}}, std::array<const char *,3>{{"tree","node","action"}}, 0),
stratum_disconnected0_ec65f654607345ea(symTable,recordTable,regexCache,pruneImdtRels,performIO,signalHandler,iter,ctr,inputDirectory,outputDirectory,*rel_disconnected0_615a847368b8df77,*rel_disconnected1_615a837368b8ddc4,*rel_disconnected2_615a867368b8e2dd,*rel_delta_disconnected0_3b2fbdedaad9411a,*rel_delta_disconnected1_3b2fbeedaad942cd,*rel_delta_disconnected2_3b2fbbedaad93db4,*rel_delta_AgentInitComplete_851d2e5f48d18d54,*rel_delta_Finish_a44c45a10dcdc5f7,*rel_delta_IntAttrInstance_b8fdf596d9aeece1,*rel_delta_Start_4a3bb0b3286f88b4,*rel_new_disconnected0_811c6a653f6f04c2,*rel_new_disconnected1_811c6b653f6f0675,*rel_new_disconnected2_811c68653f6f015c,*rel_new_AgentInitComplete_5e2c310bdba794cc,*rel_new_Finish_669fdb18649c352f,*rel_new_IntAttrInstance_46c3e1da2b668339,*rel_new_Start_8d183a7aef9127dc,*rel_ActionComplete_274fcea6d3a4990c,*rel_AgentInitComplete_bc76db663593fd33,*rel_Finish_ad59707375956ad2,*rel_IntAttr_9edc9675b07c35fd,*rel_IntAttrInstance_b534d52673393a7a,*rel_Parent_4eb514ebcb80553d,*rel_Precede_3d173237b8f1e4e1,*rel_Start_ae1c7f13b7c0c47f),
stratum_Action_cfcf50feab8c4aa2(symTable,recordTable,regexCache,pruneImdtRels,performIO,signalHandler,iter,ctr,inputDirectory,outputDirectory,*rel_Action_a442044b586ec8bf),
stratum_ActionBegin_75af5f53dacea827(symTable,recordTable,regexCache,pruneImdtRels,performIO,signalHandler,iter,ctr,inputDirectory,outputDirectory,*rel_Action_a442044b586ec8bf,*rel_ActionBegin_a6d9444aaed87d80,*rel_Start_ae1c7f13b7c0c47f),
stratum_ActionComplete_bfd78f8c2bfdb409(symTable,recordTable,regexCache,pruneImdtRels,performIO,signalHandler,iter,ctr,inputDirectory,outputDirectory,*rel_ActionComplete_274fcea6d3a4990c),
stratum_IntAttr_9b2e94aa39f85a96(symTable,recordTable,regexCache,pruneImdtRels,performIO,signalHandler,iter,ctr,inputDirectory,outputDirectory,*rel_IntAttr_9edc9675b07c35fd),
stratum_Parent_4038c03f7b83fbc8(symTable,recordTable,regexCache,pruneImdtRels,performIO,signalHandler,iter,ctr,inputDirectory,outputDirectory,*rel_Parent_4eb514ebcb80553d),
stratum_Precede_fc5d2637a8882446(symTable,recordTable,regexCache,pruneImdtRels,performIO,signalHandler,iter,ctr,inputDirectory,outputDirectory,*rel_Precede_3d173237b8f1e4e1){
addRelation("Parent", wrapper_rel_Parent_4eb514ebcb80553d, true, false);
addRelation("ActionComplete", wrapper_rel_ActionComplete_274fcea6d3a4990c, true, false);
addRelation("IntAttr", wrapper_rel_IntAttr_9edc9675b07c35fd, true, false);
addRelation("Precede", wrapper_rel_Precede_3d173237b8f1e4e1, true, false);
addRelation("+disconnected0", wrapper_rel_disconnected0_615a847368b8df77, false, false);
addRelation("+disconnected1", wrapper_rel_disconnected1_615a837368b8ddc4, false, false);
addRelation("+disconnected2", wrapper_rel_disconnected2_615a867368b8e2dd, false, false);
addRelation("AgentInitComplete", wrapper_rel_AgentInitComplete_bc76db663593fd33, false, false);
addRelation("Finish", wrapper_rel_Finish_ad59707375956ad2, false, true);
addRelation("IntAttrInstance", wrapper_rel_IntAttrInstance_b534d52673393a7a, false, true);
addRelation("Start", wrapper_rel_Start_ae1c7f13b7c0c47f, false, true);
addRelation("Action", wrapper_rel_Action_a442044b586ec8bf, true, true);
addRelation("ActionBegin", wrapper_rel_ActionBegin_a6d9444aaed87d80, false, true);
}

 Sf_ruleDemo::~Sf_ruleDemo(){
}

void Sf_ruleDemo::runFunction(std::string inputDirectoryArg,std::string outputDirectoryArg,bool performIOArg,bool pruneImdtRelsArg){

    this->inputDirectory  = std::move(inputDirectoryArg);
    this->outputDirectory = std::move(outputDirectoryArg);
    this->performIO       = performIOArg;
    this->pruneImdtRels   = pruneImdtRelsArg;

    // set default threads (in embedded mode)
    // if this is not set, and omp is used, the default omp setting of number of cores is used.
#if defined(_OPENMP)
    if (0 < getNumThreads()) { omp_set_num_threads(static_cast<int>(getNumThreads())); }
#endif

    signalHandler->set();
// -- query evaluation --
{
 std::vector<RamDomain> args, ret;
stratum_Parent_4038c03f7b83fbc8.run(args, ret);
}
{
 std::vector<RamDomain> args, ret;
stratum_ActionComplete_bfd78f8c2bfdb409.run(args, ret);
}
{
 std::vector<RamDomain> args, ret;
stratum_IntAttr_9b2e94aa39f85a96.run(args, ret);
}
{
 std::vector<RamDomain> args, ret;
stratum_Precede_fc5d2637a8882446.run(args, ret);
}
{
 std::vector<RamDomain> args, ret;
stratum_disconnected0_ec65f654607345ea.run(args, ret);
}
{
 std::vector<RamDomain> args, ret;
stratum_Action_cfcf50feab8c4aa2.run(args, ret);
}
{
 std::vector<RamDomain> args, ret;
stratum_ActionBegin_75af5f53dacea827.run(args, ret);
}

// -- relation hint statistics --
signalHandler->reset();
}

void Sf_ruleDemo::run(){
runFunction("", "", false, false);
}

void Sf_ruleDemo::runAll(std::string inputDirectoryArg,std::string outputDirectoryArg,bool performIOArg,bool pruneImdtRelsArg){
runFunction(inputDirectoryArg, outputDirectoryArg, performIOArg, pruneImdtRelsArg);
}

void Sf_ruleDemo::printAll([[maybe_unused]] std::string outputDirectoryArg){
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","tree\tnode\taction"},{"auxArity","0"},{"name","ActionBegin"},{"operation","output"},{"output-dir","."},{"params","{\"records\": {}, \"relation\": {\"arity\": 3, \"params\": [\"tree\", \"node\", \"action\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 3, \"types\": [\"s:String\", \"i:number\", \"s:String\"]}}"}});
if (!outputDirectoryArg.empty()) {directiveMap["output-dir"] = outputDirectoryArg;}
IOSystem::getInstance().getWriter(directiveMap, symTable, recordTable)->writeAll(*rel_ActionBegin_a6d9444aaed87d80);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","tree\tnode\tflag"},{"auxArity","0"},{"name","Finish"},{"operation","output"},{"output-dir","."},{"params","{\"records\": {}, \"relation\": {\"arity\": 3, \"params\": [\"tree\", \"node\", \"flag\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 3, \"types\": [\"s:String\", \"i:number\", \"i:number\"]}}"}});
if (!outputDirectoryArg.empty()) {directiveMap["output-dir"] = outputDirectoryArg;}
IOSystem::getInstance().getWriter(directiveMap, symTable, recordTable)->writeAll(*rel_Finish_ad59707375956ad2);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","tree\tnode"},{"auxArity","0"},{"name","Start"},{"operation","output"},{"output-dir","."},{"params","{\"records\": {}, \"relation\": {\"arity\": 2, \"params\": [\"tree\", \"node\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 2, \"types\": [\"s:String\", \"i:number\"]}}"}});
if (!outputDirectoryArg.empty()) {directiveMap["output-dir"] = outputDirectoryArg;}
IOSystem::getInstance().getWriter(directiveMap, symTable, recordTable)->writeAll(*rel_Start_ae1c7f13b7c0c47f);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","tree\tagent\tattr\tvalue"},{"auxArity","0"},{"name","IntAttrInstance"},{"operation","output"},{"output-dir","."},{"params","{\"records\": {}, \"relation\": {\"arity\": 4, \"params\": [\"tree\", \"agent\", \"attr\", \"value\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 4, \"types\": [\"s:String\", \"s:String\", \"s:String\", \"i:number\"]}}"}});
if (!outputDirectoryArg.empty()) {directiveMap["output-dir"] = outputDirectoryArg;}
IOSystem::getInstance().getWriter(directiveMap, symTable, recordTable)->writeAll(*rel_IntAttrInstance_b534d52673393a7a);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","tree\tnode\taction"},{"auxArity","0"},{"name","Action"},{"operation","output"},{"output-dir","."},{"params","{\"records\": {}, \"relation\": {\"arity\": 3, \"params\": [\"tree\", \"node\", \"action\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 3, \"types\": [\"s:String\", \"i:number\", \"s:String\"]}}"}});
if (!outputDirectoryArg.empty()) {directiveMap["output-dir"] = outputDirectoryArg;}
IOSystem::getInstance().getWriter(directiveMap, symTable, recordTable)->writeAll(*rel_Action_a442044b586ec8bf);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}

void Sf_ruleDemo::loadAll([[maybe_unused]] std::string inputDirectoryArg){
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","tree\tnode1\tnode2"},{"auxArity","0"},{"fact-dir","."},{"name","Parent"},{"operation","input"},{"params","{\"records\": {}, \"relation\": {\"arity\": 3, \"params\": [\"tree\", \"node1\", \"node2\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 3, \"types\": [\"s:String\", \"i:number\", \"i:number\"]}}"}});
if (!inputDirectoryArg.empty()) {directiveMap["fact-dir"] = inputDirectoryArg;}
IOSystem::getInstance().getReader(directiveMap, symTable, recordTable)->readAll(*rel_Parent_4eb514ebcb80553d);
} catch (std::exception& e) {std::cerr << "Error loading Parent data: " << e.what() << '\n';
exit(1);
}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","tree\tnode"},{"auxArity","0"},{"fact-dir","."},{"name","ActionComplete"},{"operation","input"},{"params","{\"records\": {}, \"relation\": {\"arity\": 2, \"params\": [\"tree\", \"node\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 2, \"types\": [\"s:String\", \"i:number\"]}}"}});
if (!inputDirectoryArg.empty()) {directiveMap["fact-dir"] = inputDirectoryArg;}
IOSystem::getInstance().getReader(directiveMap, symTable, recordTable)->readAll(*rel_ActionComplete_274fcea6d3a4990c);
} catch (std::exception& e) {std::cerr << "Error loading ActionComplete data: " << e.what() << '\n';
exit(1);
}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","agent\tattr\tvalue"},{"auxArity","0"},{"fact-dir","."},{"name","IntAttr"},{"operation","input"},{"params","{\"records\": {}, \"relation\": {\"arity\": 3, \"params\": [\"agent\", \"attr\", \"value\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 3, \"types\": [\"s:String\", \"s:String\", \"i:number\"]}}"}});
if (!inputDirectoryArg.empty()) {directiveMap["fact-dir"] = inputDirectoryArg;}
IOSystem::getInstance().getReader(directiveMap, symTable, recordTable)->readAll(*rel_IntAttr_9edc9675b07c35fd);
} catch (std::exception& e) {std::cerr << "Error loading IntAttr data: " << e.what() << '\n';
exit(1);
}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","tree\tnode1\tnode2"},{"auxArity","0"},{"fact-dir","."},{"name","Precede"},{"operation","input"},{"params","{\"records\": {}, \"relation\": {\"arity\": 3, \"params\": [\"tree\", \"node1\", \"node2\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 3, \"types\": [\"s:String\", \"i:number\", \"i:number\"]}}"}});
if (!inputDirectoryArg.empty()) {directiveMap["fact-dir"] = inputDirectoryArg;}
IOSystem::getInstance().getReader(directiveMap, symTable, recordTable)->readAll(*rel_Precede_3d173237b8f1e4e1);
} catch (std::exception& e) {std::cerr << "Error loading Precede data: " << e.what() << '\n';
exit(1);
}
try {std::map<std::string, std::string> directiveMap({{"IO","file"},{"attributeNames","tree\tnode\taction"},{"auxArity","0"},{"fact-dir","."},{"name","Action"},{"operation","input"},{"params","{\"records\": {}, \"relation\": {\"arity\": 3, \"params\": [\"tree\", \"node\", \"action\"]}}"},{"types","{\"ADTs\": {}, \"records\": {}, \"relation\": {\"arity\": 3, \"types\": [\"s:String\", \"i:number\", \"s:String\"]}}"}});
if (!inputDirectoryArg.empty()) {directiveMap["fact-dir"] = inputDirectoryArg;}
IOSystem::getInstance().getReader(directiveMap, symTable, recordTable)->readAll(*rel_Action_a442044b586ec8bf);
} catch (std::exception& e) {std::cerr << "Error loading Action data: " << e.what() << '\n';
exit(1);
}
}

void Sf_ruleDemo::dumpInputs(){
try {std::map<std::string, std::string> rwOperation;
rwOperation["IO"] = "stdout";
rwOperation["name"] = "Parent";
rwOperation["types"] = "{\"relation\": {\"arity\": 3, \"auxArity\": 0, \"types\": [\"s:String\", \"i:number\", \"i:number\"]}}";
IOSystem::getInstance().getWriter(rwOperation, symTable, recordTable)->writeAll(*rel_Parent_4eb514ebcb80553d);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> rwOperation;
rwOperation["IO"] = "stdout";
rwOperation["name"] = "ActionComplete";
rwOperation["types"] = "{\"relation\": {\"arity\": 2, \"auxArity\": 0, \"types\": [\"s:String\", \"i:number\"]}}";
IOSystem::getInstance().getWriter(rwOperation, symTable, recordTable)->writeAll(*rel_ActionComplete_274fcea6d3a4990c);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> rwOperation;
rwOperation["IO"] = "stdout";
rwOperation["name"] = "IntAttr";
rwOperation["types"] = "{\"relation\": {\"arity\": 3, \"auxArity\": 0, \"types\": [\"s:String\", \"s:String\", \"i:number\"]}}";
IOSystem::getInstance().getWriter(rwOperation, symTable, recordTable)->writeAll(*rel_IntAttr_9edc9675b07c35fd);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> rwOperation;
rwOperation["IO"] = "stdout";
rwOperation["name"] = "Precede";
rwOperation["types"] = "{\"relation\": {\"arity\": 3, \"auxArity\": 0, \"types\": [\"s:String\", \"i:number\", \"i:number\"]}}";
IOSystem::getInstance().getWriter(rwOperation, symTable, recordTable)->writeAll(*rel_Precede_3d173237b8f1e4e1);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> rwOperation;
rwOperation["IO"] = "stdout";
rwOperation["name"] = "Action";
rwOperation["types"] = "{\"relation\": {\"arity\": 3, \"auxArity\": 0, \"types\": [\"s:String\", \"i:number\", \"s:String\"]}}";
IOSystem::getInstance().getWriter(rwOperation, symTable, recordTable)->writeAll(*rel_Action_a442044b586ec8bf);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}

void Sf_ruleDemo::dumpOutputs(){
try {std::map<std::string, std::string> rwOperation;
rwOperation["IO"] = "stdout";
rwOperation["name"] = "ActionBegin";
rwOperation["types"] = "{\"relation\": {\"arity\": 3, \"auxArity\": 0, \"types\": [\"s:String\", \"i:number\", \"s:String\"]}}";
IOSystem::getInstance().getWriter(rwOperation, symTable, recordTable)->writeAll(*rel_ActionBegin_a6d9444aaed87d80);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> rwOperation;
rwOperation["IO"] = "stdout";
rwOperation["name"] = "Finish";
rwOperation["types"] = "{\"relation\": {\"arity\": 3, \"auxArity\": 0, \"types\": [\"s:String\", \"i:number\", \"i:number\"]}}";
IOSystem::getInstance().getWriter(rwOperation, symTable, recordTable)->writeAll(*rel_Finish_ad59707375956ad2);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> rwOperation;
rwOperation["IO"] = "stdout";
rwOperation["name"] = "Start";
rwOperation["types"] = "{\"relation\": {\"arity\": 2, \"auxArity\": 0, \"types\": [\"s:String\", \"i:number\"]}}";
IOSystem::getInstance().getWriter(rwOperation, symTable, recordTable)->writeAll(*rel_Start_ae1c7f13b7c0c47f);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> rwOperation;
rwOperation["IO"] = "stdout";
rwOperation["name"] = "IntAttrInstance";
rwOperation["types"] = "{\"relation\": {\"arity\": 4, \"auxArity\": 0, \"types\": [\"s:String\", \"s:String\", \"s:String\", \"i:number\"]}}";
IOSystem::getInstance().getWriter(rwOperation, symTable, recordTable)->writeAll(*rel_IntAttrInstance_b534d52673393a7a);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
try {std::map<std::string, std::string> rwOperation;
rwOperation["IO"] = "stdout";
rwOperation["name"] = "Action";
rwOperation["types"] = "{\"relation\": {\"arity\": 3, \"auxArity\": 0, \"types\": [\"s:String\", \"i:number\", \"s:String\"]}}";
IOSystem::getInstance().getWriter(rwOperation, symTable, recordTable)->writeAll(*rel_Action_a442044b586ec8bf);
} catch (std::exception& e) {std::cerr << e.what();exit(1);}
}

SymbolTable& Sf_ruleDemo::getSymbolTable(){
return symTable;
}

RecordTable& Sf_ruleDemo::getRecordTable(){
return recordTable;
}

void Sf_ruleDemo::setNumThreads(std::size_t numThreadsValue){
SouffleProgram::setNumThreads(numThreadsValue);
symTable.setNumLanes(getNumThreads());
recordTable.setNumLanes(getNumThreads());
regexCache.setNumLanes(getNumThreads());
}

void Sf_ruleDemo::executeSubroutine(std::string name,const std::vector<RamDomain>& args,std::vector<RamDomain>& ret){
if (name == "+disconnected0") {
stratum_disconnected0_ec65f654607345ea.run(args, ret);
return;}
if (name == "Action") {
stratum_Action_cfcf50feab8c4aa2.run(args, ret);
return;}
if (name == "ActionBegin") {
stratum_ActionBegin_75af5f53dacea827.run(args, ret);
return;}
if (name == "ActionComplete") {
stratum_ActionComplete_bfd78f8c2bfdb409.run(args, ret);
return;}
if (name == "IntAttr") {
stratum_IntAttr_9b2e94aa39f85a96.run(args, ret);
return;}
if (name == "Parent") {
stratum_Parent_4038c03f7b83fbc8.run(args, ret);
return;}
if (name == "Precede") {
stratum_Precede_fc5d2637a8882446.run(args, ret);
return;}
fatal(("unknown subroutine " + name).c_str());
}

} // namespace  souffle
namespace souffle {
SouffleProgram *newInstance_ruleDemo(){return new  souffle::Sf_ruleDemo;}
SymbolTable *getST_ruleDemo(SouffleProgram *p){return &reinterpret_cast<souffle::Sf_ruleDemo*>(p)->getSymbolTable();}
} // namespace souffle

#ifndef __EMBEDDED_SOUFFLE__
#include "souffle/CompiledOptions.h"
int main(int argc, char** argv)
{
try{
souffle::CmdOptions opt(R"(bttest.dl)",
R"()",
R"()",
false,
R"()",
1);
if (!opt.parse(argc,argv)) return 1;
souffle::Sf_ruleDemo obj;
#if defined(_OPENMP) 
obj.setNumThreads(opt.getNumJobs());

#endif
obj.runAll(opt.getInputFileDir(), opt.getOutputFileDir());
return 0;
} catch(std::exception &e) { souffle::SignalHandler::instance()->error(e.what());}
}
#endif

namespace  souffle {
using namespace souffle;
class factory_Sf_ruleDemo: souffle::ProgramFactory {
public:
souffle::SouffleProgram* newInstance();
 factory_Sf_ruleDemo();
private:
};
} // namespace  souffle
namespace  souffle {
using namespace souffle;
souffle::SouffleProgram* factory_Sf_ruleDemo::newInstance(){
return new  souffle::Sf_ruleDemo();
}

 factory_Sf_ruleDemo::factory_Sf_ruleDemo():
souffle::ProgramFactory("ruleDemo"){
}

} // namespace  souffle
namespace souffle {

#ifdef __EMBEDDED_SOUFFLE__
extern "C" {
souffle::factory_Sf_ruleDemo __factory_Sf_ruleDemo_instance;
}
#endif
} // namespace souffle

