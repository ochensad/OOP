
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "Set_release/set/Set.h"

#include <algorithm>

using namespace testing;

TEST(MySuiteName, SizeCase)
{
    set_s::Set<int> a;
    a = set_s::Set<int>(4, 1, 2, 3, 4);
    size_t s = a.get_size();
    size_t ex = 4;
    ASSERT_EQ(ex, s);
}

TEST(MySuiteName, CreateCase)
{
    set_s::Set<int> a;
    a = set_s::Set<int>(4, 1, 2, 3, 4);
    set_s::Set<int> b;
    int c[4] = {1, 2, 3, 4};
    b = set_s::Set<int>(c, 4);
    bool ans = (a == b);
    bool ex = true;
    ASSERT_EQ(ex, ans);
}

TEST(MySuiteName, CreateOneElCase)
{
    set_s::Set<int> a;
    a = set_s::Set<int>(4);
    set_s::Set<int> b;
    b = set_s::Set<int>(2,1,2);
    bool ans = (a != b);
    bool ex = true;
    ASSERT_EQ(ex, ans);
}

TEST(MySuiteName, CreateOneByOneCase)
{
    set_s::Set<int> b;
    int c[4] = {1, 4, 3, 2};
    b = set_s::Set<int>(c, 4);
    //set_s::Set<int> d(b);
    bool ans = true;
    bool ex = true;
    ASSERT_EQ(ex, ans);
}

TEST(MySuiteName, Addcase)
{
    set_s::Set<int> a;
    a.add(3);
    size_t s = a.get_size();
    size_t ex = 1;
    ASSERT_EQ(ex, s);
}

TEST(MySuiteName, Popcase)
{
    set_s::Set<int> a;
    a.add(3);
    a.erase(3);
    size_t s = a.get_size();
    size_t ex = 0;
    ASSERT_EQ(ex, s);
}

TEST(MySuiteName, UnionCase)
{
    set_s::Set<int> a;
    a = set_s::Set<int>(4);
    set_s::Set<int> b;
    b = set_s::Set<int>(2,1,2);
    set_s::Set<int> c;
    c = a.set_union(b);
    set_s::Set<int> d;
    d = set_s::Set<int>(3, 4, 1, 2);
    bool ans = (d == c);
    bool ex = true;
    ASSERT_EQ(ex, ans);
}

TEST(MySuiteName, DifCase)
{
    set_s::Set<int> a;
    a = set_s::Set<int>(4);
    set_s::Set<int> b;
    b = set_s::Set<int>(4,1,2, 4, 3);
    set_s::Set<int> c;
    c = b.set_dif(a);
    set_s::Set<int> d;
    d = set_s::Set<int>(3, 1, 2, 3);
    bool ans = (d == c);
    bool ex = true;
    ASSERT_EQ(ex, ans);
}

TEST(MySuiteName, CrossCase)
{
    set_s::Set<int> a;
    a = set_s::Set<int>(2, 4, 5);
    set_s::Set<int> b;
    b = set_s::Set<int>(4,1,2, 4, 3);
    set_s::Set<int> c;
    c = set_s::Set<int>(4);
    set_s::Set<int> d;
    d = set_s::Set<int>(4);
    bool ans = (d == c);
    bool ex = true;
    ASSERT_EQ(ex, ans);
}

TEST(MySuiteName, SymDifCase)
{
    set_s::Set<int> a;
    a = set_s::Set<int>(4, 1, 2, 3, 4);
    set_s::Set<int> b;
    b = set_s::Set<int>(4,5, 3, 4, 6);
    set_s::Set<int> c;
    c = b.set_sym_dif(a);
    set_s::Set<int> d;
    d = set_s::Set<int>(4, 1, 2, 5 ,6);
    bool ans = (d == c);
    bool ex = true;
    ASSERT_EQ(ex, ans);
}

