#include <string>
#include <algorithm>
#include <set>

using std::string;
using std::set;

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
		auto extracted_used_alphabet_set = extact_used_alphabet(str1, str2);
		int total_cnt = extracted_used_alphabet_set.size();
		int same_cnt = calc_same_alphabet_count(str1, str2, extracted_used_alphabet_set);

		return static_cast<double>(same_cnt) / static_cast<double>(total_cnt) * 40;
	}

private:
	set<char> extact_used_alphabet(const string& str1, const string& str2) {
		set<char> check;
		for (auto ch : str1) {
			check.insert(ch);
		}
		for (auto ch : str2) {
			check.insert(ch);
		}

		return check;
	}

	int calc_same_alphabet_count(const string& str1, const string& str2, const set<char>& extracted_used_alphabet_set) {
		string sum_string = str1 + str2;
		int same_cnt = 0;
		for (auto ch : extracted_used_alphabet_set) {
			int str1_count = std::count(str1.begin(), str1.end(), ch);
			int str2_count = std::count(str2.begin(), str2.end(), ch);
			if (str1_count * str2_count != 0)
				same_cnt++;
		}

		return same_cnt;
	}
};