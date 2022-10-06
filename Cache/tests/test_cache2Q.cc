#include <gtest/gtest.h>

#include "cache2Q.hh"

int getPage (int pageKey)
{
    return pageKey;
}

TEST(LRUCacheTest, BasicTest)
{
    cache::CacheLRU<int> cache{4};
    int input[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 4, 3, 4};
    int hits = 0;
    for (int i = 0; i < sizeof(input) / sizeof(input[0]); i++)
    {
        hits += cache.fetch(input[i], getPage);
    }

    EXPECT_EQ(hits, 6);
}


TEST(Cache2QTest, BasicTest1)
{
    cache::Cache2Q<int> cache{15};
    int input[] = {1, 2, 3, 4, 5, 6, 7, 1, 2, 6};
    int hits = 0;
    for (int i = 0; i < sizeof(input) / sizeof(input[0]); i++)
    {
        hits += cache.fetch(input[i], getPage);
    }

    EXPECT_EQ(hits, 3);
}

TEST(Cache2QTest, BasicTest2)
{
    cache::Cache2Q<int> cache{4};
    int input[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 4, 3, 4};
    int hits = 0;
    for (int i = 0; i < sizeof(input) / sizeof(input[0]); i++)
    {
        hits += cache.fetch(input[i], getPage);
    }

    EXPECT_EQ(hits, 1);
}

TEST(Cache2QTest, BasicTest3)
{
    cache::Cache2Q<int> cache{1};
    int input[] = {1, 2, 3, 4, 5, 5, 5, 1, 2, 3};
    int hits = 0;
    for (int i = 0; i < sizeof(input) / sizeof(input[0]); i++)
    {
        hits += cache.fetch(input[i], getPage);
    }

    EXPECT_EQ(hits, 2);
}
