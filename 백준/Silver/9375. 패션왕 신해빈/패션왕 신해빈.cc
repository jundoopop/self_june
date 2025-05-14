#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // Number to iterate
  int n;
  cin >> n;

  string category, name;

  while (n--) {
    map<string, int> m;
    int m_size;
    cin >> m_size; // Number of attributes
    while (m_size--) {
      // name은 사용 x
      cin >> name >> category;
      // find: similar as Python's dict.get()
      if (m.find(category) == m.end()) {
        m.insert({category, 1});
      } else
        m[category]++;
    }

    int result = 1;
    for (auto i : m) {
      result *= (i.second + 1);
    }
    result -= 1;
    cout << result << '\n';
  }

  return 0;
}