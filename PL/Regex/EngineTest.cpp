#include "UnitTest.hpp"
#include "Engine.hpp"

using namespace RE;

TEST_CASE(EngineTest)
{
    Engine eng0("(abc)**");
    EXPECT_EQ(eng0.search("8980abababcabcabcabab"), "abcabcabc");
    EXPECT_TRUE(eng0.match(""));
    EXPECT_FALSE(eng0.match("abcabcabcabcc"));

    Engine eng1("a*a*[abc]aaa");
    EXPECT_EQ(eng1.search("cbaaabaaaac"), "baaa");
    EXPECT_TRUE(eng1.match("aaaa"));

    Engine eng2("abc|(a*(cb)?)+");
    EXPECT_EQ(eng2.search("abc"), "abc");
    EXPECT_EQ(eng2.search("aaaaaacbaacbcbesa"), "aaaaaacbaacbcb");
    EXPECT_TRUE(eng2.match("cbcbcbaaa"));

    Engine eng3("[012]{1,3}(-[34567890]{1,3}){3}");
    EXPECT_TRUE(eng3.match("21-3-456-67"));
    EXPECT_FALSE(eng3.match("21-3-67"));
    EXPECT_EQ(eng3.search("sfe890-21-34-456-34-23"), "21-34-456-34");
}