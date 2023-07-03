/**
 * @file Main.cc
 * @author Chrystian Melo (meloo.chrys@gmail.com)
 * @brief Classe principal do projeto.
 *
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include <vector>

 /**
  * @brief Retorna o número mínimo de ligas necessárias para atender a uma demanda específica.
  *
  * @param amount A quantidade de ligas desejada.
  * @param availableSizes O vetor contendo os tamanhos disponíveis das ligas.
  * @return O número mínimo de ligas necessárias para atender à demanda especificada.
  */
int minimumLigas(int amount, const std::vector<int>& availableSizes) {
	std::vector<int> dp(amount + 1, amount + 1);
	dp[0] = 0;

	for (int i = 1; i <= amount; i++) {
		for (std::size_t j = 0; j < availableSizes.size(); j++) {
			if (availableSizes[j] <= i) {
				int subproblema = dp[i - availableSizes[j]];
				if (subproblema != (amount + 1) && subproblema + 1 < dp[i]) {
					dp[i] = subproblema + 1;
				}
			}
		}
	}

	return dp[amount];
}

/**
 * @brief Classe principal do projeto.
 */
int main() {
	int loop;
	std::cin >> loop;

	std::vector<int> output;
	for (int i = 0; i < loop; i++) {
		int amount, vetSize;
		std::cin >> vetSize >> amount;

		std::vector<int> availableCoins;
		for (int j = 0; j < vetSize; j++) {
			int v1;
			std::cin >> v1;
			availableCoins.push_back(v1);
		}

		int minCoins = minimumLigas(amount, std::move(availableCoins));

		output.push_back(minCoins);
	}

	for (int v : output)
		std::cout << v << std::endl;

	return 0;
}
