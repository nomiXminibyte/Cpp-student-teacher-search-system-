# include <iostream>
# include <string>
using namespace std;

int main() {
    cout << "Enter a number" << endl;
    int num_get;
    cin >> num_get;
    int arr[5] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i++) {
    if (arr[i] >= num_get) {
        cout << "Key found at index: " << i << endl;
    }
    else {
        cout << "Key  found at index: " << i << endl;
        
    
}
    }
    return 0;

}