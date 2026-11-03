#include <iostream>
#include <string>
#include <vector>
#include <ranges>
#include <map>
#include <set>
#include <algorithm>
#include <limits>
#include <print>

namespace views = std::views;
namespace ranges = std::ranges;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, K;
    if (!(std::cin >> N >> K >> M)) return -1;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::map<std::string, int> vcount;
    std::string line;

    // Statistics
    while (std::getline(std::cin, line)) {
        if (line == "END")
            break;
        

        auto word_views = line
            | views::split(' ')
            | views::transform([](auto &&rng) {
                return std::string(rng.begin(), rng.end());
            })
            | views::filter([](const auto &s) {
                return !s.empty();
            });

        std::vector<std::string> candidates(word_views.begin(), word_views.end());

        // Empty vote
        if (candidates.empty()) continue;

        // Exceed vote limit
        if (candidates.size() > static_cast<size_t>(K)) continue;

        // Not unique
        std::set<std::string> uniqueness(candidates.begin(), candidates.end());
        if (candidates.size() != uniqueness.size()) continue;

        // Merge to count data
        for (const auto& name : candidates) {
            ++vcount[name];
        }
    }

    // Sort
    std::vector<std::pair<std::string, int>> votes(vcount.begin(), vcount.end());
    ranges::sort(votes, [](const auto& a, const auto& b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });

    bool has_majority = false;

    for (const auto& [name, count] : votes) {
        if (count * 2 >= N) {
            has_majority = true;
            std::println("{} {}", name, count);
        }
    }

    if (!has_majority) {
        size_t lim = std::min(votes.size(), static_cast<size_t>(M));

        if (!lim) return 0;

        int thres = votes[lim - 1].second;

        for (const auto& [name, count] : votes) {
            if (count >= thres) {
                std::println("{} {}", name, count);
            }
            else {
                break;
            }
        }
    }
    return 0;
}

