#include <bits/stdc++.h>
#include <fstream>
#define TASK "test"
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i,a,b) for(int i = a; i <= b ; i++)
#define FOD(i,a,b) for(int i = a; i >= b ; i--)
#define task "test"
#define MASK(i) (1LL << (i))
#define c_bit(i) __builtin_popcountll(i) // đếm số bit đang bật
#define BIT(x, i) ((x) & MASK(i)) // trạng thái của bit thứ i trong x
#define SET_ON(x, i) ((x) | MASK(i)) // bật bit thứ i trong x
#define SET_OFF(x, i) ((x) & ~MASK(i)) //  tắt bit thứ i trong x
#define ll long long
#define vt vector
#define C make_pair
template<typename T> bool maximize(T &res, const T &val) { if (res < val) { res = val; return true; } return false; }
template<typename T> bool minimize(T &res, const T &val) { if (res > val) { res = val; return true; } return false; }
using namespace std;
typedef pair<int,int>ii;
typedef pair<int,ii>iii;
const int mod = 1e9 + 7;
const int LOG = 18;
const int N = 1e6 + 9;
const int MAXN = 16;
const ll INF = 1e18 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

double arr[N];
int n;

void Up(int i){
    while(i > 1 && arr[i] > arr[i/2]){
            swap(arr[i],arr[i/2]);
            i /= 2;
    }
}

void Down(int i){
    int k = 1;

    while(k*2 <= n - i){
            int j = 2*k;
            if(j < n - i && arr[j] < arr[j+1]) j++;
            if(arr[k] >= arr[j]) break;
            swap(arr[k],arr[j]);
            k = j;
    }
}

double process_file(const string& input_file, vector<double>& all_numbers) {
    ifstream file(input_file);
    if (!file) {
        cerr << "Error: Cannot open file " << input_file << "\n";
        return 0.0;
    }
    
    auto start = chrono::high_resolution_clock::now();
    file >> n;
    FOR(i,1,n) {
        file >> arr[i];
        all_numbers.push_back(arr[i]);
    }
    file.close();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duration = end - start;

    FOR(i,1,n) Up(i);
    FOR(i,1,n) {
        swap(arr[1], arr[n - i + 1]);
        Down(i);
    }
    
    return duration.count();
}

int main() {
    string input_folder = "test";
    vector<double> all_numbers;
    
    for (const auto& entry : filesystem::directory_iterator(input_folder)) {
        if (entry.path().extension() == ".inp") {
            string input_path = entry.path().string();
            double time_taken = process_file(input_path, all_numbers);
            cout << "Processed " << input_path << " in " << fixed << setprecision(4) << time_taken << " ms." << endl;
        }
    }
    
    return 0;
}
