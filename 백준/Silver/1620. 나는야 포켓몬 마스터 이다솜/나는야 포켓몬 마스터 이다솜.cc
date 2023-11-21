#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(void) {

  ios::sync_with_stdio(0);
  cin.tie(0);
  // input number N : number of definitions in glossary
  int number_of_pokemon = 0;

  // input number M : number of questions to solve
  int number_of_question = 0;

  // Input two variables on the first line
  cin >> number_of_pokemon >> number_of_question;

  // Declare a map to find a key
  map<string, int> name_to_key;

  // Declare an array to find pokemon
  vector<string> key_to_name;
  // Declare empty input_string for input
  string input_string = "";

  // Iterate for record pokemons
  for (int i = 0; i < number_of_pokemon; i++) {
    // Declare a name of pokemon
    cin >> input_string;
    // Record a name and number of pokemon
    // Access by name to key
    name_to_key.insert({input_string, i});
    // Access by key to name
    key_to_name.push_back(input_string);
  }

  // Question and answers
  for (int i = 0; i < number_of_question; i++) {

    // Input a question
    cin >> input_string;

    if (isdigit(input_string[0])) {
      // Find by index written on Integer.
      cout << key_to_name.at(stoi(input_string) - 1) << "\n";

    } else {
      // If it's not,it's between A to Z
      cout << name_to_key[input_string] + 1 << "\n";
    }
  }
  return 0;
}