#include "queue.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>

class TestMemory : public IMemory {};

template <typename T> class QueueFixture : public ::testing::Test {};

using Types = ::testing::Types<int, float, std::string>;
TYPED_TEST_SUITE(QueueFixture, Types) ;

TYPED_TEST(QueueFixture, EMPTY) {
  
}
