#include <string>
#include <algorithm>

using std::string;

class SimilarityChecker {
public:
	SimilarityChecker() = default;


	int CalcLengthScore(const string& str1, const string& str2) {
		int long_length = std::max(str1.size(), str2.size());
		int short_length = std::min(str1.size(), str2.size());
		int gap = long_length - short_length;
		int result = (1.0 - double(gap / short_length)) * 60;
		return result;
	}
};