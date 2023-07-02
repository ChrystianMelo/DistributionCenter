/**
 * @file Main.cc
 * @author Chrystian Melo (meloo.chrys@gmail.com)
 * @brief Classe principal do projeto.
 *
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include <vector>

int minimumLigas(int amount, const std::vector<int>& availableSizes) {
    std::vector<int> dp(amount + 1, INT_MAX); // Vetor de memoização
    dp[0] = 0; // Caso base: não é necessário nenhuma liga para demanda zero

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < availableSizes.size(); j++) {
            if (availableSizes[j] <= i) {
                int subproblema = dp[i - availableSizes[j]];
                if (subproblema != INT_MAX && subproblema + 1 < dp[i]) {
                    dp[i] = subproblema + 1;
                }
            }
        }
    }

    return dp[amount];
}

int main() {
    int loop;
    std::cin >> loop;

    std::vector<int> output;
    for (int i = 0; i < loop; i++) {
        int amount, vetSize;
        std::cin >> vetSize >> amount;

        std::vector<int> availableCoins;
        for (int i = 0; i < vetSize; i++) {
            int v1;
            std::cin >> v1;
            availableCoins.push_back(v1);
        }

        int minCoins = minimumLigas(amount, std::move(availableCoins));

        output.push_back(minCoins);
    }

    for (int v : output)
        std::cout << v <<std::endl;

    return 0;
}