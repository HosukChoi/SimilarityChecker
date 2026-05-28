#include <string>
#include <algorithm>

using std::string;

class SimilarityChecker {
public:
	SimilarityChecker() = default;


	int CalcLengthScore(const string& str1, const string& str2) {
		int long_length = std::max(str1.size(), str2.size());
		int short_length = std::min(str1.size(), str2.size());
		double gap = static_cast<double>(long_length - short_length);
		return std::max(0,static_cast<int>(
			double(1.0 - (gap / double(short_length))) * 60.0));
	}

	int CalcAlphabetScore(string str1, string str2) {
		return 0;
	}
};