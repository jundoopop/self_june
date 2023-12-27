#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(void) {
  // Contains the number of alphabets in each sentences,
  // the number of counted a to z by indices
  std::vector<int> frequencyOfAlphabets = {0, 0, 0, 0, 0, 0, 0, 0, 0,
                                           0, 0, 0, 0, 0, 0, 0, 0, 0,
                                           0, 0, 0, 0, 0, 0, 0, 0};

  int cnt;              // cnt is a number of sentences, it could not exceed 50
  std::string sentence; // Contains the sentence to be inputted

  for (int i = 0; i < 50; i++) // For each sentence
  {
    getline(std::cin, sentence);    // Input the sentence
    for (auto character : sentence) // For each character in the sentence
    {
      if ((int)character >= 97 && (int)character <= 133)
        frequencyOfAlphabets[character -
                             'a']++; // Increase the number of alphabets by 1
    }
  }

  const int mostFrequentAlphabet = *std::max_element(
      frequencyOfAlphabets.begin(),
      frequencyOfAlphabets.end()); // Contains the most frequent alphabet

  for (int i = 0; i < 26; i++) { // For each alphabet
    if (frequencyOfAlphabets.at(i) ==
        mostFrequentAlphabet) // If the number of alphabets is the most frequent
      std::cout << (char)(i + 'a'); // Print the alphabet
  }

  return 0;
}