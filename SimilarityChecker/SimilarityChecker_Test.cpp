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
	void check_calc_alphabet_score(int expect, string str1, string str2) {
		int score = _similarity_checker.CalcAlphabetScore(str1, str2);
		EXPECT_EQ(expect, score);
	}
};

TEST_F(SimilarityCheckerFixture, CheckStringLengthFullScore) {
	check_calc_length_score(60, "ASD", "DSA");
}

TEST_F(SimilarityCheckerFixture, CheckStringLengthZeroScore1) {
	check_calc_length_score(0, "A", "BB");
}

TEST_F(SimilarityCheckerFixture, CheckStringLengthZeroScore2) {
	check_calc_length_score(0, "AAAAAA", "B");
}

TEST_F(SimilarityCheckerFixture, CheckStringLengthLowScore1) {
	check_calc_length_score(20, "AAABB", "BAA");
}

TEST_F(SimilarityCheckerFixture, CheckStringLengthLowScore2) {
	check_calc_length_score(30, "AA", "AAE");
}

TEST_F(SimilarityCheckerFixture, CheckStringAlphabetScore) {
	check_calc_alphabet_score(0, "", "");
}
