#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int N; // number of fruits
    cin >> N;

    // Save the values
    vector<int> tang(N);
    for (int i = 0; i < N; i++) {
        cin >> tang[i];
    }
    
    unordered_map<int, int> fruitStatus;
    
    int front = 0; // front: sliding window
    int result = 0; // result: for output
    for(int back = 0; back < N; back++){ // Dynamically count
        fruitStatus[tang[back]]++;
        
        // Check condition
        while (fruitStatus.size() > 2) {
            // Shrink the window for result
            fruitStatus[tang[front]]--;
            
            // When the amount of such type runs out
            if (fruitStatus[tang[front]] == 0) {
                fruitStatus.erase(tang[front]);
            }
            front++;
        }
       
        result = max(result, back - front + 1);
    }

    cout << result << '\n';
    return 0;
}
