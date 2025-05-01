#include <iostream>
#include <string>
#include <unordered_map>

int main() {

  // Boos IO performance
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int sizeToRecord, casesToSearch;
  std::cin >> sizeToRecord >> casesToSearch;

  // Record the address and password
  std::unordered_map<std::string, std::string> pwMap;

  // Save the addresses
  while (sizeToRecord-- > 0) {
    std::string addressToRegister, password;
    std::cin >> addressToRegister >> password;
    pwMap[addressToRegister] = password;
  }

  // Search and print the passwords
  while (casesToSearch-- > 0) {
    std::string addressToSearch;
    std::cin >> addressToSearch;
    std::cout << pwMap[addressToSearch] << '\n';
  }

  return 0;
}