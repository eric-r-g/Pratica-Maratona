#include <iostream> 

using namespace std;

int main(){
    int n, h;
    cin >> n >> h;
    int sum = 0;

    for(int i = 0; i < n; ++i){
        int entr; cin >> entr;

        if (h >= entr) sum++;
    }

    cout << sum << "\n";
}