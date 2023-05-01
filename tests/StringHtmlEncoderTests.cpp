#include "StringHtmlEncoder.h"
#include <gtest/gtest.h>

TEST(StringHtmlEncoderTests, Encode_StringWithoutSpaces_ReturnSameString)
{
    auto result = StringHtmlEncoder::Encode("1234");

    ASSERT_EQ(result, "1234");
}

TEST(StringHtmlEncoderTests, Encode_StringWithOneSpace_ReplaceSpaceWithEncoding)
{
    auto result = StringHtmlEncoder::Encode("A B");

    ASSERT_EQ("A%2fB", result);
}

TEST(StringHtmlEncoderTests, Encode_StringWithMultipleSpaces_ReplaceSpacesWithEncoding)
{
    auto result = StringHtmlEncoder::Encode("A B C D");

    ASSERT_EQ("A%2fB%2fC%2fD", result);
}

struct EncoderTestRow
{
    EncoderTestRow(std::string input, std::string expected) : input(input), expected(expected) {}

    std::string input, expected;
};

::std::ostream& operator<<(::std::ostream& os, const EncoderTestRow& row)
{
    return os << "input:" << row.input << " expected result: " << row.expected;
}

class StringHtmlEncoderTests : public ::testing::TestWithParam<EncoderTestRow>
{
};

TEST_P(StringHtmlEncoderTests, EncodeStringToHtml)
{
    auto row = GetParam();

    auto result = StringHtmlEncoder::Encode(row.input);

    ASSERT_EQ(row.expected, result);
}

INSTANTIATE_TEST_SUITE_P(WhiteSpaceEncoding, StringHtmlEncoderTests, ::testing::Values(EncoderTestRow("A", "A"), EncoderTestRow("A B", "A%2fB"), EncoderTestRow("A B C D", "A%2fB%2fC%2fD")));

// Define a parameter generator that generates test parameters
std::vector<int> test_data = {1, 2, 3, 4, 5};

class TestParamGenerator : public ::testing::TestWithParam<int>
{
};

// Instantiate the parameter generator with the test data
INSTANTIATE_TEST_SUITE_P(TestData, TestParamGenerator, ::testing::ValuesIn(test_data));

// Define the test case using the generated parameter
TEST_P(TestParamGenerator, TestFunction)
{
    int param_value = GetParam();
    // ... perform test using param_value ...
    EXPECT_EQ(param_value, param_value); // Example test assertion
}

TEST(IteratorTest, TestFunction)
{
    // Use a range-based for loop to iterate over the test data
    for (const auto& param_value : ::testing::ValuesIn(test_data.begin(), test_data.end()))
    {
        // ... perform test using param_value ...
        EXPECT_EQ(param_value, param_value); // Example test assertion
    }
}