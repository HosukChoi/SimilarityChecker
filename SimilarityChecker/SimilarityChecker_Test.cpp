#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

using namespace testing;

class SimilarityCheckerFixture : public Test {
public:
	SimilarityChecker _similarity_checker;
	void check_calc_length_score(int expect, string str1, string str2) {
		int score = _similarity_checker.CalcLengthScore(str1, str2);
		EXPECT_EQ(expect, score);
	}
};

TEST_F(SimilarityCheckerFixture, CheckStringLengthFullScore) {
	check_calc_length_score(60, "ASD", "DSA");
}
